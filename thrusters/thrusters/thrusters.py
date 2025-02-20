import subprocess
from control_panel.control_panel import create_control_panel, ControlPanelItem as CPI #this is a package in PL repo\
import numpy as np
import pandas as pd
from rclpy.node import Node
from msg_types.msg import PWMs
import rclpy

import can

# fmt: off
# Pin numbers of each thruster
thruster_idxs = {
    # "FL": 3,
    # "FR": 1,
    # "RL": 4,
    # "RR": 0,
    # "ML": 5,
    # "MR": 2,
    # "MM": 6,
    # 15/01/24
    # "FL": 6,
    # "FR": 4,
    # "RL": 5,
    # "RR": 3,
    # "ML": 1,
    # "MR": 0,
    # "MM": 2,
    # 15/01/24 2nd attempt
    # "FL": 6,
    # "FR": 5,
    # "RL": 2,
    # "RR": 0,
    # "ML": 4,
    # "MR": 3,
    # "MM": 1,
    # 20/01/24 1st attempt
    "FL": 6,
    "FR": 5,
    "RL": 2,
    "RR": 0,
    "ML": 4,
    "MR": 3,
    "MM": 1,
}

# -1 means thruster is reversed.
thruster_reverse = {
    # "FL": -1,
    # "FR": 1,
    # "RL": 1,
    # "RR": -1,
    # "ML": 1,
    # "MR": -1,
    # "MM": -1,
    # 150125 pooltest
    # "FL": -1,
    # "FR": -1,
    # "RL": 1,
    # "RR": -1,
    # "ML": 1,
    # "MR": -1,
    # "MM": -1,
    # 100225 pooltest
    "FL": -1,
    "FR": 1,
    "RL": -1,
    "RR": 1,
    "ML": -1,
    "MR": 1,
    "MM": 1,

}

values = {
    'FL': CPI(value=10, maximum=100),
    'FR': CPI(value=10, maximum=100),
    'RL': CPI(value=10, maximum=100),
    'RR': CPI(value=10, maximum=100),
    'ML': CPI(value=8, maximum=100),
    'MR': CPI(value=10, maximum=100),
    'MM': CPI(value=10, maximum=100),
}
#create_control_panel("thruster biases", values)

thruster_biases = {'FL':values['FL'].value/100,   # Front Left
                    'FR': values['FR'].value/100,    # Front Right
                    'RL': values['RL'].value/100,    # Rear Left
                    'RR': values['RR'].value/100,   # Rear Right
                    'ML': values['ML'].value/100,    # Middle Left
                    'MR': values['MR'].value/100,    # Middle Right
                    'MM': values['MM'].value/100,}  # Middle Middle
# fmt: on


class ThrusterControl(Node):
    def __init__(self):
        super().__init__('thruster_control_node')

        self.thrustValues = [127, 127, 127, 127, 127, 127, 127]
        self.bus = can.interface.Bus(
            interface="socketcan", channel="can0", bitrate=500000
        )

        self.subscription_goal = self.create_subscription(
            PWMs,
            '/controls/PWMs',
            self.setThrusters,
            10
        )

    def correctPWMS(self):
        """
        thrustValues are in the FL-FR-ML-MR-RL-RR order. Set:
            > 127 to move in principal directions.
            < 127 to move in opposite to principal directions.

        correctedPWMs account for different pin orderings and
        reversed thrusters.
        """
        correctedPWMs = [127, 127, 127, 127, 127, 127, 127]
        for (thruster, thrusterPin), thrustValue, bias in zip(
            thruster_idxs.items(), self.thrustValues, thruster_biases
        ):
            # If thruster is not reversed,
            if thruster_reverse[thruster] > 0:
                correctedPWMs[thrusterPin] = thrustValue
            else:
                correctedPWMs[thrusterPin] = 255 - thrustValue
            #correctedPWMs[thrusterPin] = round(max(min(     (127 + (thruster_biases[thruster] * (thrustValue-127)  ))  , 255), 0))

        return correctedPWMs

    def setThrusters(self, msg):
        self.thrustValues = [msg.one, msg.two, msg.three, msg.four, msg.five, msg.six, msg.seven]
        self.waitTillSend()

    def waitTillSend(self):
        max_tries = 5
        tries = 0
        while tries < max_tries:
            try:
                # With statement needed to ensure that bus is closed properly
                # https://stackoverflow.com/questions/73386339/close-bus-in-python-can
                correctedPWMs = self.correctPWMS()
                t_msg = can.Message(
                    arbitration_id=0, data=correctedPWMs, is_extended_id=False
                )
                self.bus.send(t_msg)
                print(f"Sent PWMs: {correctedPWMs} to CAN.")
                return

            except can.CanError as error:
                tries += 1
                print(error)
                print("Message not sent.")
                # if logger:
                #     logger.error(f"ThrusterControl: Message not sent: {error}")
                # Commented out flush buffer to check overload
                # self.flush_buffer()
                # print("Flushed buffer.")
        # if logger: 
        #     logger.error(f"ThrusterControl: {max_tries} reached, abort sending message.")
        self.get_logger().info(f"ThrusterControl: {max_tries} reached, abort sending message.")


    def killThrusters(self):
        print("Killing thrusters...")
        self.setThrusters([127, 127, 127, 127, 127, 127, 127])
        print("Killed thrusters.")

    def spinSingle(self, idx, value):
        self.thrustValues[idx] = value
        self.waitTillSend()

    def flush_buffer(self):
        ##########################################
        #    DANGER: Please change this soon.    #
        ##########################################

        subprocess.call("./restartCan.sh", shell=True)
        self.bus = can.interface.Bus(
            interface="socketcan", channel="can0", bitrate=500000
        )

        ###################################
        #    The following don't work.    #
        ###################################

        ## Flush CAN bus.
        # self.bus.flush_tx_buffer()

        ## Shutdown and create new bus instance.
        # self.bus.shutdown()
        # self.bus = can.interface.Bus(
        #     interface="socketcan", channel="can0", bitrate=500000
        # )

        ## Read all the messages.
        # with self.bus as bus:
        #     for msg in bus:
        #         continue

def main(args=None):
    rclpy.init(args=args)
    thruster_control_node = ThrusterControl()
    try:
        while True:
            rclpy.spin(thruster_control_node)
    finally:
        thruster_control_node.killThrusters()
        thruster_control_node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()