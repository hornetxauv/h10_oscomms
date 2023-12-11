import can

import rclpy
from rclpy.node import Node

from std_msgs.msg import Header
from acoustic_msg.msg import Acoustic

from std_msgs.msg import String

class MinimalPublisher(Node):

    def __init__(self):
        super().__init__('minimal_publisher')
        self.publisher_ = self.create_publisher(Acoustic, 'topic', 10)
        timer_period = 0.5  # seconds
        self.timer = self.create_timer(timer_period, self.timer_callback)
        self.i = 0
        self.bus = can.interface.Bus(interface="socketcan", channel="can0", bitrate=500000)

    def timer_callback(self):
        with self.bus as bus:
            for msg in bus:
                #filter for canbus id
                msg_id = msg.arbitration_id
                print("message id: ", msg_id)
                if (msg_id == 10):
                    #print(msg.data)
                    temp = list(msg.data) #msg.data is byte array, entries are in hex.
                    msg_data = []
                    for i in range(0 ,len(temp), 2):
                        #left shift, or operations
                        msg_data.append(float((temp[i] << 8 | temp[i + 1])))
            
                    print(msg_data, type(msg_data))
                    
                    # Create an Imu message
                    acoustics_msg = Acoustic()
                    acoustics_msg.x = msg_data[0]
                    acoustics_msg.y = msg_data[1]
                    acoustics_msg.z = msg_data[2]
                    acoustics_msg.comms_bouy_output = msg_data[3]

                    self.publisher_.publish(acoustics_msg)
                    self.get_logger().info("Publishing: %s" % acoustics_msg)
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
