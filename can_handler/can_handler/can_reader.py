import rclpy
from rclpy.node import Node
from std_msgs.msg import String

class CanReaderNode(Node):

    def __init__(self):
        super().__init__('can_reader')
        self.publisher_ = self.create_publisher(String, 'can_output', 10) # “queue size” is 10
        timer_period = 0.5  # seconds
        self.timer = self.create_timer(timer_period, self.timer_callback)
        self.i = 0

    def timer_callback(self):
        msg = String()
        msg.data = 'Hello World: %d' % self.i
        self.publisher_.publish(msg)
        self.get_logger().info('Publishing: "%s"' % msg.data)
        self.i += 1

def main(args=None):
    rclpy.init(args=args)
    can_reader_node = CanReaderNode()
    rclpy.spin(can_reader_node)
    can_reader_node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()