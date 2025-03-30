#ifndef COMMS_H
#define COMMS_H

//Need to manually include HardwareSerial.h since this is not a .ino file
#include <HardwareSerial.h>

void send_log();

//Wrapper to start the serial connection
void start_serial(long baud_rate);

//Wrapper to read an 8-byte message and return the size of it (which should also be 8)
size_t read_serial(uint8_t message[8]);

//Wrapper to write an 8-byte message and return the size of it (which should also be 8)
size_t write_serial(uint8_t message[8]);

//Debug program to repeat all received messages back to the sender
int echo_serial();

#endif