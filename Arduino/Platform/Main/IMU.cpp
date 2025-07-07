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

//Total number of registered chips
int chip_count = 0;

// There are 3 different sensor module types on the vehicle, and 4 total types of chip, each of which needs its own function to initialize it:
//
// (DISABLED TO AVOID CONFLICTS) LSM6DSO32 - Single chip module with accelerometer & gyroscope (I2C: 0x6A (default), 0x6B (alternative))
// LSM6DSOX+LIS3MDL - Double chip module, where one chip has accelerometer & gyroscope, and the other chip has magnetometer
// --LSM6DSOX - Accelerometer & gyroscope (I2C: 0x6A (default), 0x6B (alternative))
// -- --This chip uses the same I2C address set as LSM6DSO32, but has a different object class in the code
// --LIS3MDL - Magnetometer (I2C: 0x1C (default), 0x1E (alternative))
// ICM20948 - Single chip module with accelerometer, gyroscope, and magnetometer (I2C: 0x69 (default), 0x68 (alternative))

//Initialize all possible IMU chips and store pointers to them in arrays. Return the number of chips registered
uint8_t init_IMUs()
{

  //Number of chips registered during initialization
  uint8_t count = 0;

  //Loop through possible LSM6DSOX addresses and begin I2C communication with them, then register the chip in pointer array
  for (int i = 0; i < 2; i++)
  {
    //Since LSM6DSOX and LSM6DSO32 chips use the same address set, make sure neither of their pointer arrays have a chip registered at the current index
    if (chip_OX[i] == 0 && chip_O32[i] == 0)
    {
      Adafruit_LSM6DSOX* chip = new Adafruit_LSM6DSOX();

      uint8_t addr = (i == 0) ? 0x6A : 0x6B; //If we're at index 0 (first chip) use default address, otherwise use alternative address
      
      //Try to begin I2C communication with the chip on the selected address
      if (chip->begin_I2C(addr))
      {
        //If successful, register the chip in the pointer array
        chip_OX[i] = chip;
        count++;
      }
    }
  }

  //DISABLED TO AVOID CONFLICTS
  /*
  //Loop through possible LSM6DSO32 addresses and begin I2C communication with them, then register the chip in pointer array
  for (int i = 0; i < 2; i++)
  {
    //Since LSM6DSOX and LSM6DSO32 chips use the same address set, make sure neither of their pointer arrays have a chip registered at the current index
    if (chip_OX[i] == 0 && chip_O32[i] == 0)
    {
      Adafruit_LSM6DSO32* chip = new Adafruit_LSM6DSO32();

      uint8_t addr = (i == 0) ? 0x6A : 0x6B; //If we're at index 0 (first chip) use default address, otherwise use alternative address

      //Try to begin I2C communication with the chip on the selected address
      if (chip->begin_I2C(addr))
      {
        //If successful, register the chip in the pointer array
        chip_O32[i] = chip;
        count++;
      }
    }
  }
  */

  //Loop through possible LIS3MDL addresses and begin I2C communication with them, then register the chip in pointer array
  for (int i = 0; i < 2; i++)
  {
    //Make sure there isn't a chip registered at the current index in the pointer array
    if (chip_MDL[i] == 0)
    {
      Adafruit_LIS3MDL* chip = new Adafruit_LIS3MDL();

      uint8_t addr = (i == 0) ? 0x1C : 0x1E; //If we're at index 0 (first chip) use default address, otherwise use alternative address

      //Try to begin I2C communication with the chip on the selected address
      if (chip->begin_I2C(addr))
      {
        //If successful, register the chip in the pointer array
        chip_MDL[i] = chip;
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
      Adafruit_ICM20948* chip = new Adafruit_ICM20948();

      uint8_t addr = (i == 0) ? 0x69 : 0x68; //If we're at index 0 (first chip) use default address, otherwise use alternative address

      
      //Try to begin I2C communication with the chip on the selected address
      if (chip->begin_I2C(addr))
      {
        //If successful, register the chip in the pointer array
        chip_948[i] = chip;
        count++;
      }
    }
  }

  chip_count = count;
  return count;
}

//"Register" the IMUs into the main program's primary device list
size_t register_IMUs(device* devs, size_t size)
{
  int count = 0;
  
  // Regsiter LSM6DSOX chips in main device list
  for (int i = 0; i < 2; i++)
  {
    if (chip_OX[i] != 0)
    {
      // Loop through main list until an open slot is found
      for (int j = 0; j < size; j++)
      {
        // Check to see if the slot is open
        if (devs[j].pChip_OX == 0)
        {
          // Store the pointer from the local list to the main list
          devs[j].pChip_OX = chip_OX[i];
          devs[j].type = CHIP_OX;
          count++;
          break;
        }
      }
    }
  }

  //DISABLED TO AVOID CONFLICTS
  /*
  // Regsiter LSM6DSO32 chips in main device list
  for (int i = 0; i < 2; i++)
  {
    // Check to make sure the local registry list has something
    if (chip_O32[i] != 0)
    {
      // Loop through main list until an open slot is found
      for (int j = 0; j < size; j++)
      {
        // Check to see if the slot is open
        if (devs[j].pChip_O32 == 0)
        {
          // Store the pointer from the local list to the main list
          devs[j].pChip_O32 = chip_O32[i];
          devs[j].type = CHIP_O32;
          count++;
          break;
        }
      }
    }
  }
  */

  // Regsiter LIS3MDL chips in main device list
  for (int i = 0; i < 2; i++)
  {
    if (chip_MDL[i] != 0)
    {
      // Loop through main list until an open slot is found
      for (int j = 0; j < size; j++)
      {
        // Check to see if the slot is open
        if (devs[j].pChip_MDL == 0)
        {
          // Store the pointer from the local list to the main list
          devs[j].pChip_MDL = chip_MDL[i];
          devs[j].type = CHIP_MDL;
          count++;
          break;
        }
      }
    }
  }

  // Regsiter ICM20948 chips in main device list
  for (int i = 0; i < 2; i++)
  {
    if (chip_948[i] != 0)
    {
      // Loop through main list until an open slot is found
      for (int j = 0; j < size; j++)
      {
        // Check to see if the slot is open
        if (devs[j].pChip_948 == 0)
        {
          // Store the pointer from the local list to the main list
          devs[j].pChip_948 = chip_948[i];
          devs[j].type = CHIP_948;
          count++;
          break;
        }
      }
    }
  }

  return count;
}