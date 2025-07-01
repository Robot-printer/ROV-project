// Program for interacting with Accelerometer, Gyroscope, and Magnetometer sensor modules.
#include "IMU.h"

// Array for holding pointers to up to 2 LSM6DSO32 chips
Adafruit_LSM6DSO32* chip_O32[2];

// Array for holding pointers for up to 2 LSM6DSOX chips
Adafruit_LSM6DSOX* chip_OX[2];

// Array for holding pointers for up to 2 LIS3MDL chips
Adafruit_LIS3MDL* chip_MDL[2];

// Array for holding pointers for up to 2 ICM20948 chips
Adafruit_ICM20948* chip_948[2];

// There are 3 different sensor module types on the vehicle, and 4 total types of chip, each of which needs its own function to initialize it:
//
// LSM6DSO32 - Single chip module with accelerometer & gyroscope (I2C: 0x6A (default), 0x6B (alternative))
// LSM6DSOX+LIS3MDL - Double chip module, where one chip has accelerometer & gyroscope, and the other chip has magnetometer
// --LSM6DSOX - Accelerometer & gyroscope (I2C: 0x6A (default), 0x6B (alternative))
// -- --This chip uses the same I2C address set as LSM6DSO32, but has a different object class in the code
// --LIS3MDL - Magnetometer (I2C: 0x1C (default), 0x1E (alternative))
// ICM20948 - Single chip module with accelerometer, gyroscope, and magnetometer (I2C: 0x69 (default), 0x68 (alternative))

//Initialize all possible IMU chips and store pointers to them in arrays. Return the number of chips registered
uint8_t init_IMUs()
{
  //Temporarily turn off main serial connection, so that built-in I2C connection failed messages don't clog up the serial line
  Serial.end();

  //Number of chips registered during initialization
  uint8_t count = 0;

  //Loop through possible LSM6DSOX addresses and begin I2C communication with them, then register the chip in pointer array
  for (int i = 0; i < 2; i++)
  {
    //Since LSM6DSOX and LSM6DSO32 chips use the same address set, make sure neither of their pointer arrays have a chip registered at the current index
    if (chip_OX[i] == 0 && chip_O32[i] == 0)
    {
      Adafruit_LSM6DSOX chip;

      uint8_t addr = (i == 0) ? 0x6A : 0x6B; //If we're at index 0 (first chip) use default address, otherwise use alternative address
      
      //Try to begin I2C communication with the chip on the selected address
      if (chip.begin_I2C(addr))
      {
        //If successful, register the chip in the pointer array
        chip_OX[i] = &chip;
        count++;
      }
    }
  }

  //Loop through possible LSM6DSO32 addresses and begin I2C communication with them, then register the chip in pointer array
  for (int i = 0; i < 2; i++)
  {
    //Since LSM6DSOX and LSM6DSO32 chips use the same address set, make sure neither of their pointer arrays have a chip registered at the current index
    if (chip_OX[i] == 0 && chip_O32[i] == 0)
    {
      Adafruit_LSM6DSO32 chip;

      uint8_t addr = (i == 0) ? 0x6A : 0x6B; //If we're at index 0 (first chip) use default address, otherwise use alternative address

      //Try to begin I2C communication with the chip on the selected address
      if (chip.begin_I2C(addr))
      {
        //If successful, register the chip in the pointer array
        chip_O32[i] = &chip;
        count++;
      }
    }
  }

  //Loop through possible LIS3MDL addresses and begin I2C communication with them, then register the chip in pointer array
  for (int i = 0; i < 2; i++)
  {
    //Make sure there isn't a chip registered at the current index in the pointer array
    if (chip_MDL[i] == 0)
    {
      Adafruit_LIS3MDL chip;

      uint8_t addr = (i == 0) ? 0x1C : 0x1E; //If we're at index 0 (first chip) use default address, otherwise use alternative address

      //Try to begin I2C communication with the chip on the selected address
      if (chip.begin_I2C(addr))
      {
        //If successful, register the chip in the pointer array
        chip_MDL[i] = &chip;
        count++;
      }
    }
  }

  //Loop through possible ICM20948 addresses and begin I2C communication with them, then register the chip in pointer array
  for (int i = 0; i < 2; i++)
  {
    //Make sure there isn't a chip registered at the current index in the pointer array
    if (chip_948[i] == 0)
    {
      Adafruit_ICM20948 chip;

      uint8_t addr = (i == 0) ? 0x69 : 0x68; //If we're at index 0 (first chip) use default address, otherwise use alternative address

      
      //Try to begin I2C communication with the chip on the selected address
      if (chip.begin_I2C(addr))
      {
        //If successful, register the chip in the pointer array
        chip_948[i] = &chip;
        count++;
      }
    }
  }

  //Re-enable serial connection
  Serial.begin(115200);
  return count;
}

