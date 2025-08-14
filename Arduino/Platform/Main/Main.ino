//This is the main program for the Arduino in the UUV.
//Every other program needs to be included here so that their functions can be called.

//List of programs to include in this program when it's compiled
//Note that each #include line is replaced with the ENTIRE content of the specified file
//before the program is compiled
//For now, files will be located in the same directory as the main program
#include "Main.h"

#define SER4RX 13 //Receive pin for serial 4 (software serial)
#define SER4TX 12 //Transmit pin for serial 4 (software serial)

//Pins that each thruster communicates over
#define THRUSTER1PIN 2
#define THRUSTER2PIN 3
#define THRUSTER3PIN 4
#define THRUSTER4PIN 5
#define THRUSTER5PIN 6
#define THRUSTER6PIN 7
#define THRUSTER7PIN 8
#define THRUSTER8PIN 9

#define COM 0x55 //Control signal to tell ultrasonic sensors to take a reading

const int ESC_MAX = 1880; //Maximum value to send to ESC
const int ESC_MIN = 1100; //Minimum value to send to ESC

union uSerial
{
  HardwareSerial* hardware;
  SoftwareSerial* software;
};

//Software serial object, used for communicating with fourth ultrasonic sensor
SoftwareSerial Serial4 = SoftwareSerial(SER4RX, SER4TX);

//Array to hold the 4 Serial connections used for ultrasonic sensors so they can be iterated over
uSerial sensorSerial[4];

//Keep track of which ultrasonic sensor is active so they can be pinged one at a time to avoid interference
int active_ult_son_sensor = 0;

//Flag to keep track of whether the ultrasonic sensor is waiting for a response ping or not
bool sensor_awaiting_response = false;

//What time (ms) the last ping was sent from an ultrasonic sensor
unsigned long last_ping_time = 0;

//Maximum amount of time (ms) we're willing to wait before we consider the ping a failure and move on
unsigned long max_ping_wait_time = 100;

//Buffers for Ultrasonic sensors
unsigned char ult_son_buff[4][4];

//Checksums for Ultrasonic sensors
uint8_t checksum[4];

//Distance readings from Ultrasonic sensors
int distance[4];

int old_distance[4];

//Accelerometer data from each IMU
sensors_event_t accel[3];

//Gyroscope data from each IMU
sensors_event_t gyro[3];

//Magnetometer data from each IMU
sensors_event_t magnet[3];

//Temperature data from each IMU
sensors_event_t temp[3];

//Current throttle level for each thruster
int throttle1 = 0;
int throttle2 = 0;
int throttle3 = 0;
int throttle4 = 0;
int throttle5 = 0;
int throttle6 = 0;
int throttle7 = 0;
int throttle8 = 0;

//"MatchState" object, for interacting with Regular Expressions library
MatchState ms;

//Command string from last received message from the Pi
String command = "";

//Identifier for the object to perform the command on from last received message from the Pi
int identifier = 0;

//Value passed as argument for the command from the last received message from the Pi
int value = 0;

//Index of the current element of the command being interpreted
int cmd_idx = 0;

//Objects representing each of the IMU/Magnetometer chips in the vehicle
Adafruit_LSM6DSOX chip_OX_1;
Adafruit_LIS3MDL chip_MDL_1;
Adafruit_ICM20948 chip_948_1;
Adafruit_ICM20948 chip_948_2;

//Servo objects for interacting with the thrusters of the vehicle
Servo thruster1;
Servo thruster2;
Servo thruster3;
Servo thruster4;
Servo thruster5;
Servo thruster6;
Servo thruster7;
Servo thruster8;

