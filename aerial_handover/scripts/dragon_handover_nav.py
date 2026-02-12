#!/usr/bin/env python3

import rospy
import math
import tf
import tf.transformations
import geometry_msgs.msg
from sensor_msgs.msg import JointState
from geometry_msgs.msg import PoseStamped
from nav_msgs.msg import Odometry
from std_msgs.msg import Empty
from aerial_robot_msgs.msg import FlightNav
from visualization_msgs.msg import Marker


class DragonSimpleNav:
    def __init__(self):
        rospy.init_node('dragon_handover_nav', anonymous=False)
        rospy.loginfo("DragonSimpleNav node started successfully")

        # TF listener for coordinate transformations
        self.tf_listener = tf.TransformListener()

        # Subscribe to robot head pose (continuously updated)
        self.robot_head_pose_sub = rospy.Subscriber('/robot_head_pose', PoseStamped, self.robot_head_pose_cb)

        # Subscribe to hand pose (continuously updated)
        self.hand_pose_sub = rospy.Subscriber('/hand_pose', PoseStamped, self.hand_pose_cb)

        # Subscribe to trigger topic to start transformation and navigation
        self.trigger_sub = rospy.Subscriber('/dragon/trigger_handover', Empty, self.trigger_handover_cb)

        # Subscribe to CoG odometry for navigation feedback
        self.cog_odom_sub = rospy.Subscriber('/dragon/uav/cog/odom', Odometry, self.cog_odom_cb)

        # Subscribe to dragon joint states
        self.joint_states_sub = rospy.Subscriber('/dragon/joint_states', JointState, self.joint_states_cb)

        # Publisher for UAV navigation
        self.uav_nav_pub = rospy.Publisher("/dragon/uav/nav", FlightNav, queue_size=10)

        # Publisher for joint control
        self.joint_control_pub = rospy.Publisher("/dragon/joints_ctrl", JointState, queue_size=10)

        # Publisher for visualization markers
        self.marker_pub = rospy.Publisher("/dragon/intermediate_pose_marker", Marker, queue_size=10)

        # Publisher for hand pose at handover trigger
        self.hand_pose_handover_pub = rospy.Publisher("/hand_pose_handover", PoseStamped, queue_size=10)

        # Current joint states
        self.current_joint_positions = None

        # Current CoG pose
        self.current_cog_pose = None

        # Target CoG pose (calculated from target robot head pose)
        self.target_cog_x = None
        self.target_cog_y = None
        self.target_cog_z = None
        self.target_cog_yaw = None

        # Target robot head pose
        self.target_robot_head_pose = None

        # Current hand pose
        self.current_hand_pose = None

        # Human center position (point H)
        self.human_center_x = None
        self.human_center_y = None

        # Intermediate target for safe approach
        self.intermediate_cog_x = None
        self.intermediate_cog_y = None
        self.intermediate_cog_z = None
        self.intermediate_cog_yaw = None

        # Comfortable circle waypoint (point X) - used when robot is outside FOV
        self.comfortable_point_x = None
        self.comfortable_point_y = None
        self.comfortable_cog_x = None
        self.comfortable_cog_y = None
        self.comfortable_cog_z = None
        self.comfortable_cog_yaw = None

        # Flag to indicate if we need to go through comfortable point first
        self.use_comfortable_approach = False

        # Navigation stage: 'intermediate', 'arc_motion', 'comfortable_to_target', or 'final'
        self.navigation_stage = None

        # Arc motion waypoints (list of CoG poses)
        self.arc_waypoints = []
        self.current_waypoint_index = 0

        # Number of waypoints for arc motion
        self.num_arc_waypoints = rospy.get_param('~navigation/num_arc_waypoints', 10)

        # Joint names we care about (in the order we want)
        self.target_joint_names = rospy.get_param('~joint_names', [
            'joint1_pitch',
            'joint1_yaw',
            'joint2_pitch',
            'joint2_yaw',
            'joint3_pitch',
            'joint3_yaw'
        ])

        # Link length (approximate distance from CoG to link1/robot head in the desired configuration)
        # This is a simplified approximation - adjust based on actual robot geometry
        self.link_length = rospy.get_param('~geometry/link_length', 0.44)

        # Safe distance from human center (meters)
        self.safe_distance = rospy.get_param('~geometry/safe_distance', 1.0)

        # Comfortable distance from human center (meters) - for robots outside FOV
        self.comfortable_distance = rospy.get_param('~geometry/comfortable_distance', 2.0)

        # Human field of view (FOV) in degrees
        self.human_fov = rospy.get_param('~human_fov', 150.0)

        # Tolerance for checking if desired joint angle is achieved (radians)
        self.joint_angle_tolerance = rospy.get_param('~navigation/joint_angle_tolerance', 0.05)

        # Tolerance for navigation (meters)
        self.nav_position_tolerance = rospy.get_param('~navigation/nav_position_tolerance', 0.1)

        # Tolerance for yaw (radians)
        self.nav_yaw_tolerance = rospy.get_param('~navigation/nav_yaw_tolerance', 0.1)

        # Flag to track if we're currently transforming joints
        self.is_transforming_joints = False

        # Flag to track if we're currently navigating
        self.is_navigating = False

        rospy.loginfo("DragonSimpleNav initialized. Waiting for trigger messages...")

    def robot_head_pose_cb(self, msg):
        """Callback for robot head pose - only stores the latest pose"""
        # Store the target robot head pose (continuously updated)
        self.target_robot_head_pose = msg

    def hand_pose_cb(self, msg):
        """Callback for hand pose - only stores the latest pose"""
        # Store the current hand pose (continuously updated)
        self.current_hand_pose = msg

    def trigger_handover_cb(self, msg):
        """Callback for trigger topic - starts the transformation and navigation task"""
        if self.target_robot_head_pose is None:
            rospy.logwarn("Cannot start handover: no robot_head_pose received yet")
            return

        if self.is_transforming_joints or self.is_navigating:
            rospy.logwarn("Handover task already in progress, ignoring trigger")
            return

        # Publish current hand pose to handover topic
        if self.current_hand_pose is not None:
            self.hand_pose_handover_pub.publish(self.current_hand_pose)
            rospy.loginfo("Published hand pose to /hand_pose_handover topic")
        else:
            rospy.logwarn("No hand pose available to publish")

        rospy.loginfo("Trigger received! Starting joint transformation with latest robot_head_pose...")

        # Extract orientation from target pose
        target_roll, target_pitch, target_yaw = self._extract_target_orientation()

        # Calculate and publish desired joint positions
        self._calculate_and_publish_joints(target_pitch)

        # Calculate human center and determine approach strategy
        self._calculate_human_center_and_approach(target_yaw)

        # Publish all visualization markers
        self._publish_all_markers(target_yaw)

    def _extract_target_orientation(self):
        """Extract roll, pitch, yaw from target robot head pose"""
        target_quat = [
            self.target_robot_head_pose.pose.orientation.x,
            self.target_robot_head_pose.pose.orientation.y,
            self.target_robot_head_pose.pose.orientation.z,
            self.target_robot_head_pose.pose.orientation.w
        ]
        return tf.transformations.euler_from_quaternion(target_quat)

    def _calculate_and_publish_joints(self, target_pitch):
        """Calculate desired joint positions and publish joint command"""
        # Update joint1_pitch to match target pitch
        # Keep pitch angles for joint2 and joint3: 0, 0 degrees
        desired_joint_positions = [
            -target_pitch,
            -0.785,
            0.0,
            1.57,
            0.0,
            1.57
        ]

        # Store updated desired positions for later comparison
        self.desired_joint_positions = desired_joint_positions

        # Set the transformation flag
        self.is_transforming_joints = True

        # Create and publish desired joint state
        desired_joint = JointState()
        desired_joint.position = desired_joint_positions

        # Publish the joint command
        self.joint_control_pub.publish(desired_joint)

        rospy.loginfo(f"Published desired joint positions: pitch1={math.degrees(target_pitch):.1f} deg, yaw=[-45, 90, 90] deg, pitch=[0, 0, 0] deg")

    def _calculate_human_center_and_approach(self, target_yaw):
        """Calculate human center position and determine approach strategy"""
        # Calculate human center (point H)
        # Point H is along the opposite direction (180 degrees) from where the robot head is pointing
        direction_x = -math.cos(target_yaw)
        direction_y = -math.sin(target_yaw)
        self.human_center_x = self.target_robot_head_pose.pose.position.x + direction_x * self.safe_distance
        self.human_center_y = self.target_robot_head_pose.pose.position.y + direction_y * self.safe_distance

        rospy.loginfo(f"Human center (H) calculated at: x={self.human_center_x:.3f}, y={self.human_center_y:.3f}")

        # Check if current robot position is within human FOV
        if self.current_cog_pose is not None:
            robot_in_fov = self.is_within_fov(
                self.current_cog_pose.position.x,
                self.current_cog_pose.position.y,
                self.human_center_x,
                self.human_center_y,
                target_yaw,
                self.human_fov
            )

            if robot_in_fov:
                rospy.loginfo("Robot is within human FOV - using direct approach")
                self.use_comfortable_approach = False
            else:
                rospy.loginfo("Robot is outside human FOV - using comfortable circle approach")
                self.use_comfortable_approach = True

                # Calculate point X: intersection of human gaze centerline with comfortable circle
                self.comfortable_point_x = self.human_center_x + self.comfortable_distance * math.cos(target_yaw)
                self.comfortable_point_y = self.human_center_y + self.comfortable_distance * math.sin(target_yaw)
                rospy.loginfo(f"Comfortable point (X) at: x={self.comfortable_point_x:.3f}, y={self.comfortable_point_y:.3f}")
        else:
            rospy.logwarn("Current CoG pose not available, assuming robot is within FOV")
            self.use_comfortable_approach = False

    def _publish_all_markers(self, target_yaw):
        """Publish all visualization markers for RViz"""
        self.publish_human_center_marker(self.human_center_x, self.human_center_y, 
                                        self.target_robot_head_pose.pose.position.z)
        self.publish_safety_circle_marker(self.human_center_x, self.human_center_y,
                                          self.target_robot_head_pose.pose.position.z, self.safe_distance)
        if self.use_comfortable_approach:
            self.publish_safety_circle_marker(self.human_center_x, self.human_center_y,
                                              self.target_robot_head_pose.pose.position.z, self.comfortable_distance)
        self.publish_fov_marker(self.human_center_x, self.human_center_y,
                                self.target_robot_head_pose.pose.position.z, target_yaw)
        self.publish_final_head_pose_marker(
            self.target_robot_head_pose.pose.position.x,
            self.target_robot_head_pose.pose.position.y,
            self.target_robot_head_pose.pose.position.z,
            target_yaw
        )

    def cog_odom_cb(self, msg):
        """Callback for CoG odometry"""
        self.current_cog_pose = msg.pose.pose

        # Check if navigation is complete
        if self.is_navigating and self.target_robot_head_pose is not None:
            if self.check_navigation_achieved():
                rospy.loginfo("Navigation complete! Robot reached final handover pose safely.")
                self.is_navigating = False
                self.navigation_stage = None

    def joint_states_cb(self, msg):
        """Callback for dragon joint states"""
        if msg.name and msg.position and len(msg.position) >= 6:
            # Extract only the joint positions we care about
            self.current_joint_positions = []
            for joint_name in self.target_joint_names:
                if joint_name in msg.name:
                    idx = msg.name.index(joint_name)
                    self.current_joint_positions.append(msg.position[idx])
                else:
                    rospy.logwarn_once(f"Joint {joint_name} not found in joint_states message")
                    return

            # Check if joint transformation is complete
            if self.is_transforming_joints:
                if self.check_joint_pose_achieved():
                    rospy.loginfo("Desired joint pose achieved! Joint transformation complete.")
                    self.is_transforming_joints = False

                    # Start navigation after joint transformation
                    self.start_navigation()

    def get_root_to_cog_transform(self):
        """Get the transformation matrix from root frame to CoG frame"""
        try:
            self.tf_listener.waitForTransform("dragon/root", "dragon/cog", rospy.Time(0), rospy.Duration(4.0))
            (trans_root_to_cog, rot_root_to_cog) = self.tf_listener.lookupTransform("dragon/root", "dragon/cog", rospy.Time(0))

            root_to_cog_matrix = tf.transformations.concatenate_matrices(
                tf.transformations.translation_matrix(trans_root_to_cog),
                tf.transformations.quaternion_matrix(rot_root_to_cog)
            )
            return root_to_cog_matrix
        except (tf.LookupException, tf.ConnectivityException, tf.ExtrapolationException) as e:
            rospy.logerr(f"TF transformation failed: {e}")
            return None

    def calculate_target_cog_pose(self, root_to_cog_matrix):
        """Calculate the target CoG pose from target robot head pose"""
        target_root_quat = [
            self.target_robot_head_pose.pose.orientation.x,
            self.target_robot_head_pose.pose.orientation.y,
            self.target_robot_head_pose.pose.orientation.z,
            self.target_robot_head_pose.pose.orientation.w
        ]
        target_root_matrix = tf.transformations.concatenate_matrices(
            tf.transformations.translation_matrix([
                self.target_robot_head_pose.pose.position.x,
                self.target_robot_head_pose.pose.position.y,
                self.target_robot_head_pose.pose.position.z
            ]),
            tf.transformations.quaternion_matrix(target_root_quat)
        )

        # Compute target cog transform: world_to_root * root_to_cog
        target_cog_matrix = tf.transformations.concatenate_matrices(target_root_matrix, root_to_cog_matrix)

        # Extract position and orientation
        target_cog_pos = tf.transformations.translation_from_matrix(target_cog_matrix)
        target_cog_quat = tf.transformations.quaternion_from_matrix(target_cog_matrix)
        _, _, target_cog_yaw = tf.transformations.euler_from_quaternion(target_cog_quat)

        # Store final target CoG pose
        self.target_cog_x = target_cog_pos[0]
        self.target_cog_y = target_cog_pos[1]
        self.target_cog_z = target_cog_pos[2]
        self.target_cog_yaw = target_cog_yaw

    def is_within_fov(self, point_x, point_y, center_x, center_y, center_yaw, fov_degrees):
        """Check if a point is within the field of view cone"""
        # Calculate angle from center to point
        dx = point_x - center_x
        dy = point_y - center_y
        angle_to_point = math.atan2(dy, dx)

        # Calculate angular difference from center yaw
        angle_diff = angle_to_point - center_yaw

        # Normalize to [-pi, pi]
        while angle_diff > math.pi:
            angle_diff -= 2 * math.pi
        while angle_diff < -math.pi:
            angle_diff += 2 * math.pi

        # Check if within FOV range
        fov_rad = math.radians(fov_degrees)
        return abs(angle_diff) <= fov_rad / 2.0

    def calculate_human_center(self):
        """Calculate human center position (point H) based on target robot head pose"""
        target_quat = [
            self.target_robot_head_pose.pose.orientation.x,
            self.target_robot_head_pose.pose.orientation.y,
            self.target_robot_head_pose.pose.orientation.z,
            self.target_robot_head_pose.pose.orientation.w
        ]
        _, _, target_yaw_head = tf.transformations.euler_from_quaternion(target_quat)

        # Direction vector from robot head pose (reversed 180 degrees)
        direction_x = -math.cos(target_yaw_head)
        direction_y = -math.sin(target_yaw_head)

        # Human center H is at safe_distance along this reversed direction
        self.human_center_x = self.target_robot_head_pose.pose.position.x + direction_x * self.safe_distance
        self.human_center_y = self.target_robot_head_pose.pose.position.y + direction_y * self.safe_distance

    def calculate_intermediate_point_on_circle(self, radius, root_to_cog_matrix, target_head_x, target_head_y):
        """Calculate intermediate point on a circle with given radius

        Args:
            radius: The radius of the circle
            root_to_cog_matrix: Transformation matrix from root to CoG
            target_head_x: Target head x position (for determining z height)
            target_head_y: Target head y position (for determining z height)

        Returns:
            Tuple: (intermediate_x, intermediate_y, intermediate_cog_x, intermediate_cog_y, 
                   intermediate_cog_z, intermediate_cog_yaw, intermediate_yaw) or None if failed
        """
        if self.current_cog_pose is None:
            rospy.logwarn("Current CoG pose not available, cannot calculate intermediate point")
            return None

        current_cog_x = self.current_cog_pose.position.x
        current_cog_y = self.current_cog_pose.position.y

        # Vector from current CoG to human center
        dx = self.human_center_x - current_cog_x
        dy = self.human_center_y - current_cog_y
        distance_to_human = math.sqrt(dx*dx + dy*dy)

        if distance_to_human < radius:
            rospy.logwarn(f"Robot is too close to human center ({distance_to_human:.3f}m < {radius:.3f}m)")

        # Normalize direction vector
        if distance_to_human > 1e-6:
            dx_norm = dx / distance_to_human
            dy_norm = dy / distance_to_human
        else:
            rospy.logerr("Current CoG is at human center, cannot calculate safe approach")
            return None

        # Point M is at radius from H along the line from CoG to H
        intermediate_x = self.human_center_x - dx_norm * radius
        intermediate_y = self.human_center_y - dy_norm * radius
        intermediate_yaw = math.atan2(-dy_norm, -dx_norm)

        # Calculate intermediate CoG pose
        intermediate_root_matrix = tf.transformations.concatenate_matrices(
            tf.transformations.translation_matrix([intermediate_x, intermediate_y, self.target_robot_head_pose.pose.position.z]),
            tf.transformations.quaternion_matrix(
                tf.transformations.quaternion_from_euler(0, 0, intermediate_yaw)
            )
        )

        intermediate_cog_matrix = tf.transformations.concatenate_matrices(intermediate_root_matrix, root_to_cog_matrix)
        intermediate_cog_pos = tf.transformations.translation_from_matrix(intermediate_cog_matrix)
        intermediate_cog_quat = tf.transformations.quaternion_from_matrix(intermediate_cog_matrix)
        _, _, intermediate_cog_yaw = tf.transformations.euler_from_quaternion(intermediate_cog_quat)

        return (intermediate_x, intermediate_y,
                intermediate_cog_pos[0], intermediate_cog_pos[1], intermediate_cog_pos[2],
                intermediate_cog_yaw, intermediate_yaw)

    def calculate_intermediate_point(self, root_to_cog_matrix):
        """Calculate intermediate point M on the safety circle"""
        result = self.calculate_intermediate_point_on_circle(
            self.safe_distance,
            root_to_cog_matrix,
            self.target_robot_head_pose.pose.position.x,
            self.target_robot_head_pose.pose.position.y
        )

        if result is None:
            return False

        intermediate_x, intermediate_y, cog_x, cog_y, cog_z, cog_yaw, head_yaw = result

        self.intermediate_cog_x = cog_x
        self.intermediate_cog_y = cog_y
        self.intermediate_cog_z = cog_z
        self.intermediate_cog_yaw = cog_yaw

        rospy.loginfo(
            f"Intermediate point (M) head pose: x={intermediate_x:.3f}, y={intermediate_y:.3f}, yaw={math.degrees(head_yaw):.1f} deg")
        rospy.loginfo(
            f"Intermediate CoG pose: x={self.intermediate_cog_x:.3f}, y={self.intermediate_cog_y:.3f}, z={self.intermediate_cog_z:.3f}, yaw={math.degrees(self.intermediate_cog_yaw):.1f} deg")

        # Publish marker for visualization
        self.publish_intermediate_pose_marker(intermediate_x, intermediate_y, self.target_robot_head_pose.pose.position.z, head_yaw)

        return True

    def publish_navigation_command_intermediate(self):
        """Publish navigation command for intermediate position"""
        nav_msg = FlightNav()
        nav_msg.control_frame = FlightNav.WORLD_FRAME
        nav_msg.target = FlightNav.COG
        nav_msg.pos_xy_nav_mode = FlightNav.POS_MODE
        nav_msg.pos_z_nav_mode = FlightNav.POS_MODE
        nav_msg.yaw_nav_mode = FlightNav.POS_MODE

        nav_msg.target_pos_x = self.intermediate_cog_x
        nav_msg.target_pos_y = self.intermediate_cog_y
        nav_msg.target_pos_z = self.intermediate_cog_z
        nav_msg.target_yaw = self.intermediate_cog_yaw

        self.uav_nav_pub.publish(nav_msg)
        rospy.loginfo("Stage 1: Navigating to intermediate safe position...")

    def start_navigation(self):
        """Main navigation function - orchestrates the safe approach strategy"""
        if self.target_robot_head_pose is None:
            rospy.logwarn("Cannot start navigation: no target robot head pose available")
            return

        rospy.loginfo("Starting whole body navigation with safe approach strategy...")
        self.is_navigating = True

        # Get transformation from root to CoG
        root_to_cog_matrix = self.get_root_to_cog_transform()
        if root_to_cog_matrix is None:
            self.is_navigating = False
            return

        # Calculate target CoG pose
        self.calculate_target_cog_pose(root_to_cog_matrix)

        # Calculate human center position
        self.calculate_human_center()

        # Setup approach strategy based on FOV
        if self.use_comfortable_approach:
            if not self._setup_comfortable_approach(root_to_cog_matrix):
                self.is_navigating = False
                return
        else:
            if not self._setup_direct_approach(root_to_cog_matrix):
                self.is_navigating = False
                return

        # Initialize navigation
        self.current_waypoint_index = 0
        self.navigation_stage = 'intermediate'
        self.publish_navigation_command_intermediate()

    def _setup_comfortable_approach(self, root_to_cog_matrix):
        """Setup navigation for comfortable circle approach (robot outside FOV)"""
        rospy.loginfo("Using comfortable circle approach (robot outside FOV)")

        # Calculate intermediate point on comfortable circle
        result = self.calculate_intermediate_point_on_circle(
            self.comfortable_distance,
            root_to_cog_matrix,
            self.comfortable_point_x,
            self.comfortable_point_y
        )

        if result is None:
            return False

        intermediate_x, intermediate_y, cog_x, cog_y, cog_z, cog_yaw, head_yaw = result
        self.intermediate_cog_x = cog_x
        self.intermediate_cog_y = cog_y
        self.intermediate_cog_z = cog_z
        self.intermediate_cog_yaw = cog_yaw

        rospy.loginfo(f"Comfortable intermediate point: x={intermediate_x:.3f}, y={intermediate_y:.3f}")
        self.publish_intermediate_pose_marker(intermediate_x, intermediate_y,
                                              self.target_robot_head_pose.pose.position.z, head_yaw)

        # Calculate comfortable point X CoG pose
        self._calculate_comfortable_point_cog(root_to_cog_matrix)

        # Generate arc motion waypoints to comfortable point X
        self.arc_waypoints = self.generate_arc_waypoints_between_points(
            intermediate_x, intermediate_y,
            self.comfortable_point_x, self.comfortable_point_y,
            self.comfortable_distance,
            root_to_cog_matrix
        )
        return True

    def _setup_direct_approach(self, root_to_cog_matrix):
        """Setup navigation for direct approach (robot within FOV)"""
        rospy.loginfo("Using direct approach (robot within FOV)")

        # Calculate intermediate point on safety circle
        if not self.calculate_intermediate_point(root_to_cog_matrix):
            return False

        # Generate arc motion waypoints to final target
        self.arc_waypoints = self.generate_arc_waypoints_between_points(
            None, None,  # Will use intermediate point calculated above
            self.target_robot_head_pose.pose.position.x,
            self.target_robot_head_pose.pose.position.y,
            self.safe_distance,
            root_to_cog_matrix
        )
        return True

    def _calculate_comfortable_point_cog(self, root_to_cog_matrix):
        """Calculate CoG pose for comfortable point X"""
        comfortable_yaw = math.atan2(
            self.comfortable_point_y - self.human_center_y,
            self.comfortable_point_x - self.human_center_x
        )
        comfortable_root_matrix = tf.transformations.concatenate_matrices(
            tf.transformations.translation_matrix([self.comfortable_point_x, self.comfortable_point_y,
                                                  self.target_robot_head_pose.pose.position.z]),
            tf.transformations.quaternion_matrix(
                tf.transformations.quaternion_from_euler(0, 0, comfortable_yaw)
            )
        )
        comfortable_cog_matrix = tf.transformations.concatenate_matrices(comfortable_root_matrix, root_to_cog_matrix)
        comfortable_cog_pos = tf.transformations.translation_from_matrix(comfortable_cog_matrix)
        comfortable_cog_quat = tf.transformations.quaternion_from_matrix(comfortable_cog_matrix)
        _, _, comfortable_cog_yaw = tf.transformations.euler_from_quaternion(comfortable_cog_quat)

        self.comfortable_cog_x = comfortable_cog_pos[0]
        self.comfortable_cog_y = comfortable_cog_pos[1]
        self.comfortable_cog_z = comfortable_cog_pos[2]
        self.comfortable_cog_yaw = comfortable_cog_yaw

    def generate_arc_waypoints_between_points(self, start_head_x, start_head_y,
                                              end_head_x, end_head_y, radius, root_to_cog_matrix):
        """Generate waypoints for arc motion between two points on a circle

        Args:
            start_head_x: Starting head x position (None to use intermediate point)
            start_head_y: Starting head y position (None to use intermediate point)
            end_head_x: Ending head x position
            end_head_y: Ending head y position
            radius: Radius of the circle
            root_to_cog_matrix: Transformation matrix from root to CoG

        Returns:
            List of waypoint dictionaries
        """
        # Use intermediate point if start is not specified
        if start_head_x is None or start_head_y is None:
            # Calculate from intermediate CoG back to head position
            # This is a simplification - we use the angle from human center
            intermediate_angle = math.atan2(
                self.intermediate_cog_y - self.human_center_y,
                self.intermediate_cog_x - self.human_center_x
            )
        else:
            intermediate_angle = math.atan2(
                start_head_y - self.human_center_y,
                start_head_x - self.human_center_x
            )

        final_angle = math.atan2(
            end_head_y - self.human_center_y,
            end_head_x - self.human_center_x
        )

        # Calculate angular difference and normalize to [-pi, pi]
        angle_diff = final_angle - intermediate_angle
        while angle_diff > math.pi:
            angle_diff -= 2 * math.pi
        while angle_diff < -math.pi:
            angle_diff += 2 * math.pi

        rospy.loginfo(
            f"Arc motion: from {math.degrees(intermediate_angle):.1f} deg to {math.degrees(final_angle):.1f} deg (sweep: {math.degrees(angle_diff):.1f} deg)")

        # Generate waypoints along the arc
        waypoints = []
        for i in range(1, self.num_arc_waypoints + 1):
            # Interpolate angle
            t = float(i) / self.num_arc_waypoints
            current_angle = intermediate_angle + angle_diff * t

            # Calculate head position on the circle
            head_x = self.human_center_x + radius * math.cos(current_angle)
            head_y = self.human_center_y + radius * math.sin(current_angle)
            head_z = self.target_robot_head_pose.pose.position.z

            # Head orientation: pointing from H to head position
            head_yaw = current_angle

            # Create transformation matrix for this waypoint head pose
            waypoint_head_matrix = tf.transformations.concatenate_matrices(
                tf.transformations.translation_matrix([head_x, head_y, head_z]),
                tf.transformations.quaternion_matrix(
                    tf.transformations.quaternion_from_euler(0, 0, head_yaw)
                )
            )

            # Calculate CoG pose for this waypoint
            waypoint_cog_matrix = tf.transformations.concatenate_matrices(
                waypoint_head_matrix, root_to_cog_matrix
            )

            # Extract CoG position and orientation
            waypoint_cog_pos = tf.transformations.translation_from_matrix(waypoint_cog_matrix)
            waypoint_cog_quat = tf.transformations.quaternion_from_matrix(waypoint_cog_matrix)
            _, _, waypoint_cog_yaw = tf.transformations.euler_from_quaternion(waypoint_cog_quat)

            # Store waypoint as dict
            waypoint = {
                'cog_x': waypoint_cog_pos[0],
                'cog_y': waypoint_cog_pos[1],
                'cog_z': waypoint_cog_pos[2],
                'cog_yaw': waypoint_cog_yaw,
                'head_x': head_x,
                'head_y': head_y,
                'head_yaw': head_yaw
            }
            waypoints.append(waypoint)

        rospy.loginfo(f"Generated {len(waypoints)} waypoints for arc motion")
        return waypoints

    def generate_arc_waypoints(self, root_to_cog_matrix):
        """Generate waypoints for arc motion from intermediate to final pose (legacy wrapper)"""
        self.arc_waypoints = self.generate_arc_waypoints_between_points(
            None, None,
            self.target_robot_head_pose.pose.position.x,
            self.target_robot_head_pose.pose.position.y,
            self.safe_distance,
            root_to_cog_matrix
        )

    def publish_intermediate_pose_marker(self, x, y, z, yaw):
        """Publish a marker to visualize the intermediate head pose in RViz"""
        marker = Marker()
        marker.header.frame_id = "world"
        marker.header.stamp = rospy.Time.now()
        marker.ns = "intermediate_pose"
        marker.id = 0
        marker.type = Marker.ARROW
        marker.action = Marker.ADD

        # Position
        marker.pose.position.x = x
        marker.pose.position.y = y
        marker.pose.position.z = z

        # Orientation
        quat = tf.transformations.quaternion_from_euler(0, 0, yaw)
        marker.pose.orientation.x = quat[0]
        marker.pose.orientation.y = quat[1]
        marker.pose.orientation.z = quat[2]
        marker.pose.orientation.w = quat[3]

        # Scale (arrow dimensions)
        marker.scale.x = 0.3  # Arrow length
        marker.scale.y = 0.05  # Arrow width
        marker.scale.z = 0.05  # Arrow height

        # Color (green for intermediate pose)
        marker.color.r = 0.0
        marker.color.g = 1.0
        marker.color.b = 0.0
        marker.color.a = 1.0

        marker.lifetime = rospy.Duration(0)  # Permanent until replaced

        self.marker_pub.publish(marker)
        rospy.loginfo("Published intermediate pose marker to RViz")

    def publish_safety_circle_marker(self, center_x, center_y, z, radius):
        """Publish a marker to visualize the safety circle in RViz"""
        marker = Marker()
        marker.header.frame_id = "world"
        marker.header.stamp = rospy.Time.now()
        marker.ns = "safety_circle"
        marker.id = 1
        marker.type = Marker.LINE_STRIP
        marker.action = Marker.ADD

        # Position (set to origin for LINE_STRIP, points define actual positions)
        marker.pose.position.x = 0
        marker.pose.position.y = 0
        marker.pose.position.z = 0
        marker.pose.orientation.w = 1.0

        # Line width
        marker.scale.x = 0.02

        # Color (red for safety circle)
        marker.color.r = 1.0
        marker.color.g = 0.0
        marker.color.b = 0.0
        marker.color.a = 0.8

        # Generate circle points
        num_points = 50
        for i in range(num_points + 1):  # +1 to close the circle
            angle = 2 * math.pi * i / num_points
            point = geometry_msgs.msg.Point()
            point.x = center_x + radius * math.cos(angle)
            point.y = center_y + radius * math.sin(angle)
            point.z = z
            marker.points.append(point)

        marker.lifetime = rospy.Duration(0)  # Permanent until replaced

        self.marker_pub.publish(marker)
        rospy.loginfo(f"Published safety circle marker at ({center_x:.3f}, {center_y:.3f}) with radius {radius:.3f}m")

    def publish_human_center_marker(self, center_x, center_y, z):
        """Publish a marker to visualize the human center (point H) in RViz"""
        marker = Marker()
        marker.header.frame_id = "world"
        marker.header.stamp = rospy.Time.now()
        marker.ns = "human_center"
        marker.id = 2
        marker.type = Marker.SPHERE
        marker.action = Marker.ADD

        # Position
        marker.pose.position.x = center_x
        marker.pose.position.y = center_y
        marker.pose.position.z = z
        marker.pose.orientation.w = 1.0

        # Scale (sphere diameter)
        marker.scale.x = 0.15
        marker.scale.y = 0.15
        marker.scale.z = 0.15

        # Color (blue for human center)
        marker.color.r = 0.0
        marker.color.g = 0.0
        marker.color.b = 1.0
        marker.color.a = 1.0

        marker.lifetime = rospy.Duration(0)  # Permanent until replaced

        self.marker_pub.publish(marker)
        rospy.loginfo(f"Published human center marker at ({center_x:.3f}, {center_y:.3f})")

    def publish_fov_marker(self, center_x, center_y, z, yaw):
        """Publish a marker to visualize the human field of view as a sector in RViz"""
        marker = Marker()
        marker.header.frame_id = "world"
        marker.header.stamp = rospy.Time.now()
        marker.ns = "human_fov"
        marker.id = 4
        marker.type = Marker.LINE_LIST
        marker.action = Marker.ADD

        # Position (set to origin for LINE_LIST, points define actual positions)
        marker.pose.position.x = 0
        marker.pose.position.y = 0
        marker.pose.position.z = 0
        marker.pose.orientation.w = 1.0

        # Line width
        marker.scale.x = 0.03

        # Color (cyan for FOV sector boundaries)
        marker.color.r = 0.0
        marker.color.g = 1.0
        marker.color.b = 1.0
        marker.color.a = 0.8

        # Convert FOV from degrees to radians
        fov_rad = math.radians(self.human_fov)

        # FOV sector radius equals safe_distance
        fov_radius = self.safe_distance

        # Calculate start and end angles for the FOV sector
        # Human body orientation is yaw, FOV is centered on this direction
        start_angle = yaw - fov_rad / 2.0
        end_angle = yaw + fov_rad / 2.0

        # Create center point
        center_point = geometry_msgs.msg.Point()
        center_point.x = center_x
        center_point.y = center_y
        center_point.z = z

        # Generate arc lines
        num_arc_segments = 30
        for i in range(num_arc_segments):
            angle1 = start_angle + (end_angle - start_angle) * i / num_arc_segments
            angle2 = start_angle + (end_angle - start_angle) * (i + 1) / num_arc_segments

            point1 = geometry_msgs.msg.Point()
            point1.x = center_x + fov_radius * math.cos(angle1)
            point1.y = center_y + fov_radius * math.sin(angle1)
            point1.z = z

            point2 = geometry_msgs.msg.Point()
            point2.x = center_x + fov_radius * math.cos(angle2)
            point2.y = center_y + fov_radius * math.sin(angle2)
            point2.z = z

            # Add arc segment
            marker.points.append(point1)
            marker.points.append(point2)

        # Add boundary rays from center to start and end of arc
        start_point = geometry_msgs.msg.Point()
        start_point.x = center_x + fov_radius * math.cos(start_angle)
        start_point.y = center_y + fov_radius * math.sin(start_angle)
        start_point.z = z

        end_point = geometry_msgs.msg.Point()
        end_point.x = center_x + fov_radius * math.cos(end_angle)
        end_point.y = center_y + fov_radius * math.sin(end_angle)
        end_point.z = z

        # Left boundary ray
        marker.points.append(center_point)
        marker.points.append(start_point)

        # Right boundary ray
        marker.points.append(center_point)
        marker.points.append(end_point)

        marker.lifetime = rospy.Duration(0)  # Permanent until replaced

        self.marker_pub.publish(marker)
        rospy.loginfo(f"Published human FOV marker: {self.human_fov:.1f} degrees, orientation: {math.degrees(yaw):.1f} deg")

    def publish_final_head_pose_marker(self, x, y, z, yaw):
        """Publish a marker to visualize the final robot head pose in RViz"""
        marker = Marker()
        marker.header.frame_id = "world"
        marker.header.stamp = rospy.Time.now()
        marker.ns = "final_head_pose"
        marker.id = 3
        marker.type = Marker.ARROW
        marker.action = Marker.ADD

        # Position
        marker.pose.position.x = x
        marker.pose.position.y = y
        marker.pose.position.z = z

        # Orientation
        quat = tf.transformations.quaternion_from_euler(0, 0, yaw)
        marker.pose.orientation.x = quat[0]
        marker.pose.orientation.y = quat[1]
        marker.pose.orientation.z = quat[2]
        marker.pose.orientation.w = quat[3]

        # Scale (arrow dimensions)
        marker.scale.x = 0.3  # Arrow length
        marker.scale.y = 0.05  # Arrow width
        marker.scale.z = 0.05  # Arrow height

        # Color (yellow for final target pose)
        marker.color.r = 1.0
        marker.color.g = 1.0
        marker.color.b = 0.0
        marker.color.a = 1.0

        marker.lifetime = rospy.Duration(0)  # Permanent until replaced

        self.marker_pub.publish(marker)
        rospy.loginfo("Published final head pose marker to RViz")

    def check_joint_pose_achieved(self):
        """Check if the current joint positions match the desired positions"""
        if self.current_joint_positions is None:
            return False

        for i in range(len(self.desired_joint_positions)):
            error = abs(self.current_joint_positions[i] - self.desired_joint_positions[i])
            if error > self.joint_angle_tolerance:
                return False

        return True

    def check_navigation_achieved(self):
        """Check if CoG has reached the target position and orientation"""
        if self.current_cog_pose is None:
            return False

        # Get current CoG pose and yaw
        current_cog_x = self.current_cog_pose.position.x
        current_cog_y = self.current_cog_pose.position.y
        current_cog_z = self.current_cog_pose.position.z
        current_yaw = self._get_current_yaw()

        # Check based on current navigation stage
        if self.navigation_stage == 'intermediate':
            return self._check_intermediate_stage(current_cog_x, current_cog_y, current_cog_z, current_yaw)
        elif self.navigation_stage == 'arc_motion':
            return self._check_arc_motion_stage(current_cog_x, current_cog_y, current_cog_z, current_yaw)
        elif self.navigation_stage == 'comfortable_to_target':
            return self._check_comfortable_to_target_stage(current_cog_x, current_cog_y, current_cog_z, current_yaw)
        elif self.navigation_stage == 'final':
            return self._check_final_stage(current_cog_x, current_cog_y, current_cog_z, current_yaw)

        return False

    def _get_current_yaw(self):
        """Extract current yaw from CoG pose"""
        current_quat = [
            self.current_cog_pose.orientation.x,
            self.current_cog_pose.orientation.y,
            self.current_cog_pose.orientation.z,
            self.current_cog_pose.orientation.w
        ]
        _, _, current_yaw = tf.transformations.euler_from_quaternion(current_quat)
        return current_yaw

    def _check_pose_reached(self, current_x, current_y, current_z, current_yaw, 
                           target_x, target_y, target_z, target_yaw):
        """Check if current pose matches target pose within tolerances"""
        dx = current_x - target_x
        dy = current_y - target_y
        dz = current_z - target_z
        distance = math.sqrt(dx*dx + dy*dy + dz*dz)

        yaw_error = self._normalize_angle(target_yaw - current_yaw)

        return distance < self.nav_position_tolerance and abs(yaw_error) < self.nav_yaw_tolerance

    def _normalize_angle(self, angle):
        """Normalize angle to [-pi, pi]"""
        while angle > math.pi:
            angle -= 2 * math.pi
        while angle < -math.pi:
            angle += 2 * math.pi
        return angle

    def _check_intermediate_stage(self, current_x, current_y, current_z, current_yaw):
        """Check if intermediate position is reached"""
        if self.intermediate_cog_x is None:
            return False

        if self._check_pose_reached(current_x, current_y, current_z, current_yaw,
                                    self.intermediate_cog_x, self.intermediate_cog_y, 
                                    self.intermediate_cog_z, self.intermediate_cog_yaw):
            rospy.loginfo("Intermediate position reached! Starting arc motion...")
            self._transition_to_arc_motion()
            return False
        return False

    def _transition_to_arc_motion(self):
        """Transition to arc motion stage"""
        self.navigation_stage = 'arc_motion'
        self.current_waypoint_index = 0

        if len(self.arc_waypoints) > 0:
            self._publish_waypoint_nav(self.arc_waypoints[self.current_waypoint_index])
            rospy.loginfo(f"Stage 2: Arc motion - navigating to waypoint {self.current_waypoint_index + 1}/{len(self.arc_waypoints)}")

    def _check_arc_motion_stage(self, current_x, current_y, current_z, current_yaw):
        """Check arc motion waypoint progress"""
        if len(self.arc_waypoints) == 0:
            return False

        waypoint = self.arc_waypoints[self.current_waypoint_index]

        if self._check_pose_reached(current_x, current_y, current_z, current_yaw,
                                    waypoint['cog_x'], waypoint['cog_y'], 
                                    waypoint['cog_z'], waypoint['cog_yaw']):
            self.current_waypoint_index += 1

            if self.current_waypoint_index < len(self.arc_waypoints):
                # Move to next waypoint
                self._publish_waypoint_nav(self.arc_waypoints[self.current_waypoint_index])
                rospy.loginfo(f"Arc motion - navigating to waypoint {self.current_waypoint_index + 1}/{len(self.arc_waypoints)}")
                return False
            else:
                # All arc waypoints completed
                return self._handle_arc_completion()
        return False

    def _handle_arc_completion(self):
        """Handle completion of arc motion waypoints"""
        if self.use_comfortable_approach:
            return self._transition_comfortable_to_target()
        else:
            return self._transition_to_final()

    def _transition_comfortable_to_target(self):
        """Transition from comfortable point to target"""
        rospy.loginfo("Reached comfortable point X! Now navigating to final target...")
        self.navigation_stage = 'comfortable_to_target'

        root_to_cog_matrix = self.get_root_to_cog_transform()
        if root_to_cog_matrix is None:
            rospy.logerr("Failed to get transform for comfortable to target navigation")
            return False

        result = self.calculate_intermediate_point_on_circle(
            self.safe_distance,
            root_to_cog_matrix,
            self.target_robot_head_pose.pose.position.x,
            self.target_robot_head_pose.pose.position.y
        )

        if result is None:
            rospy.logerr("Failed to calculate intermediate point for comfortable to target")
            return False

        intermediate_x, intermediate_y, _, _, _, _, _ = result

        # Generate arc waypoints from X to intermediate point on safety circle
        self.arc_waypoints = self.generate_arc_waypoints_between_points(
            self.comfortable_point_x, self.comfortable_point_y,
            intermediate_x, intermediate_y,
            self.safe_distance,
            root_to_cog_matrix
        )
        self.current_waypoint_index = 0

        if len(self.arc_waypoints) > 0:
            self._publish_waypoint_nav(self.arc_waypoints[self.current_waypoint_index])
            rospy.loginfo(f"Stage 2.5: Arc from comfortable to target - waypoint {self.current_waypoint_index + 1}/{len(self.arc_waypoints)}")
        return False

    def _transition_to_final(self):
        """Transition to final handover position"""
        rospy.loginfo("Arc motion complete! Moving to final handover position...")
        self.navigation_stage = 'final'
        self._publish_final_nav()
        rospy.loginfo("Stage 3: Navigating to final handover position...")
        return False

    def _check_comfortable_to_target_stage(self, current_x, current_y, current_z, current_yaw):
        """Check comfortable to target arc waypoint progress"""
        if len(self.arc_waypoints) == 0:
            return False

        waypoint = self.arc_waypoints[self.current_waypoint_index]

        if self._check_pose_reached(current_x, current_y, current_z, current_yaw,
                                    waypoint['cog_x'], waypoint['cog_y'], 
                                    waypoint['cog_z'], waypoint['cog_yaw']):
            self.current_waypoint_index += 1

            if self.current_waypoint_index < len(self.arc_waypoints):
                self._publish_waypoint_nav(self.arc_waypoints[self.current_waypoint_index])
                rospy.loginfo(f"Comfortable to target arc - waypoint {self.current_waypoint_index + 1}/{len(self.arc_waypoints)}")
                return False
            else:
                # Reached safety circle, move to final target
                rospy.loginfo("Reached safety circle! Moving to final handover position...")
                self.navigation_stage = 'final'
                self._publish_final_nav()
                rospy.loginfo("Stage 3: Navigating to final handover position...")
                return False
        return False

    def _check_final_stage(self, current_x, current_y, current_z, current_yaw):
        """Check if final handover position is reached"""
        if self.target_cog_x is None:
            return False

        return self._check_pose_reached(current_x, current_y, current_z, current_yaw,
                                       self.target_cog_x, self.target_cog_y, 
                                       self.target_cog_z, self.target_cog_yaw)

    def _publish_waypoint_nav(self, waypoint):
        """Publish navigation command for a waypoint"""
        nav_msg = FlightNav()
        nav_msg.control_frame = FlightNav.WORLD_FRAME
        nav_msg.target = FlightNav.COG
        nav_msg.pos_xy_nav_mode = FlightNav.POS_MODE
        nav_msg.pos_z_nav_mode = FlightNav.POS_MODE
        nav_msg.yaw_nav_mode = FlightNav.POS_MODE
        nav_msg.target_pos_x = waypoint['cog_x']
        nav_msg.target_pos_y = waypoint['cog_y']
        nav_msg.target_pos_z = waypoint['cog_z']
        nav_msg.target_yaw = waypoint['cog_yaw']
        self.uav_nav_pub.publish(nav_msg)

    def _publish_final_nav(self):
        """Publish navigation command for final pose"""
        nav_msg = FlightNav()
        nav_msg.control_frame = FlightNav.WORLD_FRAME
        nav_msg.target = FlightNav.COG
        nav_msg.pos_xy_nav_mode = FlightNav.POS_MODE
        nav_msg.pos_z_nav_mode = FlightNav.POS_MODE
        nav_msg.yaw_nav_mode = FlightNav.POS_MODE
        nav_msg.target_pos_x = self.target_cog_x
        nav_msg.target_pos_y = self.target_cog_y
        nav_msg.target_pos_z = self.target_cog_z
        nav_msg.target_yaw = self.target_cog_yaw
        self.uav_nav_pub.publish(nav_msg)

    def run(self):
        """Main loop"""
        rospy.spin()


if __name__ == '__main__':
    try:
        nav = DragonSimpleNav()
        nav.run()
    except rospy.ROSInterruptException:
        pass
