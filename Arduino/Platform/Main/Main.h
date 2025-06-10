#ifndef MAIN_H
#define MAIN_H

#include "MotorControl.h"
#include "6AxisSensor.h"
#include "Comms.h"
#include "MessagePrefixes.h"

//States/modes for the Arduino to be in
#define STBY 0x0 // "Standby". Do nothing, wait for instructions
#define DBUG 0x1 // "Debug". Use functions from debug program, including echo, etc.
#define INIT 0x2 // "Initialize". 


//Parse message to figure out which function should be called
void parse_message(uint8_t message[8]);

#endif