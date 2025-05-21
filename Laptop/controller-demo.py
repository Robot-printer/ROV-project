#!./laptop-python-venv/bin/python3
from inputs import get_gamepad

#On an XBox controller, these are the values to match `event.code` to:
#=======The following are of ev_type "Absolute"=======:
#----CONTROL STICKS----
#Left stick LEFT/RIGHT: ABS_X
#Left stick UP/DOWN: ABS_Y
#Right stick LEFT/RIGHT: ABS_RX
#Right stick UP/DOWN: ABS_RY
#----D-PAD----
#D-pad UP/DOWN: ABS_HAT0Y
#D-PAD LEFT/RIGHT: ABS_HAT0X
#----TRIGGERS----
#Left Trigger: ABS_Z
#Right Trigger: ABS_RZ
#=======The following are of ev_type "Key"=======:
#----BUTTONS----
#Button "Y": BTN_NORTH
#Button "B": BTN_EAST
#Button "A": BTN_SOUTH
#Button "X": BTN_WEST
#Button "Start": BTN_START
#Button "Select": BTN_SELECT
#Button "XBOX": BTN_MODE
#Bumper/Shoulder Left: BTN_TL
#Bumper/Shoulder Right: BTN_TR
#Control Stick Left Press: BTN_THUMBL
#Control Stick Right Press: BTN_THUMBR


max_LX = 0
min_LX = 0
max_LY = 0
min_LY = 0

max_RX = 0
min_RX = 0
max_RY = 0
min_RY = 0


calibrated = False

def calibrate():
    global max_LX
    global min_LX
    global max_LY
    global min_LY
    global max_RX
    global min_RX
    global max_RY
    global min_RY
    events = get_gamepad()
    for event in events:
        if event.ev_type == "Absolute":
            value = event.state
            match event.code:
                case "ABS_X":
                    if value > max_LX:
                        max_LX = value
                        #print("Left stick max X:", max_LX)
                    if value < min_LX:
                        min_LX = value
                        #print("Left stick min X:", min_LX)
                case "ABS_Y":
                    if value > max_LY:
                        max_LY = value
                        #print("Left stick max Y:", max_LY)
                    if value < min_LX:
                        min_LY = value
                        #print("Left stick min y:", min_LY)
                case "ABS_RX":
                    if value > max_RX:
                        max_RX = value
                        #print("Right stick max X:", max_RX)
                    if value < min_LX:
                        min_RX = value
                        #print("Right stick min X:", min_RX)
                case "ABS_RY":
                    if value > max_RY:
                        max_RY = value
                        #print("Right stick max Y:", max_RY)
                    if value < min_LX:
                        min_RY = value
                        #print("Right stick min Y:", min_RY)

while 1:
    events = get_gamepad()
    for event in events:
        if event.ev_type == "Key":
            print(event.code, event.state)
        if event.ev_type == "Absolute":
            print(event.code, event.state)
#             if not (event.code == "ABS_X" or event.code == "ABS_Y" or event.code == "ABS_RX" or event.code == "ABS_RY"):
#                 print(event.code, event.state)

# while not calibrated:
#     calibrate()
#     events = get_gamepad()
#     for event in events:
#         if event.ev_type == "Key":
#             calibrated = True
# 
# print("Left stick max X:", max_LX)
# print("Left stick min X:", min_LX)
# print("Left stick max Y:", max_LY)
# print("Left stick min y:", min_LY)
# print("Right stick max X:", max_RX)
# print("Right stick min X:", min_RX)
# print("Right stick max Y:", max_RY)
# print("Right stick min Y:", min_RY)