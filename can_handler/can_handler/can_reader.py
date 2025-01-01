from threading import Thread
import rclpy
import can
from rclpy.node import Node
from std_msgs.msg import String

class CanReaderNode(Node):
    def __init__(self, bus: can.ThreadSafeBus):
        super().__init__('can_reader')
        # CAN bus
        self.buffered_reader = can.BufferedReader()
        # ROS
        self.publisher_ = self.create_publisher(String, 'can_output', 10) # “queue size” is 10
        timer_period = 0.5  # seconds
        #? to check timer_period instantiation in or outside OOP affect time recalling
        self.timer = self.create_timer(timer_period, self.publish_can)

    def read_buffer(self):
        while True:
            msg = self.buffered_reader.get_message()
            if msg is None: #? check to see what the error is for the sake of it if it triggers here
                continue

            if 19 <= msg.arbitration_id <= 20:
                #TODO imu and depth sensor handler
                pass
            elif msg.arbitration_id == 22:
                #TODO temperature and pht sensor
                pass
            elif msg.arbitration_id == 23:
                #TODO ultrasonic sensor
                pass
            elif msg.arbitration_id == 32:
                #TODO acoustics
                pass
            elif msg.arbitration_id == 48:
                #TODO heartbeat
                pass
            else:
                print("Error: Can reader arbitration ID of unknown value")

    def test_publish(self):
        #TODO publish to the ros topic
        msg = String()
        msg.data = 'Hello World: %d' % self.i
        self.publisher_.publish(msg)
        self.get_logger().info('Publishing: "%s"' % msg.data)
        self.i += 1

    def publish(self):
        pass
        #? why not publish at the same time as when receiving

def main(args=None):

    can_bus = can.ThreadSafeBus(interface='socketcan', channel='can0', bitrate=500000) #? thread safe bus vs normal bus

    rclpy.init(args=args)

    can_reader_node = CanReaderNode(can_bus)

    can_reader_thread = Thread(target=can_reader_node.read_buffer, daemon=True)
    can_reader_thread.start()

    rclpy.spin(can_reader_node)

    can_reader_thread.join() #? join detach reminder to check how important this is
    can_reader_node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()