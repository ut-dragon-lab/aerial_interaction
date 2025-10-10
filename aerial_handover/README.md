## Handover between human and flying robots

### simulation mode

#### Description

VR in gazebo system with mocap system.

#### Command

```bash
 roslaunch aerial_handover task.launch rm:=false sim:=true headless:=false robot_name:=mini_quadrotor
```

- `robot_name`: can be any types of robot supported by `jsk_aerial_robot`, like `dragon`
- two topics (`/eye/mocap/pose` and `/wrist/mocap/pose`) subscribed from mocap system.

