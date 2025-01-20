from threading import Thread
import rclpy
import can
from rclpy.node import Node

from can_handler.sensor_handlers import DepthIMUHandler, BatteryHandler, decode

class CanReaderNode(Node):
    def __init__(self, bus: can.ThreadSafeBus, timer_period: float):
        super().__init__('can_reader')
        # self.imu_handler = IMUHandler(self, log=True)
        # self.depth_handler = DepthHandler(self, log=True)
        self.depth_imu_handler = DepthIMUHandler(self, log=True)
        self.voltage_handler = BatteryHandler(self, log=True)
        
        self.buffered_reader = can.BufferedReader()
        _ = can.Notifier(bus=bus, listeners=[self.buffered_reader])
        self.timer = self.create_timer(timer_period, self.publish_all)

    def read_buffer(self):
        while True:
            # print("here")
            msg = self.buffered_reader.get_message()
            # print("Message: ", msg)
            if msg is None: #? check to see what the error is for the sake of it if it triggers here
                continue

            # print("ID: ", msg.arbitration_id)
            decoded_data = decode(msg.data, num_bytes=4)
            if msg.arbitration_id == 19:
                # print("Decoded 19:", decoded_data)
                self.depth_imu_handler.process_data(decoded_data, msg.arbitration_id)
            elif msg.arbitration_id == 20:
                # print("Decoded 20:", decoded_data)
                # self.imu_handler.process_data(decoded_data[0], msg.arbitration_id)
                # self.depth_handler.process_data(decoded_data[1], msg.arbitration_id)
                self.depth_imu_handler.process_data(decoded_data, msg.arbitration_id)
            elif msg.arbitration_id == 22:
                self.voltage_handler.process_data(decoded_data)
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

    def publish_all(self):
        # self.imu_handler.publish()
        # self.depth_handler.publish()
        self.depth_imu_handler.publish()

    def publish_voltage(self):
        self.voltage_handler.publish()

def main(args=None):

    can_bus = can.ThreadSafeBus(interface='socketcan', channel='can0', bitrate=500000) #? thread safe bus vs normal bus

    rclpy.init(args=args)

    can_reader_node = CanReaderNode(can_bus, timer_period=0.05)

    can_reader_thread = Thread(target=can_reader_node.read_buffer, daemon=True)
    can_reader_thread.start()

    rclpy.spin(can_reader_node)

    can_reader_thread.join() #? join detach reminder to check how important this is
    can_reader_node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
