import time

from thrusters import ThrusterControl

thrusterControl = ThrusterControl()
thrustMag = 170

# Spin forward one by one.
currIdx = 0
while currIdx < 6:
    thrusterControl.spinSingle(currIdx, thrustMag)
    time.sleep(2)
    currIdx += 1
    thrusterControl.killThrusters()
    time.sleep(0.5)

# Spin backward one by one.
currIdx = 0
while currIdx < 6:
    thrusterControl.spinSingle(currIdx, 255 - thrustMag)
    time.sleep(2)
    currIdx += 1
    thrusterControl.killThrusters()
    time.sleep(0.5)
