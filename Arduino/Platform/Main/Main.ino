//This is the main program for the Arduino in the UUV.
//Every other program needs to be included here so that their functions can be called.

//List of programs to include in this program when it's compiled
//Note that each #include line is replaced with the ENTIRE content of the specified file
//before the program is compiled
//For now, files will be located in the same directory as the main program
#include "MotorControl.h"
#include "6AxisSensor.h"
#include "Comms.h"

//This function runs once, when the Arduino is first powered up.
//This is where initialization, configuration, etc. should be added.
void setup()
{
  //Start the serial connection with a baud rate of 115200
  start_serial(115200);
}

//This function is called repeatedly for as long as the Arduino has power.
//Anything that needs to happen constantly/continuously should be here.
void loop()
{
  uint8_t message[8];
  size_t message_size = read_serial(message);
  if (message_size != 0)
  {
    if (((message[0] & 0xF0) == 0x10) && ((message[0] & 0x0F) == 0x00) && (message[1] == 0x01))
    {
      uint8_t query_response[8] = {0x10, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
      size_t response_size = write_serial(query_response);
    }
  }
  
  /*
  int result = echo_serial();
  if (result < 0)
  {
    Serial.print("ErrEchoM");
  }
  */
}
