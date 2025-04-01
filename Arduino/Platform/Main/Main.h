#ifndef MAIN_H
#define MAIN_H

#include "MotorControl.h"
#include "6AxisSensor.h"
#include "Comms.h"
#include "MessagePrefixes.h"

//Parse message to figure out which function should be called
void parse_message(uint8_t message[8]);

#endif