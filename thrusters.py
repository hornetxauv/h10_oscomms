import can

# bus = can.interface.Bus(interface="socketcan", channel="can0", bitrate=500000)
# msg = can.Message(
#   arbitration_id=123,
#   data=[1, 2, 3, 4, 5, 6, 7, 8],
#   is_extended_id=False
# )

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


with bus as bus:
    try:
        bus.send(t_msg)
        print("message sent")
    except can.CanError as error:
        print(error)
        print("message not sent")