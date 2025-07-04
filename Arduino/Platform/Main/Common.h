#ifndef COMMON_H
#define COMMON_H
//File for common definitions, unions, structures, etc. that any program can access.

#include <Servo.h>

enum device_type
{
  SERVO = 0,
  CHIP_OX,
  //CHIP_O32,
  CHIP_MDL,
  CHIP_948
};

struct device
{
  device_type type;
  
  union
  {
    Servo* pServo;
    Adafruit_LSM6DSOX* pChip_OX;
    //Adafruit_LSM6DSO32* pChip_O32;
    Adafruit_LIS3MDL* pChip_MDL;
    Adafruit_ICM20948* pChip_948;
  };
};

/*
//Union to hold a pointer to any of the devices connected to the Arduino
union device_pointer
{
  Servo* servo;
  Adafruit_LSM6DSOX* chip_OX;
  Adafruit_LSM6DSO32* chip_O32;
  Adafruit_LIS3MDL* chip_MDL;
  Adafruit_ICM20948* chip_948;
};
*/

#endif