from threading import Thread

import rclpy
from can import BufferedReader, Notifier, ThreadSafeBus
from rclpy.node import Node
from sensors.sensor_handlers import AcousticsHandler, DepthHandler, IMUHandler, IMUCorrectedHandler


class CanReaderNode(Node):
    def __init__(self, bus: ThreadSafeBus, timer_period: float):
        super().__init__("can_reader")

        # Creates a thread to read messages from the bus and distributes them to listeners
        self.buffered_reader = BufferedReader()
        notifier = Notifier(bus=bus, listeners=[self.buffered_reader])

        self.imu_handler = IMUHandler(self, log=True)
        self.imu_corrected_handler = IMUCorrectedHandler(self, log=True)
        self.acoustics_handler = AcousticsHandler(self, log=False)
        self.depth_handler = DepthHandler(self, log=False)

        self.timer = self.create_timer(timer_period, self.publish_sensors)

    def read_can(self):
        while True:
            msg = self.buffered_reader.get_message()
            if msg is None:
                continue

            msg_id = msg.arbitration_id

            if 1 <= msg_id <= 3:
                self.imu_handler.process_data(msg.data, msg_id)
                self.imu_corrected_handler.process_data(msg.data, msg_id)

            elif msg_id == 4:
                self.depth_handler.process_data(msg.data, msg_id)

            elif msg_id == 10:
                self.acoustics_handler.process_data(msg.data, msg_id)

    def publish_sensors(self):
        self.imu_handler.publish()
        self.imu_corrected_handler.publish()
        self.acoustics_handler.publish()
        self.depth_handler.publish()


def main(args=None):
    bus = ThreadSafeBus(interface="socketcan", channel="can0", bitrate=500000)

    rclpy.init(args=args)

    # This node reads from CAN and publishes sensor values at fixed intervals
    can_reader_node = CanReaderNode(bus, timer_period=0.05)

    # Create thread to read from CAN and update sensor values
    read_can_thread = Thread(target=can_reader_node.read_can, daemon=True)
    read_can_thread.start()

    # Main thread publishes latest values to sensor topics
    rclpy.spin(can_reader_node)

    # Clean up
    can_reader_node.destroy_node()
    read_can_thread.join()
    rclpy.shutdown()