//This function runs once, when the Arduino is first powered up.
//This is where initialization, configuration, etc. should be added.
void setup()
{
  unsigned long t1 = 0;
  //Primary serial connection, used to communicate with Raspberry Pi
  Serial.begin(115200);
  while (!Serial){;}
  Serial.flush();

  
  //Serial communication to first Ultrasonic Sensor
  //Pins: RX=19, TX=18
  Serial1.begin(115200);
  while (!Serial1){;}
  Serial1.flush();
  
  //Serial communication to second Ultrasonic Sensor
  //Pins: RX=17, TX=16
  Serial2.begin(115200);
  while (!Serial2){;}
  Serial2.flush();

  //Serial communication to third Ultrasonic Sensor
  //Pins: RX=15, TX=14
  Serial3.begin(115200);
  while (!Serial3){;}
  Serial3.flush();

  //Serial communication to fourth Ultrasonic Sensor
  pinMode(SER4RX, INPUT);
  pinMode(SER4TX, OUTPUT);
  Serial4.begin(115200);
  while (!Serial4){;}
  Serial4.flush();
  
  
  sensorSerial[0].hardware = &Serial1;
  sensorSerial[1].hardware = &Serial2;
  sensorSerial[2].hardware = &Serial3;
  sensorSerial[3].software = &Serial4;/*

  //Begin I2C communication with the IMU/Magnetometer chips
  chip_OX_1.begin_I2C(0x6A);
  chip_MDL_1.begin_I2C(0x1C);
  chip_948_1.begin_I2C(0x69);
  chip_948_2.begin_I2C(0x68);
  */

  //Attach the ESCs to their corresponding servo object
  thruster1.attach(THRUSTER1PIN, ESC_MIN, ESC_MAX);
  thruster2.attach(THRUSTER2PIN, ESC_MIN, ESC_MAX);
  thruster3.attach(THRUSTER3PIN, ESC_MIN, ESC_MAX);
  thruster4.attach(THRUSTER4PIN, ESC_MIN, ESC_MAX);
  thruster5.attach(THRUSTER5PIN, ESC_MIN, ESC_MAX);
  thruster6.attach(THRUSTER6PIN, ESC_MIN, ESC_MAX);
  thruster7.attach(THRUSTER7PIN, ESC_MIN, ESC_MAX);
  thruster8.attach(THRUSTER8PIN, ESC_MIN, ESC_MAX);

  //Set all thrusters to zero on startup
  int start_value = map(0, -100, 100, ESC_MIN, ESC_MAX);
  thruster1.write(start_value);
  thruster2.write(start_value);
  thruster3.write(start_value);
  thruster4.write(start_value);
  thruster5.write(start_value);
  thruster6.write(start_value);
  thruster7.write(start_value);
  thruster8.write(start_value);

  //Once setup is finished, send "READY" to Raspberry Pi
  //Serial.println("READY");

  //DISABLED IN FAVOR OF SIMPLER SYSTEM
  //Turn on the IMU & Magnetometer units
  //It's important to do this before starting the Serial connection, because the built-in init functions try to send messages over it
  //int sensor_count = init_IMUs();

  //Store pointers to each IMU or magnetometer unit in the device list
  //register_IMUs(devices, sizeof(devices));
  
  //Start the primary serial connection with a baud rate of 115200
  //start_serial(115200);
  
  //Serial.println();
  //Serial.println(sensor_count);

  //sensor_t sensor;
  //devices[0].pChip_OX->getAccelerometerSensor()->getSensor(&sensor);
  //Serial.println(sensor.sensor_id);
  //Serial.println(devices[1].pChip_OX->getAccelRange());

  /*for (int i = 0; i < sensor_count; i++)
  {
    
    //Serial.println(sensor.sensor_id);
  }*/
  
}

