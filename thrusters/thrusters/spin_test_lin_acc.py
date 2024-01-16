import time

from thrusters.thrusters import ThrusterControl
from controls_core.thruster_allocator import ThrustAllocator

thrusterControl = ThrusterControl()
thrustAllocator = ThrustAllocator()

lin_acc = 5.0
ang_acc = 0.0
duration = 10

linear_accelerations = [lin_acc, lin_acc, lin_acc]
angular_accelerations = [ang_acc, ang_acc, ang_acc]

thrusterValues = thrustAllocator.getThrustPWMs(linear_accelerations, angular_accelerations)

try:
    thrusterControl.setThrusters(thrusterValues)
    time.sleep(duration)
    thrusterControl.killThrusters()
    time.sleep(0.5)
except KeyboardInterrupt:
    thrusterControl.killThrusters()
finally:
    thrusterControl.killThrusters()
