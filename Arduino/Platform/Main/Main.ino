//This is the main program for the Arduino in the UUV. Every other program needs to be included here so that their functions can be called.

//List of programs to include in this program when it's compiled
//Note that each #include line is replaced with the ENTIRE content of the specified file before the program is compiled
//For now, files will be located in the same directory as the main program
#include "MotorControl.h"
#include "6AxisSensor.h"


//This function runs exactly once, when the Arduino is first powered up. This is where initialization, configuration, etc. should be added.
void setup()
{
  //Start the Serial connection so that the Arduino and Raspberry Pi can communicate with each other
  Serial.begin(115200);
  //Wait for the Serial connection to open before doing anything else
  while(!Serial)
  {
    delay(10); //10ms
  }
}

//This function is called repeatedly for as long as the Arduino has power. Anything that needs to happen constantly/continuously should be here.
void loop()
{
  
}
