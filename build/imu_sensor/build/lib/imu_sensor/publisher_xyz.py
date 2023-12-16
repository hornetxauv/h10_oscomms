import can
import time

import rclpy
from rclpy.node import Node

from std_msgs.msg import Header
from linear_acceleration_msg.msg import Acceleration

from std_msgs.msg import String

class MinimalPublisher(Node):

    def __init__(self):
        super().__init__('minimal_publisher')
        self.publisher_ = self.create_publisher(Acceleration, 'accel_inter', 10)
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
                if (msg_id == 2):
                    print("message id: ", msg_id)
                    #print(msg.data)
                    temp = list(msg.data) #msg.data is byte array, entries are in hex.
                    msg_data = []
                    for i in range(0 ,len(temp), 4):
                        #left shift, or operations
                        # check the shift amount the excel say 4 used
                        msg_data.append(float(temp[i] << 24 | temp[i+1] << 16 | temp[i+2] << 8 | temp[i+3]))
            
                    print(msg_data, type(msg_data))
                    
                    # Create an Imu message
                    accel_msg = Acceleration()

                    accel_msg.x = msg_data[0]
                    accel_msg.y = msg_data[1]
                    
                    self.publisher_.publish(accel_msg)
                    self.get_logger().info(f"Publishing: {accel_msg}")
                if (msg_id == 3):
                    print("message id: ", msg_id)
                    #print(msg.data)
                    temp = list(msg.data) #msg.data is byte array, entries are in hex.
                    
                    # Create an Imu message
                    accel_msg = Acceleration()

                    accel_msg.z = float(temp[0] << 24 | temp[1] << 16 | temp[2] << 8 | temp[3])
                    
                    self.publisher_.publish(accel_msg)
                    self.get_logger().info(f"Publishing: {accel_msg}")
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
