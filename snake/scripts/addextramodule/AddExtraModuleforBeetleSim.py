#!/usr/bin/env python

import os, tf, math, rospy
import xml.etree.ElementTree as ET
from std_msgs.msg import Bool
from geometry_msgs.msg import Transform, Quaternion, Pose, Point
from std_srvs.srv import SetBool
from aerial_robot_model.srv import AddExtraModule, AddExtraModuleRequest
from gazebo_msgs.srv import SpawnModel, DeleteModel

def euler_to_quaternion(roll, pitch, yaw):
    q = tf.transformations.quaternion_from_euler(roll, pitch, yaw)
    return Quaternion(x = q[0], y = q[1], z = q[2], w = q[3])

def spawn_object(module_name, model_path, link_name):
    if not os.path.exists(model_path):
        rospy.logerr("[spawn_object] model_path does not exist: %s", model_path)
        return None, None, None

    try:
        with open(model_path, 'r') as f:
            model_sdf = f.read()
    except Exception as e:
        rospy.logerr("[spawn_object] Failed to read model file: %s (%s)", model_path, str(e))
        return None, None, None

    try:
        tree = ET.parse(model_path)
        root = tree.getroot()
    except Exception as e:
        rospy.logerr("[spawn_object] XML parse failed: %s (%s)", model_path, str(e))
        return None, None, None

    pose_element = root.find('.//pose')
    if pose_element is None or pose_element.text is None:
        rospy.logwarn("[spawn_object] No <pose> tag found. Use zero pose.")
        x = y = z = 0.0
        roll = pitch = yaw = 0.0
    else:
        try:
            pose_values = [float(v) for v in pose_element.text.split()]
            # pose may be 6 values. If not, pad.
            while len(pose_values) < 6:
                pose_values.append(0.0)
            x, y, z, roll, pitch, yaw = pose_values[:6]
        except Exception as e:
            rospy.logerr("[spawn_object] Failed to parse <pose>: '%s' (%s). Use zero pose.",
                         pose_element.text, str(e))
            x = y = z = 0.0
            roll = pitch = yaw = 0.0

    orientation = euler_to_quaternion(roll, pitch, yaw)
    initial_pose = Pose(position=Point(x, y, z), orientation=orientation)

    rospy.loginfo("[spawn_object] Initial pose: xyz=(%.3f, %.3f, %.3f), rpy=(%.3f, %.3f, %.3f)",
                  x, y, z, roll, pitch, yaw)

    inertia = {
        'm': None,
        'ixx': None, 'ixy': 0.0, 'ixz': 0.0,
        'iyy': None, 'iyz': 0.0,
        'izz': None
    }

    mass_element = root.find('.//inertial/mass')
    inertia_element = root.find('.//inertial/inertia')
    if inertia_element is None:
        inertia_element = root.find('.//inertia')

    try:
        if mass_element is not None and mass_element.text is not None:
            inertia['m'] = float(mass_element.text)
        else:
            mass_value = root.find('.//inertial/mass/value')
            if mass_value is not None and mass_value.text is not None:
                inertia['m'] = float(mass_value.text)

        if inertia_element is not None:
            def _get(tag, default=None):
                el = inertia_element.find('./' + tag)
                if el is None or el.text is None:
                    return default
                return float(el.text)

            inertia['ixx'] = _get('ixx')
            inertia['ixy'] = _get('ixy', 0.0)
            inertia['ixz'] = _get('ixz', 0.0)
            inertia['iyy'] = _get('iyy')
            inertia['iyz'] = _get('iyz', 0.0)
            inertia['izz'] = _get('izz')
        else:
            rospy.logwarn("[spawn_object] No <inertia> tag found in the model file.")
    except Exception as e:
        rospy.logerr("[spawn_object] Failed to parse inertia/mass: %s", str(e))
        return None, None, None

    missing = []
    if inertia['m'] is None:   missing.append('mass(m)')
    if inertia['ixx'] is None: missing.append('ixx')
    if inertia['iyy'] is None: missing.append('iyy')
    if inertia['izz'] is None: missing.append('izz')

    if missing:
        rospy.logerr("[spawn_object] Missing required inertial fields: %s", ", ".join(missing))
        rospy.logerr("[spawn_object] Ensure SDF has <inertial><mass> and <inertia><ixx/iyy/izz>.")
        return None, None, None

    rospy.loginfo("[spawn_object] Inertia loaded: m=%.6f ixx=%.6f ixy=%.6f ixz=%.6f iyy=%.6f iyz=%.6f izz=%.6f",
                  inertia['m'], inertia['ixx'], inertia['ixy'], inertia['ixz'],
                  inertia['iyy'], inertia['iyz'], inertia['izz'])

    config = {
        'module_name': module_name,
        'transform': Transform(translation=Point(x, y, z), rotation=orientation),
        'inertia': inertia
    }

    return model_sdf, initial_pose, config

