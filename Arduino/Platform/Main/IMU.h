#ifndef IMU_H
#define IMU_H

#include <Adafruit_LSM6DSO32.h>
#include <Adafruit_LSM6DSOX.h>
#include <Adafruit_LIS3MDL.h>
#include <Adafruit_ICM20948.h>
#include "Common.h"

uint8_t init_IMUs();

size_t register_IMUs(device* devs, size_t size);

#endif