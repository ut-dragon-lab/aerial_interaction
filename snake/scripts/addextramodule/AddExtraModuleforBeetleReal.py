#!/usr/bin/env python

import os, tf, math, rospy
import xml.etree.ElementTree as ET
from geometry_msgs.msg import Transform, Quaternion, Pose, Point
from aerial_robot_model.srv import AddExtraModule, AddExtraModuleRequest
from spinal.msg import ServoControlCmd 

def euler_to_quaternion(roll, pitch, yaw):
    q = tf.transformations.quaternion_from_euler(roll, pitch, yaw)
    return Quaternion(x=q[0], y=q[1], z=q[2], w=q[3])

def spawn_object(module_name, model_path, link_name):        
    try:
        tree = ET.parse(model_path)
        root = tree.getroot()
        pose_element = root.find('.//pose')
        
        if pose_element is not None:
            pose_values = list(map(float, pose_element.text.split()))
            x, y, z = pose_values[0:3]
            roll, pitch, yaw = pose_values[3:6]
    
            pose = Point(x, y, z)
            orientation = euler_to_quaternion(roll, pitch, yaw)
            initial_pose = Pose(pose, orientation)
            print(f"\033[1;32m[Msg] Initial pose set.\033[0m")

        else:
            print("\033[1;91m[Warn] No <pose> tag found in the model file.\033[0m")
            return None, None, None

        inertia_element = root.find('.//inertia')
        if inertia_element is not None:
            inertia = {}
            inertia['m'] = float(inertia_element.find('./mass').text)
            inertia['ixx'] = float(inertia_element.find('./ixx').text)
            inertia['ixy'] = float(inertia_element.find('./ixy').text)
            inertia['ixz'] = float(inertia_element.find('./ixz').text)
            inertia['iyy'] = float(inertia_element.find('./iyy').text)
            inertia['iyz'] = float(inertia_element.find('./iyz').text)
            inertia['izz'] = float(inertia_element.find('./izz').text)

            print(f"\033[1;32m[Msg] Inertia set.\033[0m")
        else:
            print("\033[1;91m[Warn] No <inertia> tag found in the model file.\033[0m")
            return None, None, None
            
        config = {
            'module_name': module_name,
            'transform': Transform(translation=pose, rotation=orientation),
            'inertia': inertia
        }

        with open(model_path, 'r') as model_file:
            model_sdf = model_file.read()

        return model_sdf, config

    except rospy.ServiceException as e:
        rospy.logerr("\033[1;91m[Warn] Service call failed: %s\033[0m" % e)
        return None, None, None

def call_add_extra_module(action, link_name, config):
    rospy.wait_for_service('/beetle1/add_extra_module')
    try:
        add_extra_module = rospy.ServiceProxy('/beetle1/add_extra_module', AddExtraModule)

        request = AddExtraModuleRequest()
        request.action = action
        request.module_name = config['module_name']
        request.parent_link_name = link_name
        request.transform = config['transform']
        request.inertia.m = config['inertia']['m']
        request.inertia.ixx = config['inertia']['ixx']
        request.inertia.ixy = config['inertia']['ixy']
        request.inertia.ixz = config['inertia']['ixz']
        request.inertia.iyy = config['inertia']['iyy']
        request.inertia.iyz = config['inertia']['iyz']
        request.inertia.izz = config['inertia']['izz']

        response = add_extra_module(request)
        if response.status:
            print("\033[1mModule processed successfully!\033[0m")
            return True
        else:
            print("\033[1mFailed to process the module!\033[0m")
            return False
    except rospy.ServiceException as e:
        print("\033[1mService call failed!\033[0m")
        return False

def send_openhand_command():
    pub = rospy.Publisher('/servo/target_states', ServoControlCmd, queue_size=10)
    rospy.sleep(0.5)
    cmd = ServoControlCmd()
    cmd.index = [1]
    cmd.angles = [4500]
    pub.publish(cmd)
    print("\033[1;32m[Msg] Open hand command sent.\033[0m")

def main():
    rospy.init_node('add_module_client')
    rospy.sleep(1)

    link_name = "dummy_gripper_2"
    print("\033[1mEnter the module name: \033[0m")

    try:
        module_name = input().strip().lower()
    except KeyboardInterrupt:
        rospy.loginfo("Interrupted from keyboard.")
        rospy.signal_shutdown("")

    model_path = f'/home/iida/ros/jsk_aerial_robot_ws/src/jsk_aerial_robot/robots/beetle/models/real/{module_name}_model.sdf'
    if not os.path.exists(model_path):
        print(f"\033[1;91m[Warning] '{module_name}' model not found. Please enter a valid module name.\033[0m")
        return

    model_sdf, config = spawn_object(module_name, model_path, link_name)
    if model_sdf is None:
        return

    while True:
        print("\033[1mEnter add or delete: \033[0m")

        try:
            operation = input().strip().lower()
        except KeyboardInterrupt:
            rospy.loginfo("Interrupted from keyboard.")
            rospy.signal_shutdown("")
            break
        
        if operation == "add":
            action = 1
            if call_add_extra_module(action, link_name, config):
                print(f"\033[1;32m[Msg] {module_name} model added successfully!\033[0m")
            else:
                print("\033[1;91m[Error] Failed to add module.\033[0m")
            break

        elif operation == "delete":
            action = -1
            # send_openhand_command()
            if call_add_extra_module(action, link_name, config):
                print(f"\033[1;32m[Msg] {module_name} model deleted successfully!\033[0m")
            else:
                print("\033[1;91m[Error] Failed to delete module.\033[0m")
            break

        else:
            print("\033[1;91mInvalid operation. Please enter 'add' or 'delete'.\033[0m")

if __name__ == "__main__":
    main()
