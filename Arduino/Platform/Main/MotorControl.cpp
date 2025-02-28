//This script controls the motors on the UUV

#include "MotorControl.h"

void attach_servo(Servo servo, int pin_number)
{
    servo.attach(pin_number);
}
