import can
import rclpy
from geometry_msgs.msg import Quaternion, Vector3
from linear_acceleration_msg.msg import AccelerationXY, AccelerationZ
from rclpy.node import Node
from sensor_msgs.msg import Imu
from std_msgs.msg import Header

IMU_DICT = {
    "a_x": None,
    "a_y": None,
    "a_z": None,
    "q_x": None,
    "q_y": None,
    "q_z": None,
    "q_w": None,
}


class MinimalPublisher(Node):
    def __init__(self):
        super().__init__("imu")
        self.publisher_ = self.create_publisher(Imu, "/sensors/imu", 10)
        timer_period = 0.1  # seconds
        self.timer = self.create_timer(timer_period, self.timer_callback)
        self.i = 0
        self.bus = can.interface.Bus(
            interface="socketcan", channel="can0", bitrate=500000
        )

    def timer_callback(self):
        global IMU_DICT
        with self.bus as bus:
            for msg in bus:
                # filter for canbus id
                msg_id = msg.arbitration_id

                # Quaternion
                if msg_id == 1:
                    print("message id: ", msg_id)

                    IMU_DICT["q_x"] = float(
                        int.from_bytes(msg.data[:2], "big", signed=True)
                    )
                    IMU_DICT["q_y"] = float(
                        int.from_bytes(msg.data[2:4], "big", signed=True)
                    )
                    IMU_DICT["q_z"] = float(
                        int.from_bytes(msg.data[4:6], "big", signed=True)
                    )
                    IMU_DICT["q_w"] = float(
                        int.from_bytes(msg.data[6:], "big", signed=True)
                    )

                # Acceleration xy
                elif msg_id == 2:
                    print("message id: ", msg_id)
                    IMU_DICT["a_x"] = float(
                        int.from_bytes(msg.data[:4], "big", signed=True)
                    )
                    IMU_DICT["a_y"] = float(
                        int.from_bytes(msg.data[4:], "big", signed=True)
                    )
                    print(IMU_DICT["a_x"], IMU_DICT["a_y"])

                # Acceleration z
                elif msg_id == 3:
                    print("message id: ", msg_id)
                    IMU_DICT["a_z"] = float(
                        int.from_bytes(msg.data[:4], "big", signed=True)
                    )
                    print(IMU_DICT["a_z"])

                # if any None values, continue reading from canbus
                if None in IMU_DICT.values():
                    continue

                imu_msg = Imu()
                # Fill in the header
                imu_msg.header = Header()
                imu_msg.header.frame_id = str(msg.arbitration_id)

                # acceleration
                imu_msg.linear_acceleration = Vector3()
                imu_msg.linear_acceleration.y = IMU_DICT["a_y"]
                imu_msg.linear_acceleration.x = IMU_DICT["a_x"]
                imu_msg.linear_acceleration.z = IMU_DICT["a_z"]

                # Quaternion
                # Fill in the orientation (quaternion)
                # imu_msg.orientation = Quaternion(0.0, 0.0, 0.0, 1.0)  # Adjust the values accordingly
                imu_msg.orientation = Quaternion()  # Adjust the values accordingly
                imu_msg.orientation.x = IMU_DICT["q_x"]
                imu_msg.orientation.y = IMU_DICT["q_y"]
                imu_msg.orientation.z = IMU_DICT["q_z"]
                imu_msg.orientation.w = IMU_DICT["q_w"]

                self.publisher_.publish(imu_msg)
                self.get_logger().info(
                    f"linear acceleration published: {imu_msg.linear_acceleration}"
                )
                self.get_logger().info(f"orientation published: {imu_msg.orientation}")


def main(args=None):
    rclpy.init(args=args)

    minimal_publisher = MinimalPublisher()

    rclpy.spin(minimal_publisher)

    # Destroy the node explicitly
    # (optional - otherwise it will be done automatically
    # when the garbage collector destroys the node object)
    minimal_publisher.destroy_node()
    rclpy.shutdown()


if __name__ == "__main__":
    main()
