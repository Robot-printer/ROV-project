#ifndef MOTOR_CONTROL_H
#define MOTOR_CONTROL_H
//Declarations of variables, structures, etc.
#include <Servo.h>

//Wrapper function for attaching a servo to a pin on the Arduino
void attach_servo(Servo servo, int pin_number);

#endif
