#!/usr/bin/env python3

import rospy
from geometry_msgs.msg import PoseStamped, TransformStamped
import tf2_ros
from tf.transformations import quaternion_from_euler
import tf2_geometry_msgs  # required
import numpy as np


class PoseTransformer:
    def __init__(self):
        rospy.init_node('pose_transformer', anonymous=False)
        rospy.loginfo("PoseTransformer node started successfully")

        self.handover_dis_x = rospy.get_param('~handover_dis_x', 0.1)
        self.handover_dis_z = rospy.get_param('~handover_dis_z', 0.1)
        self.handover_pitch = rospy.get_param('~handover_pitch', 0.1)

        self.hand_pose_sub = rospy.Subscriber('/desired_3D_pose', PoseStamped, self.hand_pose_cb)

        self.robot_head_pose_pub = rospy.Publisher('/robot_head_pose', PoseStamped, queue_size=10)

        self.world2hand_tf_bc = tf2_ros.TransformBroadcaster()
        self.world2hand_tf = TransformStamped()
        self.world2hand_tf.header.frame_id = "world"
        self.world2hand_tf.child_frame_id = "hand_frame"

        self.tf_buffer = tf2_ros.Buffer()
        self.tf_listener = tf2_ros.TransformListener(self.tf_buffer)

        self.robot_head_pose_in_hand = PoseStamped()
        self.robot_head_pose_in_hand.header.frame_id = "hand_frame"
        self.robot_head_pose_in_hand.pose.position.x = self.handover_dis_x
        self.robot_head_pose_in_hand.pose.position.y = 0.0
        self.robot_head_pose_in_hand.pose.position.z = self.handover_dis_z
        q = quaternion_from_euler(0.0, self.handover_pitch, 0)
        self.robot_head_pose_in_hand.pose.orientation.x = q[0]
        self.robot_head_pose_in_hand.pose.orientation.y = q[1]
        self.robot_head_pose_in_hand.pose.orientation.z = q[2]
        self.robot_head_pose_in_hand.pose.orientation.w = q[3]

        print("New test")

    def hand_pose_cb(self, msg):
        self.world2hand_tf.header.stamp = rospy.Time.now()
        self.world2hand_tf.transform.translation.x = msg.pose.position.x
        self.world2hand_tf.transform.translation.y = msg.pose.position.y
        self.world2hand_tf.transform.translation.z = msg.pose.position.z
        self.world2hand_tf.transform.rotation = msg.pose.orientation
        self.world2hand_tf_bc.sendTransform(self.world2hand_tf)

        self.transform_pose()

    def transform_pose(self):
        self.robot_head_pose_in_hand.header.stamp = self.world2hand_tf.header.stamp  # Use The same timestamp as the hand frame

        try:
            robot_head_pose_in_world = self.tf_buffer.transform(
                self.robot_head_pose_in_hand, "world", rospy.Duration(0.5))  # waiting fot TF timeout of 0.5 seconds
            self.robot_head_pose_pub.publish(robot_head_pose_in_world)

        except Exception as e:
            rospy.logerr(e)


if __name__ == '__main__':
    transformer = PoseTransformer()
    rospy.spin()
