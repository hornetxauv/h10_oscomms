import time

import can

# fmt: off
# Pin numbers of each thruster
thruster_idxs = {
    "FL": 1,
    "FR": 3,
    "ML": 5,
    "MR": 2,
    "RL": 4,
    "RR": 0
}

# -1 means thruster is reversed.
thruster_reverse = {
    "FL": -1,
    "FR": 1,
    "ML": 1,
    "MR": -1,
    "RL": 1,
    "RR": -1
}
# fmt: on


class ThrusterControl:
    def __init__(self):
        self.thrustValues = [127, 127, 127, 127, 127, 127]
        self.bus = can.interface.Bus(
            interface="socketcan", channel="can0", bitrate=500000
        )

    def correctPWMS(self):
        """
        thrustValues are in the FL-FR-ML-MR-RL-RR order. Set:
            > 127 to move in principal directions.
            < 127 to move in opposite to principal directions.

        correctedPWMs account for different pin orderings and
        reversed thrusters.
        """
        correctedPWMs = [127, 127, 127, 127, 127, 127]
        for (thruster, thrusterPin), thrustValue in zip(
            thruster_idxs.items(), self.thrustValues
        ):
            # If thruster is not reversed,
            if thruster_reverse[thruster] > 0:
                correctedPWMs[thrusterPin] = thrustValue
            else:
                correctedPWMs[thrusterPin] = 255 - thrustValue

        return correctedPWMs

    def setThrusters(self, thrustValues):
        self.thrustValues = thrustValues
        self.waitTillSend()

    def waitTillSend(self):
        while True:
            try:
                # With statement needed to ensure that bus is closed properly
                # https://stackoverflow.com/questions/73386339/close-bus-in-python-can
                correctedPWMs = self.correctPWMS()
                t_msg = can.Message(
                    arbitration_id=0, data=correctedPWMs, is_extended_id=False
                )
                self.bus.send(t_msg)
                print(f"Sent PWMs: {correctedPWMs} to CAN.")
                break

            except can.CanError as error:
                print(error)
                print("Message not sent.")

    def killThrusters(self):
        print("Killing thrusters...")
        self.setThrusters([127, 127, 127, 127, 127, 127])
        print("Killed thrusters.")

    def spinSingle(self, idx, value):
        self.thrustValues[idx] = value
        self.waitTillSend()
