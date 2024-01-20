from abc import ABC, abstractmethod
from typing import Union

from acoustics_msg.msg import Acoustics
from geometry_msgs.msg import Vector3
from imu_msg.msg import Imu
from rclpy.node import Node
from rclpy.publisher import Publisher
from std_msgs.msg import Float32, Header
from tf_transformations import euler_from_quaternion


def decode(data, num_bytes):
    """
    data: bytearray
    num_bytes: Number of bytes for each value
    """
    decoded_data = []
    for i in range(0, len(data), num_bytes):
        packet = data[i : i + num_bytes]
        decoded_packet = float(int.from_bytes(packet, "big", signed=True))
        decoded_data.append(decoded_packet)
    return decoded_data


class SensorHandler(ABC):
    def __init__(self, node: Node, log: bool):
        self.node = node
        self.log = log

    @property
    @abstractmethod
    def publisher(self) -> Union[Publisher, None]:
        pass

    @abstractmethod
    def process_data(self, data, msg_id):
        pass

    @abstractmethod
    def get_message(self):
        pass

    def publish(self):
        msg, string_repr = self.get_message()
        if msg is not None:
            self.publisher.publish(msg)
            if self.log:
                self.node.get_logger().info(string_repr)


class IMUHandler(SensorHandler):
    def __init__(self, node: Node, log: bool):
        super().__init__(node, log)
        self.imu_dict = {
            "a_x": 0,
            "a_y": 0,
            "a_z": 0,
            "q_x": None,
            "q_y": None,
            "q_z": None,
            "q_w": None,
        }
        self.counter = 0
        self._publisher = self.node.create_publisher(Imu, "/sensors/imu", 10)

    @property
    def publisher(self) -> Union[Publisher, None]:
        return self._publisher

    def process_data(self, data, msg_id):
        # Quaternion
        if msg_id == 1:
            (
                self.imu_dict["q_x"],
                self.imu_dict["q_y"],
                self.imu_dict["q_z"],
                self.imu_dict["q_w"],
            ) = decode(data, num_bytes=2)

        # Acceleration xy
        elif msg_id == 2:
            self.imu_dict["a_x"], self.imu_dict["a_y"] = decode(data, num_bytes=4)

        # Acceleration z
        elif msg_id == 3:
            self.imu_dict["a_z"], _ = decode(data, num_bytes=4)

    def get_message(self):
        # If any None values, continue reading from canbus
        if None in self.imu_dict.values():
            return None, ""

        imu_msg = Imu()

        # Fill in the header
        imu_msg.header = Header()
        imu_msg.header.frame_id = str(self.counter)
        self.counter += 1

        # Acceleration
        imu_msg.linear_acceleration = Vector3()
        imu_msg.linear_acceleration.x = self.imu_dict["a_x"] / 1000
        imu_msg.linear_acceleration.y = self.imu_dict["a_y"] / 1000
        imu_msg.linear_acceleration.z = self.imu_dict["a_z"] / 1000

        # Quaternion
        rpy_list = euler_from_quaternion(
            [
                self.imu_dict["q_x"] / 1000,
                self.imu_dict["q_y"] / 1000,
                self.imu_dict["q_z"] / 1000,
                self.imu_dict["q_w"] / 1000,
            ]
        )

        # roll_pitch_yaw
        imu_msg.roll_pitch_yaw = Vector3()

        # Roll negative
        imu_msg.roll_pitch_yaw.x = -rpy_list[0]
        imu_msg.roll_pitch_yaw.y = rpy_list[1]
        imu_msg.roll_pitch_yaw.z = rpy_list[2]

        string_repr = f"""Linear acceleration published: {imu_msg.linear_acceleration})
        Orientation published: {imu_msg.roll_pitch_yaw}"""

        return imu_msg, string_repr


class AcousticsHandler(SensorHandler):
    def __init__(self, node: Node, log: bool):
        super().__init__(node, log)
        self.acoustics_msg = Acoustics()
        self._publisher = self.node.create_publisher(
            Acoustics, "/sensors/acoustics", 10
        )

    @property
    def publisher(self) -> Union[Publisher, None]:
        return self._publisher

    def process_data(self, data, msg_id):
        (
            self.acoustics_msg.x,
            self.acoustics_msg.y,
            self.acoustics_msg.z,
            self.acoustics_msg.comms_bouy_out,
        ) = decode(data, num_bytes=2)

    def get_message(self):
        string_repr = f"""Acoustics data published: [{self.acoustics_msg.x}, 
        {self.acoustics_msg.y}, {self.acoustics_msg.z}, {self.acoustics_msg.comms_bouy_out}]"""
        return self.acoustics_msg, string_repr


class DepthHandler(SensorHandler):
    def __init__(self, node: Node, log: bool):
        super().__init__(node, log)
        self.depth_msg = Float32()
        self._publisher = self.node.create_publisher(Float32, "/sensors/depth", 10)

    @property
    def publisher(self) -> Union[Publisher, None]:
        return self._publisher

    def process_data(self, data, msg_id):
        # Pressure in millibars
        decoded_data = decode(data, num_bytes=2)[0]
        # In centimeters, downwards negative
        self.depth_msg.data = 1000 - decoded_data
        # In metres
        self.depth_msg.data /= 100

    def get_message(self):
        string_repr = f"Depth published: {self.depth_msg.data}"
        return self.depth_msg, string_repr
