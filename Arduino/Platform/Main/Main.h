#ifndef MAIN_H
#define MAIN_H

//Regular Expressions library, used for parsing messages
#include <Regexp.h>
//Libaries for the IMU chips used on the vehicle
#include <Adafruit_LSM6DSOX.h>
#include <Adafruit_LIS3MDL.h>
#include <Adafruit_ICM20948.h>
//Servo library for interacting with thrusters (ESC-controlled BLDC motors use the same interface as servos)
#include <Servo.h>
//Software Serial library, used to connect to the 4th Ultrasonic Sensor
#include <SoftwareSerial.h>

//Callback function that gets called when a matching string is found by the regexp parser
void matchCallback (const char * match,
                    const unsigned int length,
                    const MatchState & ms);

//#include "MotorControl.h"
//#include "6AxisSensor.h"
//#include "IMU.h"
//#include "Comms.h"
//#include "MessagePrefixes.h"
//#include "Common.h"

/*
//States (modes) for the Arduino to be in
#define STBY 0x0 // "Standby". Do nothing, wait for instructions
#define DBUG 0x1 // "Debug". Use functions from debug program, including echo, etc.
#define INIT 0x2 // "Initialize". Use functions to activate motors, configure sensors, etc.
#define MAIN 0x3 // "Main". Use functions for normal operation, like setting thrust levels, reading sensor data, etc.
#define RSET 0xD // "Reset". Set everything back to default settings in event of error.
#define ESTP 0xE // "Emergency Stop". Turn off all motors or other moving parts and go into Standby mode.
#define PDWN 0xF // "Power Down". Standard procedure for turning off all components and shutting off vehicle.

//Parse message to figure out which function should be called
void parse_message(uint8_t message[8]);
*/

#endif