def delete_object(model_name):
    rospy.wait_for_service('/gazebo/delete_model')
    try:
        delete_model_service = rospy.ServiceProxy('/gazebo/delete_model', DeleteModel)
        response = delete_model_service(model_name)
        if response.success:
            print(f"\033[1;32m[Msg] {model_name} has been deleted successfully!\033[0m")
        else:
            print(f"\033[1;91m[Warning] Failed to delete {model_name}.\033[0m")
    except rospy.ServiceException as e:
        print(f"\033[1;91m[Warning] Service call failed: {e}\033[0m")

def call_add_extra_module(action, link_name, config):
    rospy.wait_for_service('/dragon/add_extra_module')
    try:
        add_extra_module = rospy.ServiceProxy('/dragon/add_extra_module', AddExtraModule)

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
            print("""
########################################################################################
\033[1mModule added/deleted successfully!\033[0m
########################################################################################
            """)
            return True
        else:
            print("""
########################################################################################
\033[1mFailed to add/delete module!\033[0m
########################################################################################
            """)
            return False
    except rospy.ServiceException as e:
        rospy.logerr("Service call failed: %s", str(e))
        print("""
########################################################################################
\033[1mService call failed!: \033[0m
########################################################################################
        """)
        return False

pub = rospy.Publisher('/dragon/docking_cmd', Bool, queue_size=10)

def send_docking_command(is_docking):
    rospy.sleep(0.5)
    pub.publish(is_docking)
    rospy.sleep(0.5)

def main():
    rospy.init_node('add_module_client')
    rospy.sleep(1)

    link_name = "dummy_mouth"

    while True:
        print("\033[1mEnter the module name: \033[0m")

        module_name = input().strip().lower()
        model_path = f'/home/kyoji/ros/human_robot_interaction_ws/src/aerial_interaction/snake/models/sim/{module_name}_model.sdf'
        if not os.path.exists(model_path):
            print(f"\033[1;91m[Warning] '{module_name}' model not found. Please enter a valid module name.\033[0m")
            continue
        else:
            model_sdf, initial_position, config = spawn_object(module_name, model_path, link_name)
            if model_sdf is None:
                continue
            break

    while True:
        print("\033[1mEnter add or delete: \033[0m")
        operation = input().strip().lower()
        if operation == "add":
            action = 1
            send_docking_command(True)
            try:
                spawn_model = rospy.ServiceProxy('/gazebo/spawn_sdf_model', SpawnModel)
                spawn_model(module_name, model_sdf, 'obstacle_namespace', initial_position, link_name)
                if call_add_extra_module(action, link_name, config):
                    print(f"\033[1;32m[Msg] {module_name} model spawned successfully!\033[0m")
                    print("\033[1;32m[Msg] Attachment on!\033[0m")
                    break
                else:
                    print("\033[1;91m[Error] Failed to add module. Please try again.\033[0m")
                    continue
            except rospy.ServiceException as e:
                print(f"\033[1;91m[Warn] Spawn service call failed: {e}\033[0m")
                continue

        elif operation == "delete":
            action = -1
            send_docking_command(False)
            print("\033[1;32m[Msg] Attachment off!\033[0m")
            if call_add_extra_module(action, link_name, config):
                rospy.sleep(2)
                try:
                    delete_object(module_name)
                    break
                except rospy.ServiceException as e:
                    rospy.logerr("\033[1;91m[Warn] Despawn service call failed: %s\033[0m" % e)
                    continue
        else:
            print("\033[1;91mInvalid operation. Please enter 'add' or 'delete'.\033[0m")

if __name__ == "__main__":
    main()
