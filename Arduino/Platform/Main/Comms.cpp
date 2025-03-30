//Program for handling communication with Raspberry Pi

#include "Comms.h"

int message_in_count = 0;
int message_out_count = 0;

void send_log()
{
  Serial.println(message_in_count);
  Serial.println(message_out_count);
}

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
    message_in_count += 1;
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
    message_out_count += 1;
  }
  //Return the size of the message that was sent
  return size;
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