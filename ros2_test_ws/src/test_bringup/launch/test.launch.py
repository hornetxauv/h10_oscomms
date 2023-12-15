from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    ld = LaunchDescription()
    
    sub = Node(
        package="sub",
        executable="test_subscriber",
        name="sub"
    )
    sub2 = Node(
        package="sub",
        executable="check",
        name="sub2"
    )
    pub = Node(
        package="sub",
        executable="publisher",
        name="pub"
    )

    ld.add_action(sub)
    ld.add_action(sub2)
    ld.add_action(pub)
    
    return ld