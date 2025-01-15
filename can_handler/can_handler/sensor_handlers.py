import numpy as np

from abc import ABC, abstractmethod
from typing import List, Union

from std_msgs.msg import Float32, Header
from geometry_msgs.msg import Vector3
from msg_types.msg import IMU
from rclpy.node import Node
from rclpy.publisher import Publisher

import struct
import binascii

from control_panel.control_panel import create_control_panel, ControlPanelItem as CPI #this is a package in PL repo

values = {
    'depth offset': CPI(value=0.14, maximum=5.0, minimum=0.01, multiplier=100),
}
# can't seem to use simultaneously with thruster biases control panel... sometimes. idk.
create_control_panel("sensor handler", values)

def decode(data, num_bytes):
    """
    data: bytearray
    num_bytes: Number of bytes for each value
    """
    # decoded_data = []
    # for i in range(0, len(data), num_bytes):
    #     packet = data[i : i + num_bytes]
    #     decoded_packet = float(int.from_bytes(packet, "little", signed=True))
    #     decoded_data.append(decoded_packet)
    # return decoded_data
    # print("DATA:", data)

    decoded_data = []
    for i in range(0, 8, num_bytes):
        packet = struct.unpack_from("<f", data, i)
        decoded_data.append(packet[0])
    return decoded_data


class SensorHandler(ABC):
    def __init__(self, node: Node, log: bool):
        self.node = node
        self.log = log

    @abstractmethod
    def process_data(self, data, msg_id):
        pass
    
    @property
    @abstractmethod
    def message(self):
        pass

    @property
    @abstractmethod
    def log_info(self):
        pass

    @property
    def publisher(self) -> Union[Publisher, None]:
        return self._publisher
    
    def publish(self):
        msg = self.message()
        print(msg)
        if msg is not None:
            self.publisher.publish(msg)
            if self.log:
                self.node.get_logger().info(self.log_info())


class IMUHandler(SensorHandler):
    def __init__(self, node: Node, log: bool):
        super().__init__(node, log)
        self.imu_msg = IMU()
        self.counter = 0
        self._publisher = self.node.create_publisher(IMU, "/sensors/imu", 10)

    # def process_data(self, data: Union[int, tuple[int, int]], msg_id=0):
    def process_data(self, data, msg_id=0):
        # Pitch & Roll
        if msg_id == 19:
            self.imu_msg.pitch, self.imu_msg.roll = data
        # Yaw
        elif msg_id == 20:
            # self.imu_msg.yaw = data
            self.imu_msg.yaw = -(data-values["depth offset"].value) #! recalib
    
    def message(self) -> IMU:
        # Fill in the header
        self.imu_msg.header = Header()
        self.imu_msg.header.frame_id = str(self.counter)
        self.counter += 1
        return self.imu_msg

    def log_info(self) -> str:
        return f"""IMU data published: (R-P-Y) 
        [{self.imu_msg.roll}, {self.imu_msg.pitch}, {self.imu_msg.yaw}]"""


class DepthHandler(SensorHandler):
    def __init__(self, node: Node, log: bool):
        super().__init__(node, log)
        self.depth_msg = Float32()
        self._publisher = self.node.create_publisher(Float32, "/sensors/depth", 10)

    def process_data(self, data, msg_id=0):
        decoded_data = data
        # self.depth_msg.data = -decoded_data
        # self.depth_msg.data = -(decoded_data-0.14) #! recalib
        self.depth_msg.data = -(decoded_data-values["depth offset"].value) #! recalib
        # Old code: 
        # # Pressure in millibars
        # decoded_data = decode(data, num_bytes=2)[0]
        # # In centimeters, downwards negative
        # self.depth_msg.data = 1000 - decoded_data
        # # In metres
        # self.depth_msg.data /= 100

    def message(self) -> Float32:
        return self.depth_msg

    def log_info(self) -> str:
        return f"Depth published: {self.depth_msg.data}"

#TODO Acoustics
