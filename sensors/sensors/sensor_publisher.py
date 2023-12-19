import rclpy
from rclpy.node import Node
import can
from sensors.sensor_callbacks import imu_callback, acoustic_callback, depth_callback

from sensor_msgs.msg import Imu
from acoustic_msg.msg import Acoustic
from sensor_msgs.msg import FluidPressure
from std_msgs.msg import Header


bus = can.interface.Bus(
    interface="socketcan", channel="can0", bitrate=500000
)

class SensorDataPublisher(Node):
    def __init__(self, sensor_type, sensor_topic, name, callback_func):
        super().__init__(name)
        self.callback_func = callback_func
        self.publisher_ = self.create_publisher(sensor_type, sensor_topic, 10)
        timer_period = 0.1  # seconds
        self.timer = self.create_timer(timer_period, self.callback)

    def callback(self):
        return self.callback_func(self.publisher_, bus)

def main(publisher):
    rclpy.init()
    rclpy.spin(publisher)
    publisher.destroy_node()
    rclpy.shutdown()

def imu_publisher():
    publisher = SensorDataPublisher(Imu, "/sensors/imu", "imu", imu_callback)
    main(publisher)
    
def acoustic_publisher():
    publisher = SensorDataPublisher(Acoustic, "/sensors/acoustic", "acoustic", acoustic_callback)
    main(publisher)

def depth_publisher():
    publisher = SensorDataPublisher(Imu, "/sensors/depth", "depth", depth_callback)
    main(publisher)