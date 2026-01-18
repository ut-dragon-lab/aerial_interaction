#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import rospy
import numpy as np
from geometry_msgs.msg import PoseStamped
from std_msgs.msg import String


class DistanceBasedGrasping:
    def __init__(self):
        rospy.init_node('distance_based_grasping', anonymous=False)
        
        # Thresholds
        self.open_threshold = rospy.get_param('~open_threshold', 0.15)  # Distance to trigger "open"
        self.close_threshold = rospy.get_param('~close_threshold', 0.30)  # Distance to trigger "close"
        
        # State management
        self.is_opened = False  # Track whether gripper is opened
        
        # Pose storage
        self.hand_pose = None
        self.dragon_pose = None
        
        # Subscribers
        self.hand_sub = rospy.Subscriber('/hand_pose', PoseStamped, self.hand_pose_callback)
        self.dragon_sub = rospy.Subscriber('/dragon/root_pose', PoseStamped, self.dragon_pose_callback)
        
        # Publisher
        self.command_pub = rospy.Publisher('/autograsping/command', String, queue_size=10)
        
        rospy.loginfo("Distance-based grasping node initialized")
        rospy.loginfo(f"Open threshold: {self.open_threshold}m, Close threshold: {self.close_threshold}m")
    
    def hand_pose_callback(self, msg):
        """Callback for /hand_pose topic"""
        self.hand_pose = msg
        self.check_distance()
    
    def dragon_pose_callback(self, msg):
        """Callback for /dragon/root_pose topic"""
        self.dragon_pose = msg
        self.check_distance()
    
    def calculate_distance(self):
        """Calculate Euclidean distance between hand and dragon poses"""
        if self.hand_pose is None or self.dragon_pose is None:
            return None
        
        hand_pos = self.hand_pose.pose.position
        dragon_pos = self.dragon_pose.pose.position
        
        distance = np.sqrt(
            (hand_pos.x - dragon_pos.x)**2 +
            (hand_pos.y - dragon_pos.y)**2 +
            (hand_pos.z - dragon_pos.z)**2
        )
        
        return distance
    
    def check_distance(self):
        """Check distance and publish commands based on thresholds"""
        distance = self.calculate_distance()
        
        if distance is None:
            return
        
        # State machine logic
        if not self.is_opened and distance < self.open_threshold:
            # Trigger "open" command
            msg = String()
            msg.data = "open"
            self.command_pub.publish(msg)
            self.is_opened = True
            rospy.loginfo(f"Distance: {distance:.3f}m < {self.open_threshold}m - Publishing 'open' command")
        
        elif self.is_opened and distance > self.close_threshold:
            # Trigger "close" command
            msg = String()
            msg.data = "close"
            self.command_pub.publish(msg)
            self.is_opened = False
            rospy.loginfo(f"Distance: {distance:.3f}m > {self.close_threshold}m - Publishing 'close' command")
    
    def run(self):
        """Main loop"""
        rospy.spin()


if __name__ == '__main__':
    try:
        node = DistanceBasedGrasping()
        node.run()
    except rospy.ROSInterruptException:
        pass
