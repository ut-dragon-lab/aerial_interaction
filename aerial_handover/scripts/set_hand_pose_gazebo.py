#!/usr/bin/env python
# -*- coding: utf-8 -*-

import rospy
from geometry_msgs.msg import PoseStamped
from gazebo_msgs.srv import SetModelState
from gazebo_msgs.msg import ModelState


class HandGazeboFollower:
    def __init__(self):
        rospy.init_node('set_hand_pose_gazebo')

        # Gazebo 上の hand モデル名（task.launch で -model hand になっている）
        self.model_name = rospy.get_param('~model_name', 'hand')

        self.sub = rospy.Subscriber('hand_pose', PoseStamped, self.pose_callback, queue_size=1)

        rospy.wait_for_service('/gazebo/set_model_state')
        rospy.loginfo("Waiting for /gazebo/set_model_state service...")
        self.set_model_state = rospy.ServiceProxy('/gazebo/set_model_state', SetModelState)
        rospy.loginfo("Connected to /gazebo/set_model_state")

    def pose_callback(self, msg):
        state = ModelState()
        state.model_name = self.model_name
        state.pose = msg.pose
        # world 座標系でセット
        state.reference_frame = "world"

        try:
            self.set_model_state(state)
        except rospy.ServiceException as e:
            rospy.logwarn("Failed to call set_model_state: %s", e)


if __name__ == '__main__':
    try:
        HandGazeboFollower()
        rospy.spin()
    except rospy.ROSInterruptException:
        pass
