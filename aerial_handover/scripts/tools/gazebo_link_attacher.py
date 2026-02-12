#!/usr/bin/env python

import rospy
from gazebo_ros_link_attacher.srv import Attach, AttachRequest, AttachResponse


class GazeboLinkAttacher():
    def __init__(self, model_name_1, link_name_1, model_name_2, link_name_2):
        # rospy.init_node('demo_attach_links')
        self.model_name_1 = model_name_1
        self.model_name_2 = model_name_2
        self.link_name_1 = link_name_1
        self.link_name_2 = link_name_2
    def attach_links(self):
        rospy.loginfo("Creating ServiceProxy to /link_attacher_node/attach")
        attach_srv = rospy.ServiceProxy('/link_attacher_node/attach',
                                        Attach)
        attach_srv.wait_for_service()
        rospy.loginfo("Created ServiceProxy to /link_attacher_node/attach")

        # Link them
        rospy.loginfo("Attaching link")
        req = AttachRequest()
        req.model_name_1 = self.model_name_1
        req.link_name_1 = self.link_name_1
        req.model_name_2 = self.model_name_2
        req.link_name_2 = self.link_name_2
        rospy.loginfo(f"Attaching {self.model_name_1}:{self.link_name_1} and {self.model_name_2}:{self.link_name_2}")
        attach_srv.call(req)
        rospy.loginfo(f"Successfully attached {self.model_name_1}:{self.link_name_1} and {self.model_name_2}:{self.link_name_2}")