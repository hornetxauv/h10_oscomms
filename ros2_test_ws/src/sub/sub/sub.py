import rclpy
from rclpy.node import Node

from std_msgs.msg import String
from test_msg.msg import Num

class MinimalSubscriber(Node):

    def __init__(self):
        super().__init__('sub')
        self.publisher_ = self.create_publisher(String, 'outtopic', 10)
        self.subscription = self.create_subscription(
            Num,
            'topic',
            self.listener_callback,
            10)
        self.subscription  # prevent unused variable warning
        self.timer = self.create_timer(0.5, self.timer_callback)
        self.msgs = None

    def listener_callback(self, msg):
        self.msgs = (msg.num, msg.data)
        print(msg.num, msg.data) # see the msg file and .<msg_entry>
        self.get_logger().info('msg_num: "%s"' % msg.num)

    def timer_callback(self):
        msg = String()
        if self.msgs != None:
            msg.data = str(self.msgs[1])
            self.publisher_.publish(msg)
            self.get_logger().info("published: %s" % msg.data)
            self.msgs = None
        
def main(args=None):
    rclpy.init(args=args)

    minimal_subscriber = MinimalSubscriber()

    rclpy.spin(minimal_subscriber)

    # Destroy the node explicitly
    # (optional - otherwise it will be done automatically
    # when the garbage collector destroys the node object)
    minimal_subscriber.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
