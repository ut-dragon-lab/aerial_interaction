#!/usr/bin/env python
# -*- coding: utf-8 -*-

# Software License Agreement (BSD License)

# Copyright (c) 2025, DRAGON Laboratory, The University of Tokyo
# All rights reserved.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions are met:
#
#     * Redistributions of source code must retain the above copyright
#       notice, this list of conditions and the following disclaimer.
#     * Redistributions in binary form must reproduce the above copyright
#       notice, this list of conditions and the following disclaimer in the
#       documentation and/or other materials provided with the distribution.
#     * Neither the name of the Willow Garage, Inc. nor the names of its
#       contributors may be used to endorse or promote products derived from
#       this software without specific prior written permission.
#
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
# AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
# IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
# ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
# LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
# CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
# SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
# INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
# CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
# ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
# POSSIBILITY OF SUCH DAMAGE.


import rospy
from geometry_msgs.msg import PoseStamped
from gazebo_msgs.msg import ModelState

class PoseToGazeboPublisher:
    def __init__(self):
        rospy.init_node('pose_to_gazebo_state')

        # Publisher
        self.pub = rospy.Publisher('/gazebo/set_model_state', ModelState, queue_size=10)

        # Subscriber
        rospy.Subscriber('hand_pose', PoseStamped, self.hand_pose_cb)
        rospy.Subscriber('eye_pose', PoseStamped, self.eye_pose_cb)

    def hand_pose_cb(self, msg):
        state = ModelState()
        state.model_name = 'hand'
        state.reference_frame = 'world'
        state.pose = msg.pose

        self.pub.publish(state)

    def eye_pose_cb(self, msg):
        state = ModelState()
        state.model_name = 'eye'
        state.reference_frame = 'world'
        state.pose = msg.pose

        self.pub.publish(state)

if __name__ == "__main__":
    try:
        PoseToGazeboPublisher()
        rospy.spin()
    except rospy.ROSInterruptException:
        pass
