import can

bus = can.interface.Bus(interface="socketcan", channel="can0", bitrate=500000)
msg1 = can.Message(
    arbitration_id=2, data=[2, 2, 2, 2, 2, 2, 2, 2], is_extended_id=False
)
msg2 = can.Message(
    arbitration_id=3, data=[2, 2, 2, 2, 2, 2, 2, 2], is_extended_id=False
)

with bus as bus:
    bus.send(msg1)
    bus.send(msg2)
