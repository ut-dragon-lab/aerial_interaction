#!/usr/bin/env python
import rospy, sys
import numpy as np
from std_msgs.msg import String, Float32, Bool
from spinal.msg import ServoControlCmd, ServoStates, ServoTorqueCmd

# from geometry_msgs import PoseStamped

class AutoGrasping:
    def __init__(self):
        rospy.init_node("autoGrasping")

        # Thresholds and step sizes for load-based control
        self.limitLoadInf_0 = 150
        self.limitLoadInf_0_pub = rospy.Publisher('/servo0/limit_load/inf', Float32, queue_size=10)
        
        self.limitLoadSup_0 = 200
        self.limitLoadSup_0_pub = rospy.Publisher('/servo0/limit_load/sup', Float32, queue_size=10)

        self.limitLoadInf_1_open = 40
        self.limitLoadInf_1_open_pub = rospy.Publisher('/servo1/limit_load/inf/open', Float32, queue_size=10)

        self.limitLoadSup_1_open = 100
        self.limitLoadSup_1_open_pub = rospy.Publisher('/servo1/limit_load/sup/open', Float32, queue_size=10)

        self.limitLoadInf_1_close = 120
        self.limitLoadInf_1_close_pub = rospy.Publisher('/servo1/limit_load/inf/close', Float32, queue_size=10)

        self.limitLoadSup_1_close = 180
        self.limitLoadSup_1_close_pub = rospy.Publisher('/servo1/limit_load/sup/close', Float32, queue_size=10)

        self.servoMoveRange_0 = rospy.get_param('servoMoveRange_0', 100)
        self.servoMoveRange_1 = rospy.get_param('servoMoveRange_1', 50)
        self.servoMoveRange_1_init = rospy.get_param('servoMoveRange_1_init', 30)
        self.servoMoveRange_0_close = rospy.get_param('servoMoveRange_0_close', 50)

        # Servo state cache (updated by /servo/states)
        self.currentServoLoad_0 = 0.0
        self.currentServoLoad_0_pub = rospy.Publisher('/servo0/current_load', Float32, queue_size=10)
        self.currentServoPosition_0 = 0.0
        self.currentServoPosition_0_pub = rospy.Publisher('/servo0/current_pos', Float32, queue_size=10)
        self.targetServoPosition_0 = 0.0
        self.targetServoPosition_0_pub = rospy.Publisher('/servo0/target_pos', Float32, queue_size=10)

        self.currentServoLoad_1 = 0.0
        self.currentServoLoad_1_pub = rospy.Publisher('/servo1/current_load', Float32, queue_size=10)
        self.currentServoPosition_1 = 0.0
        self.currentServoPosition_1_pub = rospy.Publisher('/servo1/current_pos', Float32, queue_size=10)
        self.targetServoPosition_1 = 0.0
        self.targetServoPosition_1_pub = rospy.Publisher('/servo1/target_pos', Float32, queue_size=10)

        # Flags and open/close state
        self.targetTorqueReachedFlag_0 = False
        self.targetTorqueReachedFlag_1 = False
        self.OpenFlag_0 = rospy.get_param('OpenFlag_0', True)
        self.OpenFlag_1 = rospy.get_param('OpenFlag_1', True)

        # ROS I/O
        self.last_callback_time = rospy.get_time()
        self.sub = rospy.Subscriber('/servo/states', ServoStates, self.callback, queue_size=10)
        self.pub = rospy.Publisher('/servo/target_states', ServoControlCmd, queue_size=10)
        self.torque_pub = rospy.Publisher('/snake_head/servo/torque_enable', ServoTorqueCmd, queue_size=10)
        self.rate = rospy.Rate(40)
        self.command_topic = rospy.get_param('~command_topic', '/autograsping/command')
        self.command_sub = rospy.Subscriber('/autograsping/command', String, self.command_callback, queue_size=10)
        # self.command_sub = rospy.Subscriber(self.command_topic, String, self.command_callback, queue_size=10)

        # Command handling state
        self.pending_command = None
        self.is_busy = False
        self.is_busy_pub = rospy.Publisher('/state/is_busy', Bool, queue_size=10)

    def command_callback(self, msg):
        # Accept external command strings: open/close/init/quit or o/c/i/q
        command = msg.data.strip().lower()
        command_map = {
            "o": "open",
            "open": "open",
            "c": "close",
            "close": "close",
            "i": "init",
            "init": "init",
            "q": "quit",
            "quit": "quit",
        }
        normalized = command_map.get(command)
        if not normalized:
            rospy.logwarn("Unknown command received: %s", msg.data)
            return
        if self.is_busy:
            rospy.logwarn("Busy; ignoring command: %s", normalized)
            return
        rospy.loginfo("Command received: %s", normalized)
        self.pending_command = normalized

    def check_subscription(self):
        # Watchdog for stale servo state
        current_time = rospy.get_time()
        if current_time - self.last_callback_time > 5.0:
            print("\033[1;91m[Error] No servo data!! \033[0m")

    def step_servo0(self, action, step=None):
        # One control step for horizontal servo (0)
        if step is None:
            step = self.servoMoveRange_0

        # rospy.loginfo("step is " + str(step))
        # ここはちゃんと出てる step=50

        if action == "open":
            if self.currentServoLoad_0 < self.limitLoadInf_0:
                self.targetServoPosition_0 = int(self.currentServoPosition_0 + step)
                print("Opening H")
            elif self.limitLoadInf_0 <= self.currentServoLoad_0 <= self.limitLoadSup_0:
                self.OpenFlag_0 = False
                rospy.set_param('OpenFlag_0', self.OpenFlag_0)
                self.targetTorqueReachedFlag_0 = True
                print("Stopped H")
            else:
                self.targetServoPosition_0 = int(self.currentServoPosition_0 - step)
                print("Overload!!!!!!!!")
                print("Moving Back")
        elif action == "close":
            if self.currentServoLoad_0 < -30:
                self.targetServoPosition_0 = int(self.currentServoPosition_0 + step)
                print("Moving back H")
            elif -30 <= self.currentServoLoad_0 <= 5:
                self.OpenFlag_0 = True
                rospy.set_param('OpenFlag_0', self.OpenFlag_0)
                self.targetTorqueReachedFlag_0 = True
                print("Stopped H")
            else:
                self.targetServoPosition_0 = int(self.currentServoPosition_0 - step)
                print("Closing H")
        else:
            return

        self.sendGraspingCommand(0)

    def step_servo1(self, action, step=None):
        # One control step for vertical servo (1)
        if step is None:
            step = self.servoMoveRange_1

        rospy.loginfo("step is " + str(step))

        if action == "open":
            if self.currentServoLoad_1 < self.limitLoadInf_1_open:
                self.targetServoPosition_1 = int(self.currentServoPosition_1 + step)
                print("Opening V")
            elif self.limitLoadInf_1_open <= self.currentServoLoad_1 <= self.limitLoadSup_1_open:
                self.OpenFlag_1 = False
                rospy.set_param('OpenFlag_1', self.OpenFlag_1)
                self.targetTorqueReachedFlag_1 = True
                print("Stopped V")
            else:
                self.targetServoPosition_1 = int(self.currentServoPosition_1 - step)
                print("Overload V")
                print("Moving Back V")
        elif action == "close":
            if self.currentServoLoad_1 > -self.limitLoadInf_1_close:
                self.targetServoPosition_1 = int(self.currentServoPosition_1 - step)
                print("Closing V")
            elif -self.limitLoadSup_1_close <= self.currentServoLoad_1 <= -self.limitLoadInf_1_close:
                self.OpenFlag_1 = True
                rospy.set_param('OpenFlag_1', self.OpenFlag_1)
                self.targetTorqueReachedFlag_1 = True
                print("Stopped V")
            else:
                self.targetServoPosition_1 = int(self.currentServoPosition_1 + step)
                print("Moving Back V")
        else:
            return
        
        self.sendGraspingCommand(1)

    def sendGraspingCommand(self, targetServoIndex):
        # Publish the target position for a single servo
        cmd = ServoControlCmd()
        if targetServoIndex == 0:
            cmd.index = [0]
            cmd.angles = [int(self.targetServoPosition_0)]
            # cmd.angles = [self.currentServoPosition_0]
        else:
            cmd.index = [1]
            cmd.angles = [int(self.targetServoPosition_1)]
            # cmd.angles = [self.currentServoPosition_1]
        # rospy.loginfo(cmd)
        self.pub.publish(cmd)

    def set_servo_torque(self, targetServoIndex, enable):
        # Enable/disable servo torque (0: off, 1: on)
        cmd = ServoTorqueCmd()
        cmd.index = [targetServoIndex]
        cmd.torque_enable = [1 if enable else 0]
        self.torque_pub.publish(cmd)

    def sync_servo_target_to_current(self, targetServoIndex):
        # Prevent sudden jump when torque is re-enabled
        if targetServoIndex == 0:
            self.targetServoPosition_0 = int(self.currentServoPosition_0)
        else:
            self.targetServoPosition_1 = int(self.currentServoPosition_1)
        self.sendGraspingCommand(targetServoIndex)

    def enable_servo_torque_safely(self, targetServoIndex):
        self.sync_servo_target_to_current(targetServoIndex)
        rospy.sleep(0.05)
        self.set_servo_torque(targetServoIndex, True)

    def callback(self, data):
        # Cache the latest servo load and angle
        self.last_callback_time = rospy.get_time()

        index0_data = next((servo for servo in data.servos if servo.index == 0), None)
        index1_data = next((servo for servo in data.servos if servo.index == 1), None)

        if index0_data:
            self.currentServoLoad_0 = index0_data.load
            self.currentServoPosition_0 = index0_data.angle
            self.currentServoLoad_0_pub.publish(self.currentServoLoad_0)
            self.currentServoPosition_0_pub.publish(self.currentServoPosition_0)
        if index1_data:
            self.currentServoLoad_1 = index1_data.load
            self.currentServoPosition_1 = index1_data.angle
            self.currentServoLoad_1_pub.publish(self.currentServoLoad_1)
            self.currentServoPosition_1_pub.publish(self.currentServoPosition_1)

    def run_open_sequence(self):
        # Open sequence: vertical -> horizontal
        rospy.sleep(1.0)
        self.enable_servo_torque_safely(1)
        self.enable_servo_torque_safely(0)
        self.targetTorqueReachedFlag_1 = False
        self.OpenFlag_1 = True
        rospy.set_param('OpenFlag_1', self.OpenFlag_1)

        while not rospy.is_shutdown():
            self.check_subscription()
            self.step_servo1("open")
            if self.targetTorqueReachedFlag_1:
                # print("\033[1;32m[Msg] Servo 1 open torque reached. \033[0m")
                rospy.loginfo(("Servo 1 open torque reached."))
                break
            self.rate.sleep()

        self.targetTorqueReachedFlag_0 = False
        self.OpenFlag_0 = True
        rospy.set_param('OpenFlag_0', self.OpenFlag_0)

        while not rospy.is_shutdown():
            self.check_subscription()
            self.step_servo0("open")
            if self.targetTorqueReachedFlag_0:
                # print("\033[1;32m[Msg] Servo 0 open torque reached. \033[0m")
                rospy.loginfo(("Servo 0 open torque reached."))
                break
            self.rate.sleep()

    def run_close_sequence(self):
        # Close sequence: horizontal -> vertical
        rospy.sleep(1.0)
        self.enable_servo_torque_safely(0)
        self.enable_servo_torque_safely(1)
        self.targetTorqueReachedFlag_0 = False
        self.OpenFlag_0 = False
        rospy.set_param('OpenFlag_0', self.OpenFlag_0)

        while not rospy.is_shutdown():
            self.check_subscription()
            self.step_servo0("close", step=self.servoMoveRange_0_close)
            if self.targetTorqueReachedFlag_0:
                print("\033[1;32m[Msg] Servo 0 close torque reached. \033[0m")
                break
            self.rate.sleep()

        self.targetTorqueReachedFlag_1 = False
        self.OpenFlag_1 = False
        rospy.set_param('OpenFlag_1', self.OpenFlag_1)

        while not rospy.is_shutdown():
            self.check_subscription()
            self.step_servo1("close")
            if self.currentServoLoad_0 > 5:
                self.step_servo0("close", step=self.servoMoveRange_0_close)
            if self.targetTorqueReachedFlag_1:
                print("\033[1;32m[Msg] Servo 1 close torque reached. \033[0m")
                break
            self.rate.sleep()

    def run_init_sequence(self):
        # Initial state: servo0 torque off, servo1 torque on and adjust to -50..-20, then torque off servo1
        self.sync_servo_target_to_current(1)
        cmd = ServoTorqueCmd()
        cmd.index = [0, 1]
        cmd.torque_enable = [0, 1]
        self.torque_pub.publish(cmd)

        while not rospy.is_shutdown():
            self.check_subscription()
            if -120 <= self.currentServoLoad_1 <= -80:
                print("\033[1;32m[Msg] Servo 1 load set to -120..-80. \033[0m")
                break

            if -120 <= self.currentServoLoad_1 <= -80:
                # Hold position while waiting for stable in-range time
                self.targetServoPosition_1 = int(self.currentServoPosition_1)
            elif self.currentServoLoad_1 > -80:
                self.targetServoPosition_1 = int(self.currentServoPosition_1 - self.servoMoveRange_1_init)
            elif self.currentServoLoad_1 < -120:
                self.targetServoPosition_1 = int(self.currentServoPosition_1 + self.servoMoveRange_1_init)
            self.sendGraspingCommand(1)
            self.rate.sleep()

        self.set_servo_torque(1, False)
        print("\033[1;32m[Msg] Torque off for servo 0 and 1. \033[0m")

    def main(self):
        # Topic-driven start for open/close/init
        while not rospy.is_shutdown():
            if self.pending_command:
                command = self.pending_command
                self.pending_command = None
                self.is_busy = True
                if command == "quit":
                    rospy.loginfo("Quit command received.")
                    rospy.signal_shutdown("")
                    break
                elif command == "open":
                    rospy.loginfo("Starting open sequence.")
                    self.run_open_sequence()
                elif command == "close":
                    rospy.loginfo("Starting close sequence.")
                    self.run_close_sequence()
                elif command == "init":
                    rospy.loginfo("Starting init sequence.")
                    self.run_init_sequence()
                self.is_busy = False
            self.rate.sleep()

            self.limitLoadInf_0_pub.publish(self.limitLoadInf_0)
            self.limitLoadSup_0_pub.publish(self.limitLoadSup_0)

            self.limitLoadInf_1_open_pub.publish(self.limitLoadInf_1_open)
            self.limitLoadSup_1_open_pub.publish(self.limitLoadSup_1_open)

            self.limitLoadInf_1_close_pub.publish(self.limitLoadInf_1_close)
            self.limitLoadSup_1_close_pub.publish(self.limitLoadSup_1_close)

        rospy.loginfo("Exiting main loop.")

if __name__ == "__main__":
    try:
        auto_grasping = AutoGrasping()
        auto_grasping.main()
        rospy.spin()
    except rospy.ROSInterruptException:
        sys.exit(1)
    except KeyError:
        rospy.logerr("Error: OpenFlag_0 or OpenFlag_1 not found!")
        sys.exit(1)
