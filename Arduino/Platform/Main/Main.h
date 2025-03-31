#ifndef MAIN_H
#define MAIN_H

#include "MotorControl.h"
#include "6AxisSensor.h"
#include "Comms.h"

//Macros for message parser to make code more human-readable
//Debug category
#define ECHO_CONTROL 0x00
#define ECHO_SIMPLE 0x01
#define ECHO_MODIFY 0x02
#define ECHO_LOGS 0x03
//Initialization category
#define ID_QUERY 0x10
//Thruster control category
#define THRUSTER_TIMEOUT 0x20
#define THRUSTER_THROTTLE 0x21
//Sensor category
#define SENSOR_UPDATE_INTERVAL 0x30
#define SENSOR_START 0x31
#define SENSOR_STOP 0x3F

//Parse message to figure out which function should be called
void parse_message(uint8_t message[8]);

#endif