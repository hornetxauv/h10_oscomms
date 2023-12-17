import robot_upstart

j = robot_upstart.Job(name="h9")
j.symlink = True

j.add(package="bring_up", filename="launch/nodes.launch.py")

j.install()