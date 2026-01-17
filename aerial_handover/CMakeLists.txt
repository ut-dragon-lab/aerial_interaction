cmake_minimum_required(VERSION 3.0.2)
project(aerial_handover)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
)

catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES aerial_handover
#  CATKIN_DEPENDS roscpp rospy
#  DEPENDS system_lib
)

include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)

## Install Python scripts
catkin_install_python(PROGRAMS
  scripts/set_hand_pose_gazebo.py
  scripts/interactive_marker.py
  scripts/pose_transformer.py
  scripts/dragon_handover_nav.py
  scripts/dragon_root_pose_publisher.py
  DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)

