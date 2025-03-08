//This script controls the motors on the UUV

#include "MotorControl.h"

//Wrapper function for attaching a servo to a pin on the Arduino
void attach_servo(Servo servo, int pin_number)
{
    servo.attach(pin_number);
}
