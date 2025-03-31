//This is the main program for the Arduino in the UUV.
//Every other program needs to be included here so that their functions can be called.

//List of programs to include in this program when it's compiled
//Note that each #include line is replaced with the ENTIRE content of the specified file
//before the program is compiled
//For now, files will be located in the same directory as the main program
#include "Main.h"

//These include statements are redundant, as they are present in Main.h, but for now they'll stay here too
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
    
    parse_message(message);

  }
  
  /*
  int result = echo_serial();
  if (result < 0)
  {
    Serial.print("ErrEchoM");
  }
  */
}

//Parse message to figure out which function should be called
void parse_message(uint8_t message[8])
{
  uint8_t message_prefix = message[0];
  uint8_t message_address = message[1];

  //Take the first byte of the message and see what they match up with
  switch (message_prefix)
  {
    //--Debug category--
    //Echo Control
    case ECHO_CONTROL:
      
      break;
    //Echo simple
    case ECHO_SIMPLE:
          
      break;
        
    //Echo modify
    case ECHO_MODIFY:
          
      break;
        
    //Echo logs
    case ECHO_LOGS:
          
      break;
        
    //--Initialization category--
    //ID Query
    case ID_QUERY:
      if (message_address == 0x01)
        {
          //Send response message to verify that this is the Arduino
          verify_id();
        }
        else
        {
          report_unknown_message(message);
        }
      break;
    
    //--Thruster control category--
    case 0x20:

      break;
    
    //--Sensor category--
    case 0x30:

      break;
    
    //--No match--
    default:
      report_unknown_message(message);
      break;
  }
}