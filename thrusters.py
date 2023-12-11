import can

bus = can.interface.Bus(interface="socketcan", channel="can0", bitrate=500000)

#use decimal values, last 2 are useless values
thrusters = [127, 127, 127, 127, 127, 127, 0, 0]

#process
for i in range(len(thrusters)):
    thrusters[i] = hex(thrusters[i])

print(thrusters)

t_msg = can.Message(
    arbitration_id=1,
    data = thrusters
    is_extended_id = False
)

#test

with bus as bus:
    try:
        bus.send(t_msg)
        print("message sent")
    except can.CanError as error:
        print(error)
        print("message not sent")