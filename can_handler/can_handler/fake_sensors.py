from abc import ABC, abstractmethod

import numpy as np
import rclpy
from geometry_msgs.msg import Vector3
from msg_types.msg import IMU
from rclpy.node import Node
from std_msgs.msg import Header


class IMU_Generator(ABC):
    @abstractmethod
    def update(self):
        pass  # pragma: no cover


class IMU_SHM(IMU_Generator):
    def __init__(self, amplitude=[0, 0, 1], wavelength=10) -> None:
        self.count = 0
        self.amplitude = np.array(amplitude)
        self.wavelength = wavelength

    def update(self):
        self.roll_pitch_yaw = self.amplitude * np.sin(
            self.count / self.wavelength * np.pi
        )
        self.count += 1
        return self.roll_pitch_yaw


class IMU_Constant(IMU_Generator):
    def __init__(self, roll_pitch_yaw) -> None:
        self.roll_pitch_yaw = roll_pitch_yaw

    def update(self):
        return self.roll_pitch_yaw


class FakeIMUPublisher(Node):
    def __init__(self, name, imu_generator: IMU_Generator, timer_period: int) -> None:
        super().__init__(name)

        self.imu_generator = imu_generator
        self.imu_msg = IMU()
        self.publisher = self.create_publisher(IMU, "/sensors/imu", 10)
        self.timer = self.create_timer(timer_period, self.callback)

    def callback(self):
        roll_pitch_yaw = self.imu_generator.update()
        self.imu_msg.roll, self.imu_msg.pitch, self.imu_msg.yaw = roll_pitch_yaw
        self.imu_msg.header = Header()
        self.imu_msg.header.frame_id = str(0)

        self.publisher.publish(self.imu_msg)

        self.get_logger().info(
            f"""IMU data published: (R-P-Y) [{self.imu_msg.roll}, {self.imu_msg.pitch}, {self.imu_msg.yaw}]"""
            )


def imu_publisher():
    imu_pub = IMU_SHM()
    # imu_pub = IMU_Constant(roll_pitch_yaw=[0.0, 0.0, -np.pi])

    rclpy.init()
    publisher = FakeIMUPublisher("fake_imu_publisher_node", imu_pub, 0.1)
    rclpy.spin(publisher)
    publisher.destroy_node()
    rclpy.shutdown()
