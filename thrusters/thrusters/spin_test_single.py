import time

from thrusters import ThrusterControl

thrusterControl = ThrusterControl()
thrustMag = 170
duration = 4

# Spin forward one by one.
for i in range(6):
    thrusterControl.spinSingle(i, thrustMag)
    time.sleep(duration)
    thrusterControl.killThrusters()
    time.sleep(0.5)

# Spin backward one by one.
for i in range(6):
    thrusterControl.spinSingle(i, 255 - thrustMag)
    time.sleep(duration)
    thrusterControl.killThrusters()
    time.sleep(0.5)
