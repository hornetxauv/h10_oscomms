import can
bus = can.interface.Bus(interface='socketcan', channel='can0', bitrate=500000)

with can.Bus() as bus:
    msg = can.Message(
        arbitration_id=0,
        data=[0, 25, 0, 1, 3, 1, 4, 1],
        is_extended_id=False # not sure if this is supposed to be true!
    )
    try:
        bus.send(msg)
        print(f"Message sent on {bus.channel_info}")
    except can.CanError:
        print("Message NOT sent")