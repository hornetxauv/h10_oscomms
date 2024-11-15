import time

from thrusters import ThrusterControl, thruster_idxs

thrusterControl = ThrusterControl()

# Outside water
thrustMag = 140
# # Inside water
# thrustMag = 170

duration = 5

try:
    # Spin forward one by one.
    for i, thruster_name in enumerate(thruster_idxs.keys()):
        thrusterControl.spinSingle(i, thrustMag)
        print(f"Spinning {thruster_name}...\n")
        time.sleep(duration)
        thrusterControl.killThrusters()
        time.sleep(0.5

    # Spin backward one by one.
    for i, thruster_name in enumerate(thruster_idxs.keys()):
        thrusterControl.spinSingle(i, 255 - thrustMag)
        print(f"Spinning {thruster_name}...\n")
        time.sleep(duration)
        thrusterControl.killThrusters()
        time.sleep(0.5)

except KeyboardInterrupt:
    thrusterControl.killThrusters()

finally:
    thrusterControl.killThrusters()
