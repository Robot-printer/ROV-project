#ifndef COMMS_H
#define COMMS_H

//Need to manually include HardwareSerial.h since this is not a .ino file
#include <HardwareSerial.h>

#include "MessagePrefixes.h"

//Wrapper to start the serial connection
void start_serial(long baud_rate);

//Wrapper to read an 8-byte message and return the size of it (which should also be 8)
size_t read_serial(uint8_t message[8]);

//Wrapper to write an 8-byte message and return the size of it (which should also be 8)
size_t write_serial(uint8_t message[8]);

//Tell the Raspberry Pi that a message was not recognized
size_t report_unknown_message(uint8_t message[8]);

//Send a message to verify that this is the Arduino
size_t verify_id();

//Debug function to repeat all received messages back to the sender
int echo_serial();

//Turn a(n) (un)signed integer into a format that can be sent as the "data" portion of a message
size_t package_int(long long value, uint8_t package[6]);

//Turn a floating-point number into a format that can be sent as the "data" portion of a message.
size_t package_float(double value, uint8_t package[6]);

#endif