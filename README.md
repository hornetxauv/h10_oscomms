# CAN Debug
## Loopback Test
```
sudo ip link set can0 down
sudo ip link set can0 type can bitrate 500000 loopback on
sudo ip link set can0 up
candump can0 &
cansend can0 123#abcdabcd
```

## Disable Loopback / Restart
Also in `~/poolTest_ws/restartCan.sh`.
```
sudo ip link set can0 down
sudo ip link set can0 type can bitrate 500000 loopback off
sudo ip link set can0 up type can bitrate 500000 dbitrate 1000000 berr-reporting on fd on
```

## Increase Buffer Queue Length
```
sudo ifconfig can0 txqueuelen 1000
```

## Show CAN Status
```
sudo ip -s -d link show can0
```