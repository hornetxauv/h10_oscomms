import rclpy
from acoustic_msg.msg import Acoustic
from geometry_msgs.msg import Quaternion, Vector3
from rclpy.node import Node
from sensor_msgs.msg import FluidPressure, Imu
from std_msgs.msg import Header
from tf_transformations import euler_from_quaternion

quat_to_list = lambda quat: [quat.x, quat.y, quat.z, quat.w]
IMU_DICT = {
    "a_x": None,
    "a_y": None,
    "a_z": None,
    "q_x": None,
    "q_y": None,
    "q_z": None,
    "q_w": None,
}


def imu_callback(publisher, bus):
    global IMU_DICT
    with bus as bus:
        for msg in bus:
            # filter for canbus id
            msg_id = msg.arbitration_id
            # print("message id: ", msg_id)

            # Quaternion
            if msg_id == 1:
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
                IMU_DICT["a_x"] = float(
                    int.from_bytes(msg.data[:4], "big", signed=True)
                )
                IMU_DICT["a_y"] = float(
                    int.from_bytes(msg.data[4:], "big", signed=True)
                )

            # Acceleration z
            elif msg_id == 3:
                IMU_DICT["a_z"] = float(
                    int.from_bytes(msg.data[:4], "big", signed=True)
                )

            # if any None values, continue reading from canbus
            if None in IMU_DICT.values():
                continue

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
            imu_msg.orientation = Quaternion()  # Adjust the values accordingly
            imu_msg.orientation.x = IMU_DICT["q_x"] / 1000
            imu_msg.orientation.y = IMU_DICT["q_y"] / 1000
            imu_msg.orientation.z = IMU_DICT["q_z"] / 1000
            imu_msg.orientation.w = IMU_DICT["q_w"] / 1000
            print(imu_msg)
            publisher.publish(imu_msg)


def acoustic_callback(publisher, bus):
    with bus as bus:
        for msg in bus:
            # filter for canbus id
            msg_id = msg.arbitration_id
            print("message id: ", msg_id)
            if msg_id == 10:
                # print(msg.data)
                temp = list(msg.data)  # msg.data is byte array, entries are in hex.
                msg_data = []
                for i in range(0, len(temp), 2):
                    # left shift, or operations
                    msg_data.append(float((temp[i] << 8 | temp[i + 1])))

                # Create an Imu message
                acoustics_msg = Acoustic()
                acoustics_msg.x = msg_data[0]
                acoustics_msg.y = msg_data[1]
                acoustics_msg.z = msg_data[2]
                acoustics_msg.comms_bouy_output = msg_data[3]
                print(acoustics_msg)
                publisher.publish(acoustics_msg)


def depth_callback(publisher, bus):
    with bus as bus:
        for msg in bus:
            # print(msg.data)
            # chnage the condition after testing
            msg_id = msg.arbitration_id
            if msg_id == 4:
                print("message id:", msg_id)
                temp = list(msg.data)
                depth = float((temp[0] << 8 | temp[1]))

                print(depth, type(depth))

                # Create an Depth message
                depth_msg = FluidPressure()

                # Fill in the header
                depth_msg.header = Header()
                # depth_msg.header.stamp = 123.0 error, need type Time
                depth_msg.header.frame_id = str(msg.arbitration_id)  # Set your frame_id

                # NEED TEST if this works
                depth_msg.fluid_pressure = depth
                print(depth_msg)
                publisher.publish(depth_msg)
