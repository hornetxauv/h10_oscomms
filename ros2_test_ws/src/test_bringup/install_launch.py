import robot_upstart

j = robot_upstart.Job(name="test_ros")
j.symlink = True

j.add(package="test_bringup", filename="launch/test.launch.py")

j.install()