import rclpy
from rclpy.node import Node

from std_msgs.msg import String


class TestCanSubscriber(Node):

    def __init__(self):
        super().__init__('test_can_subscriber')
        self.subscription = self.create_subscription(
            String,
            'can_output',
            self.listener_callback,
            10)
        self.subscription  # prevent unused variable warning

    def listener_callback(self, msg):
        self.get_logger().info('I heard: "%s"' % msg.data)


def main(args=None):
    rclpy.init(args=args)

    test_can_subscriber = TestCanSubscriber()

    rclpy.spin(test_can_subscriber)
    test_can_subscriber.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()