#!/usr/bin/env python

import rospy
import smach
import smach_ros
import math,time
from std_msgs.msg import Empty, String, Bool
from aerial_robot_msgs.msg import FlightNav
from spinal.msg import DesireCoord
from geometry_msgs.msg import PoseStamped
from diagnostic_msgs.msg import KeyValue
import numpy as np
import tf
from beetle.gazebo_link_attacher import GazeboLinkAttacher
from beetle.gazebo_link_detacher import GazeboLinkDetacher
from gazebo_ros_link_attacher.srv import Attach, AttachRequest, AttachResponse

if __name__ == '__main__':
        if not self.real_machine:
            try:
                link_attacher = GazeboLinkAttacher(self.robot_name, 'root', self.leader, 'root')
                link_attacher.attach_links()
            except rospy.ServiceException:
                rospy.loginfo("Attacher failed")        
        rospy.sleep(2.0)

        return 'done'       