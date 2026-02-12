#!/usr/bin/env python3
import rospy
from geometry_msgs.msg import PoseStamped

class QuestPoseRelay:
    def __init__(self):
        rospy.init_node("quest_pose_relay")

        self.in_topic  = rospy.get_param("~in",  "/quest/test_pose")
        self.out_topic = rospy.get_param("~out", "/eye/mocap/pose")

        self.pub = rospy.Publisher(self.out_topic, PoseStamped, queue_size=10)
        rospy.Subscriber(self.in_topic, PoseStamped, self.cb, queue_size=10)

        rospy.loginfo("Relay: %s -> %s", self.in_topic, self.out_topic)

    def cb(self, msg: PoseStamped):
        msg.header.stamp = rospy.Time.now()
        self.pub.publish(msg)

if __name__ == "__main__":
    QuestPoseRelay()
    rospy.spin()
