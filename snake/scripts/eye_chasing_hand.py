#!/usr/bin/env python
# -*- coding: utf-8 -*-

import rospy
import math
import numpy as np
from geometry_msgs.msg import PoseStamped
from tf.transformations import quaternion_from_euler, quaternion_matrix, quaternion_multiply

class HandFollower:
    """
    手の位置生成をキーボードから入力し、
    ・手の平法線方向（手ローカル+Z)上に「目(eye)」を配置する。
    ・目が手の平を正面から見るように姿勢（クオータニオン）を合わせる。
    という動作を行うノード。

    目のローカル座標系の軸が手のローカル軸とどう対応するかは以下：
    X_e = -Z_h
    Y_e = -Y_h
    Z_e = -X_h
    この回転は　roll=0, pitch=+90°, yaw=180°により実現できる。
    """
    
    def __init__(self):
        rospy.init_node('hand_follower')

        #Publishするトピック名
        self.hand_topic = rospy.get_param("~hand_topic", "/wrist/mocap/pose")
        self.eye_topic = rospy.get_param("~eye_topic", "/eye/mocap/pose")

        #手の平法線方向へどれくらい離れて目を置くか [m]
        self.eye_offset = rospy.get_param("~eye_offset", 0.4)

        self.hand_pub = rospy.Publisher(self.hand_topic, PoseStamped, queue_size = 1)
        self.eye_pub = rospy.Publisher(self.eye_topic, PoseStamped, queue_size = 1)

        rospy.loginfo("Eye-Chasing-Hand Started.")
        rospy.loginfo(" hand_topic: %s", self.hand_topic)
        rospy.loginfo(" eye_topic: %s", self.eye_topic)
        rospy.loginfo(" eye_offset: %.3f [m]", self.eye_offset)

    def compute_eye_pose(self, hand_pose):
        """
        入力された手のPoseStampedから、目のPoseStampedを計算する。
        
        【位置の決め方】
        　　手首位置 hand_posから、
        　　手のローカル+z(手の平法線）方向にeye_offsetだけ離れた点を目の位置とする。

        【姿勢の決め方】
        　　手ローカル軸（X_h, Y_h, Z_h）に対し、
        　　目のローカル軸を以下のように対応させる回転を適用する：
        
        　　　X_e = -Z_h
        　　　Y_e = -Y_h
        　　　Z_e = -X_h　

          この目的の回転は roll=0, pitch=+90°, yaw=180で実現できる。
        """°

        #手の位置ベクトル
        hx = hand_pose.pose.position.x
        hy = hand_pose.pose.position.y
        hz = hand_pose.pose.position.z
        hand_pos = np.array([hx, hy, hz])

        #手のクオータニオン
        qh = hand_pose.pose.orientation
        q_hand = np.array([qh.x, qh.y, qh.z, qh.w])

        #手座標系の+Z軸(0,0,1)をワールド座標系に変換
        #quaternion_matrixで4x4の回転行列にして、その3x3部分を取り出す。
        R = quaternion_matrix(q_hand)[0:3, 0:3]
        normal_hand_frame = np.array([0.0, 0.0, 1.0])
        normal_world = R.dot(normal_hand_frame)
        normal_world = normal_world / np.linalg.norm(normal_world)

        #目の位置 = 手の位置 + offset * 法線
        eye_pos = hand_pos + self.eye_offset * normal_world

        #目の姿勢：手の姿勢にオフセット回転を適用
        #roll=0, pitch=+pi/2, yaw=pi

        q_offset = quaternion_from_euler(0.0, math.pi/2.0, math.pi)
        q_eye = quaternion_multiply(q_hand, q_offset)
        
        #PoseStampedとして格納
        eye_pose = PoseStamped()
        eye_pose.header.frame_id = hand_pose.header.frame_id
        eye_pose.header.stamp = rospy.Time.now()

        eye_pose.pose.position.x = eye_pos[0]
        eye_pose.pose.position.y = eye_pos[1]
        eye_pose.pose.position.z = eye_pos[2]

        eye_pose.pose.orientation.x = q_eye[0]
        eye_pose.pose.orientation.y = q_eye[1]
        eye_pose.pose.orientation.z = q_eye[2]
        eye_pose.pose.orientation.w = q_eye[3]

        return eye_pose

    def run(self):
        """
        キーボードから手の位置姿勢を何度でも入力できるループ
        入力フォーマット：x y z roll_deg pitch_deg yaw_deg
        (終了したいときは、'q'を入力）
        """
        rate = rospy.Rate(10)

        print("")
        print("=== Eye-Chasing-Hand ===")
        print("手の位置姿勢を入力すると、その手の平法線方向上に目を配置します。")
        print("入力フォーマット：x y z roll_deg pitch_deg yaw_deg")
        print("例：0.5 0.0 1.0 0 0 90")
        print("")

        while not rospy.is_shutdown():
            try:
                user_input = input("hand pose ->")
            except EOFError:
                break

            if user_input.strip().lower() == "q":
                rospy.loginfo("Quit requested.")
                break

            if not user_input.strip():
                continue

            try:
                vals = [float(v) for v in user_input.split()]
                if len(vals) != 6:
                    rospy.logwarn("6個の数値（x y z roll pitch yaw）を入力してください。")
                    continue
                x, y, z, roll_deg, pitch_deg, yaw_deg = vals
            except ValueError:
                rospy.logwarn("数値として解釈できませんでした。もう一度入力して下さい。")
                continue


            #角度をradに変換
            roll = math.radians(roll_deg)
            pitch = math.radians(pitch_deg)
            yaw = math.radians(yaw_deg)

            #手のクオータニオン
            q_hand = quaternion_from_euler(roll, pitch, yaw)

            #手のPoseStampedを作成
            hand_pose = PoseStamped()
            hand_pose.header.stamp = rospy.Time.now()
            #frame_idは必要に応じて変更（"world"や"map"など）
            hand_pose.header.frame_id = "world"

            hand_pose.pose.position.x = x
            hand_pose.pose.position.y = y
            hand_pose.pose.position.z = z

            hand_pose.pose.orientation.x = q_hand[0]
            hand_pose.pose.orientation.y = q_hand[1]
            hand_pose.pose.orientation.z = q_hand[2]
            hand_pose.pose.orientation.w = q_hand[3]

            #目のPoseを計算
            eye_pose = self.compute_eye_pose(hand_pose)

            #Publish
            self.hand_pub.publish(hand_pose)
            self.eye_pub.publish(eye_pose)

            #コンソールに分かりやすく表示（確認しやすくするため）
            rospy.loginfo("Hand pose:")
            rospy.loginfo(" pos = (%.3f, %.3f, %.3f)", x, y, z)
            rospy.loginfo(" rpy = (%.1f, %.1f, %.1f) [deg]", roll_deg, pitch_deg, yaw_deg)

            rospy.loginfo("Eye pose:")
            rospy.loginfo(" pos = (%.3f, %.3f, %.3f)",
                          eye_pose.pose.position.x,
                          eye_pose.pose.position.y,
                          eye_pose.pose.position.z)

            #姿勢はクオータニオンのまま出しているが、必要ならrpyに戻してもよい
            qe = eye_pose.pose.orientation
            rospy.loginfo(" quat = (x=%.3f, y=%.3f, z=%.3f, w=%.3f)",
                          qe.x, qe.y, qe.z, qe.w)

            #すぐ次の入力を受け付けたいので、Rate.sleepだけ軽く回しておく
            rate.sleep()

if __name__ == "__main__":
    node = HandFollower()
    node.run()
