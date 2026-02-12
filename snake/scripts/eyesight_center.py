#!/usr/bin/env python
# -*- coding: utf-8 -*-

#ドローンが視界の中心に来るようにする

import rospy
import math
import numpy as np
from geometry_msgs.msg import PoseStamped
from std_msgs.msg import String
from std_msgs.msg import Empty
from aerial_robot_msgs.msg import FlightNav

class eyesight_center:
    def __init__(self):
        rospy.init_node('eyesight_center')
        
        #目の位置・姿勢を格納
        self.eye_pose = PoseStamped()
        
        #ドローンの目標位置を格納
        self.nav_msg = FlightNav()
        self.nav_msg.control_frame = FlightNav.WORLD_FRAME
        self.nav_msg.target = FlightNav.COG
        self.nav_msg.pos_xy_nav_mode = FlightNav.POS_MODE
        self.nav_msg.pos_z_nav_mode = FlightNav.POS_MODE

        #ドローンの目標位置を発行
        self.nav_pub = rospy.Publisher('/quadrotor/uav/nav', FlightNav, queue_size = 10)

        #目からドローンまでの距離
        self.d = 1.0

        #目の位置を購読
        self.eye_sub = rospy.Subscriber('/eye/mocap/pose', PoseStamped, self.eye_cb)

        #スタートの合図
        rospy.loginfo("Start")

    def rotate_vector_by_quaternion(self, qx, qy, qz, qw, v):
        qv = np.array([qx, qy, qz])
        t = 2.0 * np.cross(qv,v)
        return v + qw*t + np.cross(qv, t)

    def eye_cb(self, msg):
        self.eye_pose = msg

        eye_pos = np.array([
            msg.pose.position.x,
            msg.pose.position.y,
            msg.pose.position.z
            ])

        #クオータニオン
        qx = msg.pose.orientation.x
        qy = msg.pose.orientation.y
        qz = msg.pose.orientation.z
        qw = msg.pose.orientation.w

        #ローカル前方ベクトル（視線方向）:+X軸
        v_local = np.array([1.0, 0.0, 0.0])

        forward_world = self.rotate_vector_by_quaternion(qx, qy, qz, qw, v_local)
        forward_world /= np.linalg.norm(forward_world)

        #ドローンを目の前 d[m]の距離に配置
        target_pos = eye_pos + self.d*forward_world

        #FlightNavメッセージに反映
        self.nav_msg.target_pos_x = target_pos[0]
        self.nav_msg.target_pos_y = target_pos[1]
        self.nav_msg.target_pos_z = target_pos[2]

        #メッセージを送信
        self.nav_pub.publish(self.nav_msg)
        
        rospy.loginfo(
            f"Drone:{np.array2string(target_pos,precision=2,separator=',')},"
            f"Eye: position{np.array2string(eye_pos,precision=2,separator=',')}"
            f"direction:{np.array2string(forward_world,precision=2,separator=',')}")

    def spin(self):
            rospy.spin()


if __name__ == '__main__':
    try:
        node = eyesight_center()
        node.spin()
    except rospy.ROSInterruptException:
        pass
