import numpy as np

from abc import ABC, abstractmethod
from typing import List, Union

from std_msgs.msg import Float32, Header, Bool
from geometry_msgs.msg import Vector3
from msg_types.msg import DepthIMU, Battery
from rclpy.node import Node
from rclpy.publisher import Publisher

from collections import deque
import statistics

import struct
import time
import binascii
import json

# from control_panel.control_panel import create_control_panel, ControlPanelItem as CPI #this is a package in PL repo

with open("/home/aa/h10_workspace/src/oscomms/can_handler/can_handler/imu_zero.json", "r") as f:
    IMU_ZERO = json.load(f)

def decode(data, num_bytes):
    """
    data: bytearray
    num_bytes: Number of bytes for each value
    """
    decoded_data = []
    for i in range(0, 8, num_bytes):
        packet = struct.unpack_from("<f", data, i)
        decoded_data.append(packet[0])
    return decoded_data


class SensorHandler(ABC):
    def __init__(self, node: Node, log: bool):
        self.node = node
        self.log = log

    @abstractmethod
    def process_data(self, data, msg_id):
        pass
    
    @property
    @abstractmethod
    def message(self):
        pass

    @property
    @abstractmethod
    def log_info(self):
        pass

    @property
    def publisher(self) -> Union[Publisher, None]:
        return self._publisher
    
    def publish(self):
        msg = self.message()
        if msg is not None and self.new:
            self.publisher.publish(msg)
            self.new = False
            if self.log:
                self.node.get_logger().info(self.log_info())


class DepthIMUHandler(SensorHandler):
    def __init__(self, node: Node, log: bool):
        super().__init__(node, log)
        self.depth_imu_msg = DepthIMU()
        self.counter = 0
        self._publisher = self.node.create_publisher(DepthIMU, "/sensors/depth_imu", 10)
        # self._update_timer = {
        #     "depth": time.time(),
        #     "roll": time.time(),
        #     "pitch": time.time(),
        #     "yaw": time.time(),
        #     } # d, r, p, y
        self.new = False
        self.new_rp = False
        self.new_dy = False
        self.last_yaw = 0

        # rolling median
        # self.yaw_buffer = deque(maxlen=5)

    # def process_data(self, data: Union[int, tuple[int, int]], msg_id=0):
    def process_data(self, data, msg_id=0):
        # Pitch & Roll
        print(data)
        if msg_id == 19:
            new_pitch, new_roll = data
            new_pitch = -new_pitch # correct direction for rpy
            new_roll = -new_roll
            if (self.depth_imu_msg.pitch != new_pitch):
                self.depth_imu_msg.pitch = new_pitch
                self.new_rp = True
                # self._update_timer["pitch"] = time.time()
            if (new_roll != self.depth_imu_msg.roll):
                self.depth_imu_msg.roll = new_roll
                self.new_rp = True
                # self._update_timer["roll"] = time.time()
        # Yaw
        elif msg_id == 20:
            new_yaw, new_depth = data
            new_yaw = -new_yaw
            new_depth = -max(min((new_depth), 2.0), 0.0)
            if (self.depth_imu_msg.yaw != new_yaw):
                self.depth_imu_msg.yaw = new_yaw
                self.new_dy = True
                # self._update_timer["yaw"] = time.time()
            if (self.depth_imu_msg.depth != new_depth):
                self.depth_imu_msg.depth = new_depth
                self.new_dy = True
            # new_yaw, new_depth = data
            # new_yaw = -new_yaw
            # real_yaw_diff = new_yaw - self.last_yaw
            # if (real_yaw_diff < -180): # wrap around case turning right. values go from positive to negative
            #     real_yaw_diff += 360
            # elif (real_yaw_diff > 180): # wrap around case turning left. values fgo from negative to positive
            #     real_yaw_diff -= 360
            # self.last_yaw = new_yaw

            # print(f"Last yaw:{self.last_yaw}, New yaw: {new_yaw}, Real yaw diff: {real_yaw_diff}")
            # new_depth = -max(min((new_depth+0.45), 2.0), 0.0)
            # if (real_yaw_diff != 0):
            #     self.depth_imu_msg.yaw = new_yaw + real_yaw_diff
            #     self.new_dy = True
            #     # self._update_timer["yaw"] = time.time()
            # if (self.depth_imu_msg.depth != new_depth):
            #     self.depth_imu_msg.depth = new_depth
            #     self.new_dy = True
            #     # self._update_timer["depth"] = time.time()

            

        # curr_time = time.time()
        # for timestamp in self.depth_imu_msg.values():
        #     if ((curr_time - timestamp) > 5): # reset sensor board if any one of the values remain the same for more than 5 seconds
        #         self.reset_sensors()

    # def reset_sensors(self):
    #     pass #TODO

    def boundAngle(self, angle):
        """
        Bound angle to [-pi, pi]
        """
        angle = angle % (2 * np.pi)
        if angle < -np.pi:
            return 2 * np.pi + angle
        elif angle > np.pi:
            return angle - 2 * np.pi
        else:
            return angle

    def correctIMU(self, currAtt):
        """
        Correct IMU by subtracting imuZero.
        """
        corrAtt = []
        for att, zero in zip(currAtt, IMU_ZERO):
            corrAtt.append(np.rad2deg(self.boundAngle(np.deg2rad(att) - np.deg2rad(zero))))

        return corrAtt

    
    def message(self) -> DepthIMU:
        # Fill in the header
        self.depth_imu_msg.header = Header()
        self.depth_imu_msg.header.frame_id = str(self.counter)
        self.counter += 1
        self.new = self.new_rp and self.new_dy # only publish if yaw roll and pitch values are all new
        self.new_rp = False
        self.new_y = False

        # # TODO: Race condition
        # currAtt = [self.depth_imu_msg.roll, self.depth_imu_msg.pitch, self.depth_imu_msg.yaw]
        # correctedAtt = self.correctIMU(currAtt)

        # self.depth_imu_msg.roll = correctedAtt[0]
        # self.depth_imu_msg.pitch = correctedAtt[1]
        # self.depth_imu_msg.yaw = correctedAtt[2]
        
        return self.depth_imu_msg

    def log_info(self) -> str:
        return f"""Depth published: {round(self.depth_imu_msg.depth,5)} & IMU data published: [Roll: {round(self.depth_imu_msg.roll,5)}, Pitch: {round(self.depth_imu_msg.pitch,5)}, Yaw: {round(self.depth_imu_msg.yaw, 5)}]"""

