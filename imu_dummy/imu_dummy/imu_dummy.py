# import can
import rclpy
from geometry_msgs.msg import Quaternion, Vector3
from rclpy.node import Node
from imu_msg.msg import Imu
from std_msgs.msg import Header
from tf_transformations import euler_from_quaternion


IMU_DICT = {
    "a_x": None,
    "a_y": None,
    "a_z": None,
    "q_x": None,
    "q_y": None,
    "q_z": None,
    "q_w": None,
}


# test
class Message:
    def __init__(self, id, msg):
        self.arbitration_id = id
        self.data = msg


class MinimalPublisher(Node):
    def __init__(self):
        super().__init__("imu")
        self.publisher_ = self.create_publisher(Imu, "/sensors/imu", 10)
        timer_period = 0.5  # seconds
        self.timer = self.create_timer(timer_period, self.timer_callback)
        self.i = 0
        # self.bus = can.interface.Bus(interface="socketcan", channel="can0", bitrate=500000)

    def timer_callback(self):
        global IMU_DICT

        # fake messages
        bus = []
        for i in range(1, 4):
            bus.append(Message(i, [1, 2, 3, 4, 5, 6, 7, 8]))

        # adapted from actual
        for msg in bus:
            # filter for canbus id
            msg_id = msg.arbitration_id

            # Quaternion
            if msg_id == 1:
                print("message id: ", msg_id)
                # print(msg.data)
                temp = list(msg.data)  # msg.data is byte array, entries are in hex.
                msg_data = []
                for i in range(0, len(temp), 2):
                    # left shift, or operations
                    msg_data.append(float((temp[i] << 8 | temp[i + 1])))

                print(msg_data, type(msg_data))
                IMU_DICT["q_x"] = msg_data[0]
                IMU_DICT["q_y"] = msg_data[1]
                IMU_DICT["q_z"] = msg_data[2]
                IMU_DICT["q_w"] = msg_data[3]

            # Acceleration xy
            elif msg_id == 2:
                print("message id: ", msg_id)
                # print(msg.data)
                temp = list(msg.data)  # msg.data is byte array, entries are in hex.
                msg_data = []
                for i in range(0, len(temp), 4):
                    # left shift, or operations
                    # check the shift amount the excel say 4 used
                    msg_data.append(
                        float(
                            temp[i] << 24
                            | temp[i + 1] << 16
                            | temp[i + 2] << 8
                            | temp[i + 3]
                        )
                    )

                print(msg_data, type(msg_data))
                IMU_DICT["a_x"] = msg_data[0]
                IMU_DICT["a_y"] = msg_data[1]

            # Acceleration z
            elif msg_id == 3:
                print("message id: ", msg_id)
                # print(msg.data)
                temp = list(msg.data)  # msg.data is byte array, entries are in hex.

                IMU_DICT["a_z"] = float(
                    temp[0] << 24 | temp[1] << 16 | temp[2] << 8 | temp[3]
                )

        # processing
        if None in IMU_DICT.values():
            return

        imu_msg = Imu()
        # Fill in the header
        imu_msg.header = Header()
        imu_msg.header.frame_id = str(msg.arbitration_id)

        # acceleration
        imu_msg.linear_acceleration = Vector3()
        imu_msg.linear_acceleration.y = IMU_DICT["a_y"] / 1000
        imu_msg.linear_acceleration.x = IMU_DICT["a_x"] / 1000
        imu_msg.linear_acceleration.z = IMU_DICT["a_z"] / 1000

        # Quaternion
        # Fill in the orientation (quaternion)
        # imu_msg.orientation = Quaternion(0.0, 0.0, 0.0, 1.0)  # Adjust the values accordingly
        rpy_list = euler_from_quaternion(
            [
                IMU_DICT["q_x"] / 1000,
                IMU_DICT["q_y"] / 1000,
                IMU_DICT["q_z"] / 1000,
                IMU_DICT["q_w"] / 1000,
            ]
        )

        # roll_pitch_yaw
        imu_msg.roll_pitch_yaw = Vector3()
        # flip roll pitch roll negative
        imu_msg.roll_pitch_yaw.y = -rpy_list[0]
        imu_msg.roll_pitch_yaw.x = rpy_list[1]
        imu_msg.roll_pitch_yaw.z = rpy_list[2]

        print(f"Linear acceleration published: {imu_msg.linear_acceleration}")
        print(f"Orientation published: {imu_msg.roll_pitch_yaw}")
        # print(
        #    f"Roll Pitch Yaw: {euler_from_quaternion(quat_to_list(imu_msg.orientation))}"
        # )

        self.publisher_.publish(imu_msg)


def main(args=None):
    rclpy.init(args=args)

    imu = MinimalPublisher()

    rclpy.spin(imu)

    # Destroy the node explicitly
    # (optional - otherwise it will be done automatically
    # when the garbage collector destroys the node object)
    imu.destroy_node()
    rclpy.shutdown()


if __name__ == "__main__":
    main()
