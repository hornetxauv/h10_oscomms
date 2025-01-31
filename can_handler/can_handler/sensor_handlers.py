import numpy as np

from abc import ABC, abstractmethod
from typing import List, Union

from std_msgs.msg import Float32, Header
from geometry_msgs.msg import Vector3
from msg_types.msg import IMU
from rclpy.node import Node
from rclpy.publisher import Publisher

def decode(data, num_bytes):
    """
    data: bytearray
    num_bytes: Number of bytes for each value
    """
    decoded_data = []
    for i in range(0, len(data), num_bytes):
        packet = data[i : i + num_bytes]
        decoded_packet = float(int.from_bytes(packet, "little", signed=True))
        decoded_data.append(decoded_packet)
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
        msg = self.message
        if msg is not None:
            self.publisher.publish(msg)
            if self.log:
                self.node.get_logger().info(self.log_info)


class IMUHandler(SensorHandler):
    def __init__(self, node: Node, log: bool):
        super().__init__(node, log)
        self.imu_msg = IMU()
        self.counter = 0
        self._publisher = self.node.create_publisher(IMU, "/sensors/imu", 10)

    def process_data(self, data: Union[int, tuple[int, int]], msg_id=0):
        # Pitch & Roll
        if msg_id == 19:
            self.imu_msg.pitch, self.imu_msg.roll = data
        # Yaw
        elif msg_id == 20:
            self.imu_msg.yaw = data
    
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
        self.depth_msg.data = decoded_data
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