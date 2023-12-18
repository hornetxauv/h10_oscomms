import can

bus = can.interface.Bus(interface="socketcan", channel="can0", bitrate=500000)


class ThrusterControl:
    def __init__(self):
        self.thrustValues = [127, 127, 127, 127, 127, 127]

    def setThrusters(self, thrustValues):
        self.thrustValues = thrustValues
        self.waitTillSend()

    def waitTillSend(self):
        while True:
            try:
                t_msg = can.Message(
                    arbitration_id=0, data=self.thrustValues, is_extended_id=False
                )
                bus.send(t_msg)
                print(f"Sent thrust values: {self.thrustValues} to CAN.")
                break

            except can.CanError as error:
                print(error)
                print("Message not sent.")

    def killThrusters(self):
        self.setThrusters([127, 127, 127, 127, 127, 127])

    def spinSingle(self, idx, value):
        self.thrustValues[idx] = value
        self.waitTillSend()
