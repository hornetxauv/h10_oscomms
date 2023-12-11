import can
import time
bus = can.interface.Bus(interface="socketcan", channel="can0", bitrate=500000)

#use decimal values, last 2 are useless values
thrusters = [70, 70, 70, 70, 70, 70, 0, 0]

t_msg = can.Message(
    arbitration_id=0,
    data = thrusters,
    is_extended_id = False
)

#test

with bus as bus:
    while True:
        try:
            bus.send(t_msg)
            print("message sent")
            time.sleep(1)
        except can.CanError as error:
            print(error)
            print("message not sent")
