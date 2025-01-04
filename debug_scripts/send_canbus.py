import time

import can
import numpy as np

bus = can.interface.Bus(interface="socketcan", channel="can0", bitrate=500000)
# tihs data worked
# data = [1,2,3,4,5,6,7,8]
data_test = np.array(
    [127, 127, 127, 127, 127, 127, 127, 127], dtype=int
)  # the entries are of type np.int64
# print(type(data[0]))
msg = can.Message(arbitration_id=1, data=data_test, is_extended_id=False)

with bus as bus:
    while True:
        time.sleep(0.5)
        try:
            bus.send(msg)
            print("message sent")
        except can.CanError as error:
            print("buffer flushed")
            print(error)
            print("message not sent")
