import time

from thrusters import ThrusterControl

thrusterControl = ThrusterControl()
thrustMag = 170
duration = 5

# Spin all forward.
thrusterControl.setThrusters([thrustMag] * 6)
time.sleep(duration)
thrusterControl.killThrusters()
time.sleep(0.5)

# Spin all backward.
thrusterControl.setThrusters([255 - thrustMag] * 6)
time.sleep(duration)
thrusterControl.killThrusters()
time.sleep(0.5)
