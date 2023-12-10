import can

#bus = can.interface.Bus(interface="socketcan", channel="can0", bitrate=500000)
"""
msg = can.Message(
  arbitration_id=123,
  data=[1, 2, 3, 4, 5, 6, 7, 8],
  is_extended_id=False
)
"""

"""
with bus as bus:
    for msg in bus:
        temp = bytearray.count(msg.data)
"""
import rclpy
from rclpy.node import Node

from std_msgs.msg import Header
from sensor_msgs.msg import Imu
from geometry_msgs.msg import Quaternion, Vector3

from std_msgs.msg import String

class MinimalPublisher(Node):

    def __init__(self):
        super().__init__('minimal_publisher')
        self.publisher_ = self.create_publisher(Imu, 'topic', 10)
        timer_period = 0.5  # seconds
        self.timer = self.create_timer(timer_period, self.timer_callback)
        self.i = 0
        self.bus = can.interface.Bus(interface="socketcan", channel="can0", bitrate=500000)

    def timer_callback(self):
        with self.bus as bus:
            for msg in bus:
                temp = list(msg.data)
                msg_data = []
                for i in range(0 ,len(temp), 2):
                    msg_data.append(hex((temp[i] << 8 | temp[i + 1])))
                print(msg_data, type(msg_data))
                
                # Create an Imu message
                imu_msg = Imu()

                # Fill in the header
                imu_msg.header = Header()
                #imu_msg.header.stamp = 123.0 error, need type Time
                imu_msg.header.frame_id = str(msg.arbitration_id)  # Set your frame_id

                # Fill in the orientation (quaternion)
                #imu_msg.orientation = Quaternion(0.0, 0.0, 0.0, 1.0)  # Adjust the values accordingly
                imu_msg.orientation = Quaternion()  # Adjust the values accordingly
                imu_msg.orientation.x = float(msg.data[0])

                # Fill in the angular velocity
                imu_msg.angular_velocity = Vector3()  # Adjust the values accordingly

                 # Fill in the linear acceleration
                imu_msg.linear_acceleration = Vector3()  # Adjust the values accordingly

                self.publisher_.publish(imu_msg)
                self.get_logger().info("Publishing: %s" % imu_msg)
                #self.get_logger().info("Publishing: %s" % imu_msg.header.stamp)
        """
        msg = String()
        msg.data = 'Hello World: %d' % self.i
        self.publisher_.publish(msg)
        self.get_logger().info('Publishing: "%s"' % msg.data)
        self.i += 1
        """

def main(args=None):
    rclpy.init(args=args)

    minimal_publisher = MinimalPublisher()

    rclpy.spin(minimal_publisher)

    # Destroy the node explicitly
    # (optional - otherwise it will be done automatically
    # when the garbage collector destroys the node object)
    minimal_publisher.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
