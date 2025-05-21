#!../laptop-python-venv/bin/python3
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

#--Configuration variables--
#Calibration
stick_left_limits = [-65535/2, 65535/2, -65535/2, 65535/2] #minLX, maxLX, minLY, maxLY
stick_right_limits = [-65535/2, 65535/2, -65535/2, 65535/2] #minRX, maxRX, minRY, maxRY
trigger_limits = [0, 1023, 0, 1023] #minZX, maxZX, minZY, maxZY

#Deadzone
stick_left_deadzone = 0.1
stick_right_deadzone = 0.1

def calibrate_stick(stick_id:int):
    pass

def get_axis(axis_id:int):
    event = get_gamepad()
    if not event.ev_code = "Absolute":
        return
    
    axis_code = ""
    axis_min = 0
    axis_max = 0
    match axis_id:
        case 0:
            axis_code = "ABS_X"
            axis_min = stick_left_limits[0]
            axis_max = stick_left_limits[1]
        case 1:
            axis_code = "ABS_Y"
            axis_min = stick_left_limits[2]
            axis_max = stick_left_limits[3]
        case 2:
            axis_code = "ABS_RX"
            axis_min = stick_right_limits[0]
            axis_max = stick_right_limits[1]
        case 3:
            axis_code = "ABS_RY"
            axis_min = stick_right_limits[2]
            axis_max = stick_right_limits[3]
        case 4:
            axis_code = "ABS_Z"
        case 5:
            axis_code = "ABS_RZ"
        case _:
            return
    
    
    

def get_button_down(button_name:str):
    pass

def map_from_to(value, min_a, max_a, min_b, max_b):
    new_value = (value - min_a)/(max_a - min_a)*(max_b - min_b) + min_b
    return new_value