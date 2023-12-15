import rclpy
from rclpy.node import Node

from std_msgs.msg import Header
from linear_acceleration_msg.msg import Acceleration
from sensor_msgs.msg import Imu
from geometry_msgs.msg import Vector3

class MinimalSubscriber(Node):

    def __init__(self):
        super().__init__('minimal_subscriber')
        self.publisher_ = self.create_publisher(Imu, 'linear_acceleration', 10)
        self.subscription = self.create_subscription(
            Acceleration,
            'accel_inter',
            self.listener_callback,
            10)
        self.subscription  # prevent unused variable warning
        self.timer = self.create_timer(0.5, self.timer_callback)
        self.msgs = None

    def listener_callback(self, msg):
        # might need to adjust here if the xyz dont tally up
        self.msgs = (msg.x, msg.y, msg.z)
        print("message: ", self.msgs) 
        self.get_logger().info('msg_num: "%s"' % self.msgs)

    def timer_callback(self):
        if self.msgs != None:
            imu_msg = Vector3()
            imu_msg.linear_acceleration.x = self.msgs[0]
            imu_msg.linear_acceleration.y = self.msgs[1]
            imu_msg.linear_acceleration.z = self.msgs[2]
            self.msgs = None

            self.publisher_.publish(imu_msg)
            self.get_logger().info("published: %s" % imu_msg.linear_acceleration)
        
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
