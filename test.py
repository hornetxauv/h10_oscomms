import can

bus = can.interface.Bus(interface="socketcan", channel="can0", bitrate=500000)
msg = can.Message(
  arbitration_id=123,
  data=[1, 2, 3, 4, 5, 6, 7, 8],
  is_extended_id=False
)


with bus as bus:
    try:
        bus.send(msg)
        print("message sent")
    except can.CanError as error:
        print(error)
        print("message not sent")
