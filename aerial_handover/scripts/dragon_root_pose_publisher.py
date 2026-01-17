#!/usr/bin/env python3

import rospy
import tf
import tf.transformations
from geometry_msgs.msg import PoseStamped
from nav_msgs.msg import Odometry


class DragonRootPosePublisher:
    def __init__(self):
        rospy.init_node('dragon_root_pose_publisher', anonymous=False)
        rospy.loginfo("DragonRootPosePublisher node started")

        # TF listener for coordinate transformations
        self.tf_listener = tf.TransformListener()

        # Subscribe to CoG odometry
        self.cog_odom_sub = rospy.Subscriber('/dragon/uav/cog/odom', Odometry, self.cog_odom_cb)

        # Publisher for dragon root pose
        self.root_pose_pub = rospy.Publisher("/dragon/root_pose", PoseStamped, queue_size=10)

        rospy.loginfo("DragonRootPosePublisher initialized. Publishing root pose...")

    def cog_odom_cb(self, msg):
        """Callback for CoG odometry - calculates and publishes root pose"""
        self._calculate_and_publish_root_pose(msg)

    def _calculate_and_publish_root_pose(self, cog_odom_msg):
        """Calculate root pose from CoG pose and publish it"""
        try:
            # Get transform from CoG to root (inverse of root to CoG)
            self.tf_listener.waitForTransform("dragon/cog", "dragon/root", rospy.Time(0), rospy.Duration(0.1))
            (trans_cog_to_root, rot_cog_to_root) = self.tf_listener.lookupTransform("dragon/cog", "dragon/root", rospy.Time(0))

            # Create transformation matrix from CoG to root
            cog_to_root_matrix = tf.transformations.concatenate_matrices(
                tf.transformations.translation_matrix(trans_cog_to_root),
                tf.transformations.quaternion_matrix(rot_cog_to_root)
            )

            # Get current CoG pose from odometry
            cog_pose = cog_odom_msg.pose.pose
            cog_quat = [cog_pose.orientation.x, cog_pose.orientation.y, 
                       cog_pose.orientation.z, cog_pose.orientation.w]
            
            # Create transformation matrix for CoG in world frame
            world_to_cog_matrix = tf.transformations.concatenate_matrices(
                tf.transformations.translation_matrix([cog_pose.position.x, 
                                                       cog_pose.position.y, 
                                                       cog_pose.position.z]),
                tf.transformations.quaternion_matrix(cog_quat)
            )

            # Calculate root pose in world frame: world_to_cog * cog_to_root
            world_to_root_matrix = tf.transformations.concatenate_matrices(
                world_to_cog_matrix, cog_to_root_matrix
            )

            # Extract position and orientation
            root_pos = tf.transformations.translation_from_matrix(world_to_root_matrix)
            root_quat = tf.transformations.quaternion_from_matrix(world_to_root_matrix)

            # Create and publish PoseStamped message
            root_pose_msg = PoseStamped()
            root_pose_msg.header.stamp = cog_odom_msg.header.stamp
            root_pose_msg.header.frame_id = "world"
            root_pose_msg.pose.position.x = root_pos[0]
            root_pose_msg.pose.position.y = root_pos[1]
            root_pose_msg.pose.position.z = root_pos[2]
            root_pose_msg.pose.orientation.x = root_quat[0]
            root_pose_msg.pose.orientation.y = root_quat[1]
            root_pose_msg.pose.orientation.z = root_quat[2]
            root_pose_msg.pose.orientation.w = root_quat[3]

            self.root_pose_pub.publish(root_pose_msg)

        except (tf.LookupException, tf.ConnectivityException, tf.ExtrapolationException) as e:
            rospy.logwarn_throttle(5.0, f"Failed to calculate root pose: {e}")

    def run(self):
        """Main loop"""
        rospy.spin()


if __name__ == '__main__':
    try:
        publisher = DragonRootPosePublisher()
        publisher.run()
    except rospy.ROSInterruptException:
        pass
