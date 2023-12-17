import rclpy
from rclpy.node import Node

from std_msgs.msg import Header
from linear_acceleration_msg.msg import AccelerationXY, AccelerationZ
from sensor_msgs.msg import Imu
from geometry_msgs.msg import Vector3

xyz = [None, None, None]

class MinimalSubscriber(Node):
    def __init__(self):
        super().__init__('minimal_subscriber')
        self.publisher_ = self.create_publisher(Imu, 'linear_acceleration', 10)
        self.subscription_xy = self.create_subscription(
            AccelerationXY,
            'accel_inter_xy',
            self.listener_callback_xy,
            10)
        self.subscription_z = self.create_subscription(
            AccelerationZ,
            'accel_inter_z',
            self.listener_callback_z,
            10)
        self.timer = self.create_timer(0.5, self.timer_callback)

    def listener_callback_xy(self, msg):
        global xyz
        # might need to adjust here if the xyz dont tally up
        xyz[0] = msg.x
        xyz[1] = msg.y
    
    def listener_callback_z(self, msg):
        global xyz
        # might need to adjust here if the xyz dont tally up
        xyz[2] = msg.z

    def timer_callback(self):
        global xyz
        if None in xyz:
            return         
        # no header dk if will have issue
        imu_msg = Imu()
        imu_msg.linear_acceleration = Vector3()
        imu_msg.linear_acceleration.x = xyz[0]
        imu_msg.linear_acceleration.y = xyz[1]
        imu_msg.linear_acceleration.z = xyz[2]
        xyz = [None, None, None]

        self.publisher_.publish(imu_msg)
        self.get_logger().info(f"published: {imu_msg.linear_acceleration}")
        
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
