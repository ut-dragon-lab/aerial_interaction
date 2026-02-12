#!/usr/bin/env python
import rospy, sys
import numpy as np
from spinal.msg import ServoControlCmd, ServoStates

class AutoGrasping:
    def __init__(self):
        rospy.init_node("autoGrasping")

        #Prepared values
        self.limitLoadInf_0 = 20
        self.limitLoadSup_0 = 60
        self.limitLoadInf_1_open = 30
        self.limitLoadSup_1_open = 70
        self.limitLoadInf_1_close = 30
        self.limitLoadSup_1_close = 90
        self.servoMoveRange = 100

        #Parameters
        self.currentServoLoad_0 = 0.0
        self.currentServoPosition_0 = 0.0
        self.targetServoPosition_0 = 0.0

        self.currentServoLoad_1 = 0.0
        self.currentServoPosition_1 = 0.0
        self.targetServoPosition_1 = 0.0

        #Flags
        self.targetTorqueReachedFlag_0 = False
        self.targetTorqueReachedFlag_1 = False
        self.OpenFlag_0 = rospy.get_param('OpenFlag_0', True)
        self.OpenFlag_1 = rospy.get_param('OpenFlag_1', True)

        #ROS
        self.last_callback_time = rospy.get_time()
        self.sub = rospy.Subscriber('/servo/states', ServoStates, self.callback, queue_size=10)
        self.pub = rospy.Publisher('/servo/target_states', ServoControlCmd, queue_size=10)
        self.rate = rospy.Rate(40)

    def check_subscription(self):
        current_time = rospy.get_time()
        if current_time - self.last_callback_time > 5.0:
            print(f"\033[1;91m[Error] No servo data!! \033[0m")

    def calculatePosition(self, targetServoIndex):
        if targetServoIndex == 0:
            if self.OpenFlag_0:
                if -self.limitLoadInf_0 < self.currentServoLoad_0:
                    self.targetServoPosition_0 = int(self.currentServoPosition_0 - self.servoMoveRange)
                    print(f"Opening")
                elif -self.limitLoadSup_0 < self.currentServoLoad_0 <= -self.limitLoadInf_0:
                    self.OpenFlag_0 = not self.OpenFlag_0
                    rospy.set_param('OpenFlag_0', self.OpenFlag_0)
                    self.targetTorqueReachedFlag_0 = True
                    print(f"Stopped")
                else:
                    self.targetServoPosition_0 = int(self.currentServoPosition_0 + self.servoMoveRange)
                    print(f"Overload!!!!!!!!")
                    print(f"Moving Back")
            else:
                if self.currentServoLoad_0 < -self.limitLoadInf_0:
                    self.targetServoPosition_0 = int(self.currentServoPosition_0 + self.servoMoveRange)
                    print(f"Closing")
                elif -self.limitLoadInf_0 < self.currentServoLoad_0 < 0:
                    self.OpenFlag_0 = not self.OpenFlag_0
                    rospy.set_param('OpenFlag_0', self.OpenFlag_0)
                    self.targetTorqueReachedFlag_0 = True
                    print(f"Stopped")
                else:
                    self.targetServoPosition_0 = int(self.currentServoPosition_0 - self.servoMoveRange)
                    print(f"Moving Back")
            self.sendGraspingCommand(targetServoIndex)

        elif targetServoIndex == 1:
            if self.OpenFlag_1:
                if self.currentServoLoad_1  < self.limitLoadInf_1_open:
                    self.targetServoPosition_1 = int(self.currentServoPosition_1 + self.servoMoveRange)
                elif self.limitLoadInf_1_open < self.currentServoLoad_1 <= self.limitLoadSup_1_open:
                    self.OpenFlag_1 = not self.OpenFlag_1
                    rospy.set_param('OpenFlag_1', self.OpenFlag_1)
                    self.targetTorqueReachedFlag_1 = True
                else:
                    self.targetServoPosition_1 = int(self.currentServoPosition_1 - self.servoMoveRange)
            else:
                if -self.limitLoadInf_1_close < self.currentServoLoad_1:
                    self.targetServoPosition_1 = int(self.currentServoPosition_1 - self.servoMoveRange)
                elif -self.limitLoadSup_1_close < self.currentServoLoad_1 <= -self.limitLoadInf_1_close:
                    self.OpenFlag_1 = not self.OpenFlag_1
                    rospy.set_param('OpenFlag_1', self.OpenFlag_1)
                    self.targetTorqueReachedFlag_1 = True
                else:
                    self.targetServoPosition_1 = int(self.currentServoPosition_1 + self.servoMoveRange)
            self.sendGraspingCommand(targetServoIndex)

    def sendGraspingCommand(self, targetServoIndex):
        cmd = ServoControlCmd()
        if targetServoIndex == 0:
            cmd.index = [0]
            cmd.angles = [int(self.targetServoPosition_0)]
        else:
            cmd.index = [1]
            cmd.angles = [int(self.targetServoPosition_1)]
        self.pub.publish(cmd)

    def callback(self, data):
        self.last_callback_time = rospy.get_time()

        index0_data = next((servo for servo in data.servos if servo.index == 0), None)
        index1_data = next((servo for servo in data.servos if servo.index == 1), None)

        if index0_data:
            self.currentServoLoad_0 = index0_data.load
            self.currentServoPosition_0 = index0_data.angle
        if index1_data:
            self.currentServoLoad_1 = index1_data.load
            self.currentServoPosition_1 = index1_data.angle

    def main(self):
        while not rospy.is_shutdown():
            # どのサーボを動かすかの入力受付
            print("\033[1mEnter the servo,(h:0, v:1, q:quit): \033[0m")
            try:
                targetInput = input().strip().lower()
            except KeyboardInterrupt:
                rospy.loginfo("Interrupted from keyboard.")
                rospy.signal_shutdown("")
                break

            if targetInput == "q":
                rospy.loginfo("Quit command received.")
                break
            elif targetInput == "h":
                targetServoIndex = 0
            elif targetInput == "v":
                targetServoIndex = 1
            else:
                print("Incorrect input. Please enter h, v or q.")
                continue

            # 選んだサーボのフラッグをリセット
            if targetServoIndex == 0:
                self.targetTorqueReachedFlag_0 = False
            else:
                self.targetTorqueReachedFlag_1 = False
                

            while not rospy.is_shutdown():
                self.check_subscription()
                self.calculatePosition(targetServoIndex)

                if targetServoIndex == 0 and self.targetTorqueReachedFlag_0:
                    print("\033[1;32m[Msg] Servo 0 target torque reached. \033[0m")
                    break
                if targetServoIndex ==1 and self.targetTorqueReachedFlag_1:
                    print("\033[1;32m[Msg] Servo 1 target torque reached. \033[0m")
                    break
            
                self.rate.sleep()

        rospy.loginfo("Exiting main loop.")

if __name__ == "__main__":
    try:
        auto_grasping = AutoGrasping()
        auto_grasping.main()
        rospy.spin()
    except rospy.ROSInterruptException:
        sys.exit(1)
    except KeyError:
        rospy.logerr(f"Error: OpenFlag_0 or OpenFlag_1 not found!")
        sys.exit(1)
