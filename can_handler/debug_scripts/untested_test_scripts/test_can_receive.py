import can
can_bus = can.interface.Bus(interface='socketcan', channel='can0', bitrate=500000)

with can_bus as bus:
    for msg in bus:
        print(msg.data)