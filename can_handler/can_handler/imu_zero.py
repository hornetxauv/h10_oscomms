import json
import time

import rclpy
from rclpy.node import Node
from msg_types.msg import DepthIMU


class IMUReader(Node):
    def __init__(self):
        super().__init__("imu_zero_computing")
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


def main():
    rclpy.init()
    imu_reader = IMUReader()

    # Spin for 5 seconds
    imu_reader.get_logger().info("STARTING IMU ZEROING...")
    while rclpy.ok() and time.time() - imu_reader.start_time <= 5:
        rclpy.spin_once(imu_reader)
    imu_reader.get_logger().info("ENDING IMU ZEROING...")

    imu_reader.publish_to_json(
        "/home/aa/h10_workspace/src/oscomms/can_handler/can_handler/imu_zero.json"
    )
    imu_reader.get_logger().info(
        "COMPUTED IMU ZERO AND PUBLISHED TO JSON FILE... DONE."
    )

    imu_reader.destroy_node()
    rclpy.shutdown()


if __name__ == "__main__":
    main()