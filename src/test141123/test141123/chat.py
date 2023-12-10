import os
import rclpy
from rclpy.executors import MultiThreadedExecutor
from rclpy.node import Node
from rclpy.executors import MultiThreadedExecutor
from std_msgs.msg import String

COLOR_RESET = '\033[0m'
def color_hash(s):
    color_codes = [
        '\033[31m',  # Red
        '\033[32m',  # Green
        '\033[33m',  # Yellow
        '\033[34m',  # Blue
        '\033[36m',  # Cyan
        '\033[37m'   # White
    ]
    
    hash_value = hash(s)
    color_index = hash_value % len(color_codes)
    
    return color_codes[color_index]

NAME = input("Enter your name: ")
color = color_hash(NAME)
NAME = color + NAME + COLOR_RESET

def clear_terminal():
    os.system('clear')

class MinimalPublisher(Node):
    def __init__(self):
        super().__init__('minimal_publisher')
        self.publisher_ = self.create_publisher(String, 'topic', 10)
        timer_period = 0.5  # seconds
        self.timer = self.create_timer(timer_period, self.timer_callback)

    def timer_callback(self):
        msg = String()
        msg.data = NAME + ": " + input()
        self.publisher_.publish(msg)

class MinimalSubscriber(Node):
    def __init__(self):
        super().__init__('chat')
        self.subscription = self.create_subscription(
            String,
            'topic',
            self.listener_callback,
            10)
        self.subscription  # prevent unused variable warning
        self.queue = []

    def listener_callback(self, msg):
        clear_terminal()
        self.queue.append(msg.data)
        #limit to 10
        if (len(self.queue) > 10):
            self.queue = self.queue[1:]
        #print out the messages
        for data in self.queue:
            print(data)

def main(args=None):
    rclpy.init(args=args)
    
    minimal_publisher = MinimalPublisher()
    minimal_subscriber = MinimalSubscriber()
    
    executor = MultiThreadedExecutor()

    executor.add_node(minimal_publisher)
    executor.add_node(minimal_subscriber)

    executor.spin()

    # Destroy the node explicitly
    # (optional - otherwise it will be done automatically
    # when the garbage collector destroys the node object)
    executor.shutdown()
    minimal_publisher.destroy_node()
    minimal_subscriber.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
    


