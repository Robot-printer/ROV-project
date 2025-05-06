#ifndef MESSAGE_PREFIXES_H
#define MESSAGE_PREFIXES_H

//Macros for message parser to make code more human-readable
//Debug category
#define ECHO_CONTROL 0x00
#define ECHO_SIMPLE 0x01
#define ECHO_MODIFY 0x02
#define ECHO_LOGS 0x03
#define DEBUG_PRINT 0x0E
#define UNKNOWN_MESSAGE 0x0F
//Initialization category
#define ID_QUERY 0x10
#define DEVICE_QUERY 0x11
#define ACTUATOR_ID 0x12
#define SENSOR_ID 0x13
#define SERIAL_READY 0x1F
//Thruster control category
#define THRUSTER_TIMEOUT 0x20
#define THRUSTER_THROTTLE 0x21
//Sensor category
#define SENSOR_UPDATE_INTERVAL 0x30
#define SENSOR_START 0x31
#define SENSOR_DATA 0x32
#define SENSOR_STOP 0x3F

#endif