class BatteryHandler(SensorHandler):
    def __init__(self, node: Node, log: bool):
        super().__init__(node, log)
        self.battery_msg = Battery()
        self._publisher = self.node.create_publisher(Battery, "/sensors/battery", 10)
        self.new = False

    def process_data(self, data, msg_id=0):
        self.battery_msg.voltage, self.battery_msg.current = data
        #TODO Cutoff programs
        
    def message(self) -> Battery:
        return self.battery_msg
    
    def log_info(self) -> str:
        return f"Voltage published: {self.battery_msg.voltage}, Current published: {self.battery_msg.current}"
    
class StartSwitchHandler(SensorHandler):
    def __init__(self, node: Node, log: bool):
        super().__init__(node, log)
        self.start_msg = Bool()
        self._publisher = self.node.create_publisher(Bool, "/command/start", 10)
        self.new = False
        self.start = False

    def process_data(self):
        self.new = True
        self.start = not self.start
        self.start_msg.data = self.start
        #TODO Cutoff programs
        
    def message(self) -> Battery:
        return self.start_msg
    
    def log_info(self) -> str:
        return f"Start: {self.start_msg.data}"

# class DepthHandler(SensorHandler):
#     def __init__(self, node: Node, log: bool):
#         super().__init__(node, log)
#         self.depth_msg = Float32()
#         self._publisher = self.node.create_publisher(Float32, "/sensors/depth_imu", 10)
#         self.new = True

#     def process_data(self, data, msg_id=0):
#         if data != self.depth_msg.data:
#             self.depth_msg.data = -(data-0.14)
#             self.new = True

#     def message(self) -> Float32:
#         return self.depth_msg

#     def log_info(self) -> str:
#         return f"Depth published: {self.depth_msg.data}"

#TODO Acoustics
