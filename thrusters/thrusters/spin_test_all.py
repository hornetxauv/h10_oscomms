import time

from thrusters import ThrusterControl

thrusterControl = ThrusterControl()

# 140 is minimum or close to it to test
forwardThrustMag = 20
upthrustMag = 20
ZERO = 127
duration = 600

# thrusterValues = [170, 172, ZERO, ZERO, ZERO, ZERO]
# thrusterValues = [ZERO, ZERO, ZERO, ZERO, 172, 170]
# thrusterValues = [ZERO, ZERO, 153, 150, ZERO, ZERO]
# thrusterValues = [170, 172, 101, 104, 172, 170]
thrusterValues = [
    ZERO + forwardThrustMag,
    ZERO + forwardThrustMag,
    ZERO + forwardThrustMag,
    ZERO + forwardThrustMag,
    ZERO + upthrustMag,
    ZERO + upthrustMag,
    ZERO + upthrustMag,
]

print("start")
try:
    # Spin all forward.
    thrusterControl.setThrusters(thrusterValues)
    time.sleep(duration)
    thrusterControl.killThrusters()
    time.sleep(0.5)

    # # Spin all backward.
    # thrusterControl.setThrusters([255 - thrustMag] * 6)
    # time.sleep(duration)
    # thrusterControl.killThrusters()
    # time.sleep(0.5)

except KeyboardInterrupt:
    thrusterControl.killThrusters()

finally:
    thrusterControl.killThrusters()
