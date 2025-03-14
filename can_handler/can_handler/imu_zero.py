import json
import time

import rclpy
from rclpy.node import Node
from msg_types.msg import DepthIMU

from rclpy.executors import MultiThreadedExecutor
import threading


class IMUReader(Node):
    def __init__(self, node=None):
        if node is None:
            super().__init__("imu_zero_computing")
        else:
            super().__init__(node_name="imu_zero_computing", context=node.context)

        self.subscription = self.create_subscription(
            DepthIMU, "/sensors/depth_imu", self.imu_callback, 10
        )
        self.imu_data = []
        self.start_time = time.time()

    def imu_callback(self, msg: DepthIMU):
        self.imu_data.append([])
        self.imu_data[-1].append(msg.roll)
        self.imu_data[-1].append(msg.pitch)
        self.imu_data[-1].append(msg.yaw)

    def calculate_average(self):
        if not self.imu_data:
            return [0, 0, 0]
        avg_roll_pitch_yaw = [sum(i) / len(i) for i in zip(*self.imu_data)]
        return avg_roll_pitch_yaw

    def publish_to_json(self, filename):
        with open(filename, "w") as json_file:
            json.dump(self.calculate_average(), json_file, indent=4)


def main(node=None):
    imu_reader = IMUReader(node)
    executor = MultiThreadedExecutor()
    executor.add_node(imu_reader)

    imu_reader.get_logger().info("STARTING IMU ZEROING...")

    def run_executor():
        start_time = time.time()
        while rclpy.ok() and time.time() - start_time <= 5:
            executor.spin_once(timeout_sec=0.1)

    # Run executor in a separate thread
    thread = threading.Thread(target=run_executor)
    thread.start()
    thread.join()  # Wait for the thread to complete

    imu_reader.get_logger().info("ENDING IMU ZEROING...")

    imu_reader.publish_to_json("/home/aa/h10_workspace/src/oscomms/can_handler/can_handler/imu_zero.json")
    imu_reader.get_logger().info("COMPUTED IMU ZERO AND PUBLISHED TO JSON FILE... DONE.")

    imu_reader.destroy_node()
    executor.shutdown()


if __name__ == "__main__":
    main()