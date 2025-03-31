//Program for handling communication with Raspberry Pi

#include "Comms.h"

//Wrapper to start the serial connection
void start_serial(long baud_rate)
{
  //Start the Serial connection so that the Arduino and Raspberry Pi
  //can communicate with each other
  Serial.begin(baud_rate);
  //Wait for the Serial connection to open before doing anything else
  while(!Serial){}
  //Clear anything that might be in the serial buffers
  Serial.flush();
  //Send a "serial ready" message to the Raspberry Pi
  uint8_t message[8] = {0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
  write_serial(message);
}

//Wrapper to read an 8-byte message and return the size of it (which should also be 8)
size_t read_serial(uint8_t message[8])
{
  //Variable that will be returned at the end, initialize to 0
  size_t size = 0;
  //If there's anything in the input buffer
  if (Serial.available() > 0)
  {
    //Read 8 bytes and store it in message, and store the length of the read operation
    size = Serial.readBytesUntil('\n', message, 8);
  }
  //Return the size of the message that was read
  return size;
}

//Wrapper to write an 8-byte message and return the size of it (which should also be 8)
size_t write_serial(uint8_t message[8])
{
  //Variable that will be returned at the end, initialize to 0
  size_t size = 0;
  //If there's 8 bytes free in output buffer
  if (Serial.availableForWrite() >= 8)
  {
    //Write the message and store its size
    size = Serial.write(message, 8);
  }
  //Return the size of the message that was sent
  return size;
}

//Tell the Raspberry Pi that a message was not recognized
size_t report_unknown_message(uint8_t message[8])
{
  uint8_t report[8];
  //First byte indicates "unknown message"
  report[0] = 0x0F;
  //Last two bytes report the first two bytes from the unknown message
  report[6] = message[0];
  report[7] = message[1];

  return write_serial(report);
}

//Send a message to verify that this is the Arduino
size_t verify_id()
{
  uint8_t response[8];
  response[0] = 0x10;
  response[1] = 0x02;
  return write_serial(response);
}

//Debug program to repeat all received messages back to the sender
int echo_serial()
{
  //Size of the message we read
  size_t size = 0;
  //Array of bytes that makes up the message
  uint8_t message[8];

  //Read a message and record its size
  size = read_serial(message);

  //If the size of the message is 8 bytes
  if (size == 8)
  {
    //Write the message we received, and remove its size from the size of what we read
    size -= write_serial(message);

    //If the new size is 0 (read message size minus sent message size)
    if (size == 0)
    {
      //Return that the message was echoed successfully
      return 1;
    }
    else
    {
      //Return that the message was not echoed successfully
      return -1;
    }
  }

  //Return that there was no suitable message to echo
  return 0;
}
