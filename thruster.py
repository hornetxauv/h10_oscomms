import can
import time
bus = can.interface.Bus(interface="socketcan", channel="can0", bitrate=500000)

#use decimal values, last 2 are useless values
x = 127
#test
# integrate with control the x need to chnage and the if else remove
with bus as bus:
    while True:
        try:
            t_msg = can.Message(
                arbitration_id = 0, data = [x, x, x, x, x, x, 0, 0], is_extended_id = False
            )
            bus.send(t_msg)
            print("thruster_val", x)
            time.sleep(0.5)
            if x == 170:
                x = 127
            else:
                x = 140
        except can.CanError as error:
            print(error)
            print("message not sent")

