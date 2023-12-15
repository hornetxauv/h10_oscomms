from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    ld = LaunchDescription()
    
    acoustic = Node(
        package="acoustic_sensor",
        executable="publisher",
        name="acoustic"
    )
    depth = Node(
        package="depth_sensor",
        executable="publisher",
        name="depth"
    )
    quat = Node(
        package="imu_sensor",
        executable="publisher_quat",
        name="quaternion"
    )
    accel_inter = Node(
        package="imu_sensor",
        executable="publisher_xyz",
        name="accel_inter"
    )
    final_accel = Node(
        package="imu_sensor",
        executable="publisher_accel",
        name="final_accel"
    )
    
    ld.add_action(acoustic)
    ld.add_action(depth)
    ld.add_action(quat)
    ld.add_action(accel_inter)
    ld.add_action(final_accel)
    
    return ld