import can
import time

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
                #filter for canbus id
                msg_id = msg.arbitration_id
                
                # change the condition when done testing
                if (msg_id == 1):
                    print("message id: ", msg_id)
                    #print(msg.data)
                    temp = list(msg.data) #msg.data is byte array, entries are in hex.
                    msg_data = []
                    for i in range(0 ,len(temp), 2):
                        #left shift, or operations
                        msg_data.append(float((temp[i] << 8 | temp[i + 1])))
            
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
                    imu_msg.orientation.x = msg_data[0]
                    imu_msg.orientation.y = msg_data[1]
                    imu_msg.orientation.z = msg_data[2]
                    imu_msg.orientation.w = msg_data[3]	
                    # Fill in the angular velocity
                    imu_msg.angular_velocity = Vector3()  # Adjust the values accordingly

                    # Fill in the linear acceleration
                    imu_msg.linear_acceleration = Vector3()  # Adjust the values accordingly

                    self.publisher_.publish(imu_msg)
                    self.get_logger().info("Publishing: %s" % imu_msg)
                    #self.get_logger().info("Publishing: %s" % imu_msg.header.stamp)
                    #time.sleep(1)
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
