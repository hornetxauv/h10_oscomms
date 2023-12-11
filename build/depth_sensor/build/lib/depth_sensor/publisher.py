import can

import rclpy
from rclpy.node import Node

from std_msgs.msg import Header
from sensor_msgs.msg import FluidPressure

from std_msgs.msg import String

class MinimalPublisher(Node):

    def __init__(self):
        super().__init__('minimal_publisher')
        self.publisher_ = self.create_publisher(FluidPressure, 'topic', 10)
        timer_period = 0.5  # seconds
        self.timer = self.create_timer(timer_period, self.timer_callback)
        self.i = 0
        self.bus = can.interface.Bus(interface="socketcan", channel="can0", bitrate=500000)

    def timer_callback(self):
        with self.bus as bus:
            for msg in bus:
                #print(msg.data)
                
                # chnage the condition after testing
                msg_id = msg.arbitration_id
                if (msg_id == 4):
                    print("message id:", msg_id)
                    temp = list(msg.data)
                    depth = (float((temp[0] << 8 | temp[1])))
            
                    print(depth, type(depth))
                    
                    # Create an Depth message
                    depth_msg = FluidPressure()

                    # Fill in the header
                    depth_msg.header = Header()
                    #depth_msg.header.stamp = 123.0 error, need type Time
                    depth_msg.header.frame_id = str(msg.arbitration_id)  # Set your frame_id
                    
                    #NEED TEST if this works
                    depth_msg.fluid_pressure = depth

                    self.publisher_.publish(depth_msg)
                    self.get_logger().info("Publishing: %s" % depth_msg)
                    #self.get_logger().info("Publishing: %s" % depth_msg.header.stamp)
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
