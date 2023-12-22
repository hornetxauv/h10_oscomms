import can
import rclpy
from acoustic_msg.msg import Acoustic
from imu_msg.msg import Imu
from rclpy.node import Node
from sensor_msgs.msg import FluidPressure
from sensors.sensor_callbacks import acoustic_callback, depth_callback, imu_callback


class SensorDataPublisher(Node):
    def __init__(self, sensor_type, sensor_topic, name, callback_func):
        super().__init__(name)
        self.bus = can.interface.Bus(
            interface="socketcan", channel="can0", bitrate=500000
        )
        self.callback_func = callback_func
        self.publisher_ = self.create_publisher(sensor_type, sensor_topic, 10)
        timer_period = 0.05  # seconds
        self.timer = self.create_timer(timer_period, self.callback)

    def callback(self):
        return self.callback_func(self.publisher_, self.bus)


def sensor(sensor_type, sensor_topic, name, callback_func):
    rclpy.init()
    publisher = SensorDataPublisher(sensor_type, sensor_topic, name, callback_func)
    rclpy.spin(publisher)
    publisher.destroy_node()
    rclpy.shutdown()


def imu_publisher():
    sensor(Imu, "/sensors/imu", "imu", imu_callback)


def acoustic_publisher():
    sensor(Acoustic, "/sensors/acoustic", "acoustic", acoustic_callback)


def depth_publisher():
    sensor(FluidPressure, "/sensors/depth", "depth", depth_callback)
