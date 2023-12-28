import time

from thrusters import ThrusterControl

thrusterControl = ThrusterControl()
thrustMag = 140
duration = 3

try:
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

except KeyboardInterrupt:
    thrusterControl.killThrusters()

finally:
    thrusterControl.killThrusters()
