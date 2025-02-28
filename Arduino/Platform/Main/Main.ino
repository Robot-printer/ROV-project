//This is the main program for the Arduino in the UUV. Every other program needs to be included here so that their functions can be called.

//List of programs to include in this program when it's compiled
//Note that each #include line is replaced with the ENTIRE content of the specified file before the program is compiled
//For now, files will be located in the same directory as the main program
#include "MotorControl.h"
#include "6AxisSensor.h"

#define test_pin 52
Servo test_servo;

//This function runs exactly once, when the Arduino is first powered up. This is where initialization, configuration, etc. should be added.
void setup()
{
  //Start the serial connection with a baud rate of 115200
  start_serial(115200);

  pinMode(test_pin, OUTPUT);
  attach_servo(test_servo, test_pin);

  test_setup();
  
}

//This function is called repeatedly for as long as the Arduino has power. Anything that needs to happen constantly/continuously should be here.
void loop()
{
  
  test_servo.write(90);
  test_loop();
  
}

//Wrapper to start the serial connection
void start_serial(long baud_rate)
{
  //Start the Serial connection so that the Arduino and Raspberry Pi can communicate with each other
  Serial.begin(baud_rate);
  //Wait for the Serial connection to open before doing anything else
  while(!Serial)
  {
    delay(10); //10ms
  }
}
