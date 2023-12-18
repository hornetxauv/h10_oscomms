from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    ld = LaunchDescription()
    
    acoustic = Node(
        package="acoustic_sensor",
        executable="publisher_acoustic",
        name="acoustic"
    )
    depth = Node(
        package="depth_sensor",
        executable="publisher_depth",
        name="depth"
    )
    quat = Node(
        package="imu_sensor",
        executable="publisher_quat",
        name="quaternion"
    )
    accel_xy = Node(
        package="imu_sensor",
        executable="publisher_xy",
        name="accel_xy"
    )
    accel_z = Node(
        package="imu_sensor",
        executable="publisher_z",
        name="accel_z"
    )
    final_accel = Node(
        package="imu_sensor",
        executable="publisher_accel",
        name="final_accel"
    )
    imu = Node(
        package="imu",
        executable="imu",
        name="imu"
    )

    # add the other nodes here then build all at once    
    ld.add_action(quat)
    ld.add_action(accel_xy)
    ld.add_action(accel_z)
    ld.add_action(final_accel)
    ld.add_action(acoustic)
    ld.add_action(depth)
    ld.add_action(imu)
    
    return ld