//This function is called repeatedly for as long as the Arduino has power.
//Anything that needs to happen constantly/continuously should be here.
void loop()
{
  //Read message from Pi, if available
  if (Serial.available() > 0)
  {
    //Get the string in the serial buffer, and turn it into a char array
    String message = Serial.readStringUntil('\n');
    char msg_array[32];
    message.toCharArray(msg_array, sizeof(msg_array));
    //Set the target of the Match State object to the string
    ms.Target(msg_array);
    //Initialize the variables where the parts of the command will be stored
    command = "";
    identifier = 0;
    value = 0;
    //Initialize the index of which part of the command is being parsed to zero
    cmd_idx = 0;
    //Match the target string with the pattern, and run the callback function for each match
    unsigned int count = ms.GlobalMatch("(%S+)", matchCallback);
  }
  
  //Set throttle for each thruster according to message from Pi
  if (command == "MOTOR")
  {
    //Map the value from scale of -100-100 to scale of ESC_MIN to ESC_MAX
    int throttle = map(value, -100, 100, ESC_MIN, ESC_MAX);
    //Depending which motor is specified, set that motor to the throttle value
    switch (identifier)
    {
      case 1:
        throttle1 = throttle;
        Serial.print("DEBUG ");
        Serial.print("Motor1 ");
        Serial.println(throttle);
        thruster1.write(throttle1);
        break;
      case 2:
        throttle2 = throttle;
        Serial.print("DEBUG ");
        Serial.print("Motor2 ");
        Serial.println(throttle);
        thruster2.write(throttle2);
        break;
      case 3:
        throttle3 = throttle;
        Serial.print("DEBUG ");
        Serial.print("Motor3 ");
        Serial.println(throttle);
        thruster3.write(throttle3);
        break;
      case 4:
        throttle4 = throttle;
        Serial.print("DEBUG ");
        Serial.print("Motor4 ");
        Serial.println(throttle);
        thruster4.write(throttle4);
        break;
      case 5:
        throttle5 = throttle;
        Serial.print("DEBUG ");
        Serial.print("Motor5 ");
        Serial.println(throttle);
        thruster5.write(throttle5);
        break;
      case 6:
        throttle6 = throttle;
        Serial.print("DEBUG ");
        Serial.print("Motor6 ");
        Serial.println(throttle);
        thruster6.write(throttle6);
        break;
      case 7:
        throttle7 = throttle;
        Serial.print("DEBUG ");
        Serial.print("Motor7 ");
        Serial.println(throttle);
        thruster7.write(throttle7);
        break;
      case 8:
        throttle8 = throttle;
        Serial.print("DEBUG ");
        Serial.print("Motor8 ");
        Serial.println(throttle);
        thruster8.write(throttle8);
        break;
      case 0:
        Serial.print("DEBUG ");
        Serial.print("All Motors ");
        Serial.println(throttle);
        throttle1 = throttle;
        throttle2 = throttle;
        throttle3 = throttle;
        throttle4 = throttle;
        throttle5 = throttle;
        throttle6 = throttle;
        throttle7 = throttle;
        throttle8 = throttle;
        thruster1.write(throttle1);
        thruster2.write(throttle2);
        thruster3.write(throttle3);
        thruster4.write(throttle4);
        thruster5.write(throttle5);
        thruster6.write(throttle6);
        thruster7.write(throttle7);
        thruster8.write(throttle8);
        break;
      case 1234:
        Serial.print("DEBUG ");
        Serial.print("Motors 1,2,3,4 ");
        Serial.println(throttle);
        throttle1 = throttle;
        throttle2 = throttle;
        throttle3 = throttle;
        throttle4 = throttle;
        thruster1.write(throttle1);
        thruster2.write(throttle2);
        thruster3.write(throttle3);
        thruster4.write(throttle4);
        break;
      case 5678:
        Serial.print("DEBUG ");
        Serial.print("Motors 5,6,7,8 ");
        Serial.println(throttle);
        throttle5 = throttle;
        throttle6 = throttle;
        throttle7 = throttle;
        throttle8 = throttle;
        thruster5.write(throttle5);
        thruster6.write(throttle6);
        thruster7.write(throttle7);
        thruster8.write(throttle8);
        break;
      case 14:
        Serial.print("DEBUG ");
        Serial.print("Motors 1,4 ");
        Serial.println(throttle);
        throttle1 = throttle;
        throttle4 = throttle;
        thruster1.write(throttle1);
        thruster4.write(throttle4);
        break;
      case 23:
        Serial.print("DEBUG ");
        Serial.print("Motors 2,3 ");
        Serial.println(throttle);
        throttle2 = throttle;
        throttle3 = throttle;
        thruster2.write(throttle2);
        thruster3.write(throttle3);
        break;
    }
    command = "";
  }
  /*
  //Read current state of IMUs
  chip_OX_1.getEvent(&accel[0], &gyro[0], &temp[0]);
  chip_MDL_1.getEvent(&magnet[0]);
  chip_948_1.getEvent(&accel[1], &gyro[1], &temp[1], &magnet[1]);
  chip_948_2.getEvent(&accel[2], &gyro[2], &temp[2], &magnet[2]);

  //Send data from accel, gyro, and magnet from each IMU to Pi
  
  for (int i = 0; i < 3; i++)
  {
    Serial.print("ACCEL ");
    Serial.print(i + 1);
    Serial.print(" ");
    Serial.print(accel[i].acceleration.x, 10);
    Serial.print(" ");
    Serial.print(accel[i].acceleration.y, 10);
    Serial.print(" ");
    Serial.print(accel[i].acceleration.z, 10);
    Serial.println();

    Serial.print("GYRO ");
    Serial.print(i + 1);
    Serial.print(" ");
    Serial.print(gyro[i].gyro.x, 10);
    Serial.print(" ");
    Serial.print(gyro[i].gyro.y, 10);
    Serial.print(" ");
    Serial.print(gyro[i].gyro.z, 10);
    Serial.println();

    Serial.print("MAGNET ");
    Serial.print(i + 1);
    Serial.print(" ");
    Serial.print(magnet[i].magnetic.x, 10);
    Serial.print(" ");
    Serial.print(magnet[i].magnetic.y), 10;
    Serial.print(" ");
    Serial.print(magnet[i].magnetic.z, 10);
    Serial.println();
  }
  */
  
  //Read current state of Ultrasonic Sensors
  if (active_ult_son_sensor < 3)
  {
    //Serial.println("One of the hardware ones");
    if (!sensor_awaiting_response)
    {
      //Serial.println("Not waiting, so time to ping");
      sensorSerial[active_ult_son_sensor].hardware->write(COM);
      last_ping_time = millis();
      sensor_awaiting_response = true;
      //delay(2);
    }
    else
    {
      if (millis() - last_ping_time > max_ping_wait_time)
      {
        distance[active_ult_son_sensor] = -1;
        sensor_awaiting_response = false;
        sensorSerial[active_ult_son_sensor].hardware->end();
        active_ult_son_sensor ++;
        if (active_ult_son_sensor > 3)
        {
          active_ult_son_sensor = 0;
        }

        if (active_ult_son_sensor < 3)
        {
          sensorSerial[active_ult_son_sensor].hardware->begin(115200);
        }
        else
        {
          sensorSerial[active_ult_son_sensor].software->begin(115200);
        }
      }
    }
    if (sensorSerial[active_ult_son_sensor].hardware->available() >= 4)
    {
      int data = sensorSerial[active_ult_son_sensor].hardware->read();
      //Serial.println(data, HEX);
      if (data == 0xFF)
      {
        ult_son_buff[active_ult_son_sensor][0] = 0xFF;
        //Serial.println("Got a response for a sensor");
        for (int i = 1; i < 4; i++)
        {
          ult_son_buff[active_ult_son_sensor][i] = sensorSerial[active_ult_son_sensor].hardware->read();
        }
        checksum[active_ult_son_sensor] = ult_son_buff[active_ult_son_sensor][0] + ult_son_buff[active_ult_son_sensor][1] + ult_son_buff[active_ult_son_sensor][2];

        if (ult_son_buff[active_ult_son_sensor][3] == checksum[active_ult_son_sensor])
        {
          //Serial.println("Checksum is correct");
          distance[active_ult_son_sensor] = (ult_son_buff[active_ult_son_sensor][1] << 8) + ult_son_buff[active_ult_son_sensor][2];
          sensorSerial[active_ult_son_sensor].hardware->end();
          active_ult_son_sensor ++;
          sensor_awaiting_response = false;
          if (active_ult_son_sensor > 3)
          {
            active_ult_son_sensor = 0;
          }

          if (active_ult_son_sensor < 3)
          {
            sensorSerial[active_ult_son_sensor].hardware->begin(115200);
          }
          else
          {
           sensorSerial[active_ult_son_sensor].software->begin(115200);
          }
        }
      }
    }
  }
  else
  {
    //Serial.println("The Software one");
    if (!sensor_awaiting_response)
    {
      //Serial.println("Not waiting, ping");
      sensorSerial[active_ult_son_sensor].software->write(COM);
      last_ping_time = millis();
      sensor_awaiting_response = true;
      //delay(2);
    }
    else
    {
      if (millis() - last_ping_time > max_ping_wait_time)
      {
        distance[active_ult_son_sensor] = -1;
        sensor_awaiting_response = false;
        sensorSerial[active_ult_son_sensor].software->end();
        active_ult_son_sensor ++;
        if (active_ult_son_sensor > 3)
        {
          active_ult_son_sensor = 0;
        }
        sensorSerial[active_ult_son_sensor].hardware->begin(115200);
      }
    }
    if (sensorSerial[active_ult_son_sensor].software->available() >= 4)
    {
      if (sensorSerial[active_ult_son_sensor].software->read() == 0xFF)
      {
        ult_son_buff[active_ult_son_sensor][0] = 0xFF;
        for (int i = 1; i < 4; i++)
        {
          ult_son_buff[active_ult_son_sensor][i] = sensorSerial[active_ult_son_sensor].software->read();
        }
        checksum[active_ult_son_sensor] = ult_son_buff[active_ult_son_sensor][0] + ult_son_buff[active_ult_son_sensor][1] + ult_son_buff[active_ult_son_sensor][2];

        if (ult_son_buff[active_ult_son_sensor][3] == checksum[active_ult_son_sensor])
        {
          distance[active_ult_son_sensor] = (ult_son_buff[active_ult_son_sensor][1] << 8) + ult_son_buff[active_ult_son_sensor][2];
          sensorSerial[active_ult_son_sensor].software->end();
          active_ult_son_sensor ++;
          sensor_awaiting_response = false;
          if (active_ult_son_sensor > 3)
          {
            active_ult_son_sensor = 0;
          }
          sensorSerial[active_ult_son_sensor].hardware->begin(115200);
        }
      }
    }
  }
  //Send distance data from each ultrasonic sensor to pi
  for (int i = 0; i < 4; i++)
  {
    if (distance[i] != old_distance[i])
    {
      Serial.print("USONIC ");
      Serial.print(i + 1);
      Serial.print(" ");
      Serial.print(distance[i]);
      Serial.println();
      old_distance[i] = distance[i];
    }
  }
  
  //DISABLED IN FAVOR OF SIMPLER SYSTEM
  /*uint8_t message[8]; //Initialize variable to hold the 8-byte message
  size_t message_size = read_serial(message); //Read a message and return its size (8 if successful, or 0 if no message)
  
  //If there was a message received
  if (message_size != 0)
  {
    parse_message(message); //Logic to determine what to do with the message is in here
  }
  */
}

