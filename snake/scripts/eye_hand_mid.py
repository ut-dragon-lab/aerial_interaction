#!/usr/bin/env python
# -*- coding: utf-8 -*-

# ドローンが目と手の中点に来るようにする


import rospy
import math
from geometry_msgs.msg import PoseStamped
from std_msgs.msg import String
from std_msgs.msg import Empty
from aerial_robot_msgs.msg import FlightNav

class eye_hand_center:
    def __init__(self):
        rospy.init_node('eye_hand_center')

        #手の位置を格納
        self.hand_position = PoseStamped()

        #目の位置を格納
        self.eye_position = PoseStamped()

        #ドローンの目標位置を格納
        self.nav_msg = FlightNav()
        self.nav_msg.control_frame = FlightNav.WORLD_FRAME
        self.nav_msg.target = FlightNav.COG
        self.nav_msg.pos_xy_nav_mode = FlightNav.POS_MODE
        self.nav_msg.pos_z_nav_mode = FlightNav.POS_MODE

        #ドローンの目標位置を発行
        self.nav_pub = rospy.Publisher('/quadrotor/uav/nav', FlightNav, queue_size = 10)

        #手の位置を購読
        self.hand_sub = rospy.Subscriber('/wrist/mocap/pose', PoseStamped, self.hand_cb)

        #目の位置を購読
        self.eye_sub = rospy.Subscriber('/eye/mocap/pose', PoseStamped, self.eye_cb)

        
        #スタートの合図
        rospy.loginfo("Start")


    def hand_cb(self, msg):
        self.hand_position = msg
        self.hand_x = self.hand_position.pose.position.x
        self.hand_y = self.hand_position.pose.position.y
        self.hand_z = self.hand_position.pose.position.z
        self.go_to_center()

        
    def eye_cb(self, msg):
        self.eye_position = msg
        self.eye_x = self.eye_position.pose.position.x
        self.eye_y = self.eye_position.pose.position.y
        self.eye_z = self.eye_position.pose.position.z
        self.go_to_center()

    def go_to_center(self):
        #どちらの位置も受け取っている時のみ実行
        if self.hand_position is None or self.eye_position is None:
            return

        #中点を計算
        center_x = (self.hand_x + self.eye_x) / 2.0
        center_y = (self.hand_y + self.eye_y) / 2.0
        center_z = (self.hand_z + self.eye_z) / 2.0

        #中点をドローンの目標位置に設定
        self.nav_msg.target_pos_x = center_x
        self.nav_msg.target_pos_y = center_y
        self.nav_msg.target_pos_z = center_z

        #目標位置を発行
        self.nav_pub.publish(self.nav_msg)

        rospy.loginfo("Published drone target: x=%.2f, y=%.2f, z=%.2f", center_x, center_y, center_z)


if __name__ == '__main__':
    try:
        node = eye_hand_center()
        rospy.spin()
    except rospy.ROSInterruptException:
        pass
    
