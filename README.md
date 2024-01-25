
# CAN Commands
## Kill All Thrusters
```
cansend can0 000#7F7F7F7F7F7F7F7F
```
Alternatively, use the alias.
```
kill-thrusters
```
## Set All Thrusters to 145
```
cansend can0 000#9191919191917F7F
```
## Set Side Thrusters to 149 
```
cansend can0 000#7F7F957F957F7F7F
```

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

# Start Job
## Start/Stop
```
sudo systemctl start h9
sudo systemctl stop h9
```
## Disable/Enable
```
sudo systemctl disable h9
sudo systemctl enable h9
```