//Callback function for Regexp matching
void matchCallback (const char * match, const unsigned int length, const MatchState & ms)
{
  //Depending on what index of the command we're at...
  switch (cmd_idx)
  {
    //Store the first part of the message as the comand string
    case 0:
      char capture[8];
      ms.GetCapture(capture, cmd_idx);
      command = capture;
      break;
    //Store the second part of the message as the identifier for which component of the vehicle the command should act on
    case 1:
      identifier = atoi(match);
      break;
    //Store the third part of the message as the value to use for the command
    case 2:
      value = atoi(match);
      break;
  }
  //Increment the index so the next time the function is called, it stores the next part of the command
  cmd_idx++;
}

//DISABLED IN FAVOR OF SIMPLER MESSAGE SYSTEM
/*
//Parse message to figure out which function should be called
void parse_message(uint8_t message[8])
{
  uint8_t message_prefix = message[0]; //First byte of the message
  uint8_t message_address = message[1]; //Second byte of the message

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
      if (message_address == 0x00)
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
    //Thruster timeout
    case THRUSTER_TIMEOUT:

      break;
    
    //Thruster throttle
    case THRUSTER_THROTTLE:

      break;
    
    //--Sensor category--
    //Sensor update interval
    case SENSOR_UPDATE_INTERVAL:

      break;
    
    //Sensor start
    case SENSOR_START:

      break;
    
    //Sensor stop
    case SENSOR_STOP:

      break;
    
    //--No match--
    default:
      report_unknown_message(message);
      break;
  }
}
*/