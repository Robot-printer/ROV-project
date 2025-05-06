#Defining constants for message prefixes to make message parse logic more human readable
#--Debug Category--
ECHO_CONTROL = 0x00
ECHO_SIMPLE = 0x01
ECHO_MODIFY = 0x02
ECHO_LOGS = 0x03
DEBUG_PRINT = 0x0E
UNKNOWN_MESSAGE = 0x0F
#--Initialization category--
ID_QUERY = 0x10
DEVICE_QUERY = 0x11
ACTUATOR_ID = 0x12
SENSOR_ID = 0x13
SERIAL_READY = 0x1F
#--Thruster category--
THRUSTER_TIMEOUT = 0x20
THRUSTER_THROTTLE = 0x21
#--Sensor category--
SENSOR_UPDATE_INTERVAL = 0x30
SENSOR_START = 0x31
SENSOR_DATA = 0x32
SENSOR_STOP = 0x3F