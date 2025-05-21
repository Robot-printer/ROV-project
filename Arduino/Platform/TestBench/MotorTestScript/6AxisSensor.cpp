// Basic demo for accelerometer & gyro readings from Adafruit
// LSM6DSO32 sensor

//EVERYTHING IN HERE IS LARGELY THE DEMO CODE, SUBJECT TO CHANGE

#include "6AxisSensor.h"

//Object representing the sensor
Adafruit_LSM6DSO32 dso32;

bool initialize_dso32(void) {

  Serial.println("Initializing accelerometer & gyroscope...");

  if (!dso32.begin_I2C()) {
    Serial.println("Failed to find LSM6DSO32 chip");
    return false;
  }

  Serial.println("LSM6DSO32 Found!");

  dso32.setAccelRange(LSM6DSO32_ACCEL_RANGE_8_G);

  // dso32.setGyroRange(LSM6DS_GYRO_RANGE_250_DPS);
  // dso32.setAccelDataRate(LSM6DS_RATE_12_5_HZ);
  // dso32.setGyroDataRate(LSM6DS_RATE_12_5_HZ);

  return true;
}

void sensor_test_loop() {

  //  /* Get a new normalized sensor event */
  sensors_event_t accel;
  sensors_event_t gyro;
  sensors_event_t temp;
  dso32.getEvent(&accel, &gyro, &temp);

  /* Display the results (acceleration is measured in m/s^2) */
  Serial.print("\t\tAccel X: ");
  Serial.print(accel.acceleration.x);
  Serial.print(" \tY: ");
  Serial.print(accel.acceleration.y);
  Serial.print(" \tZ: ");
  Serial.print(accel.acceleration.z);
  Serial.println(" m/s^2 ");

  /* Display the results (rotation is measured in rad/s) */
  /*
  Serial.print("\t\tGyro X: ");
  Serial.print(gyro.gyro.x);
  Serial.print(" \tY: ");
  Serial.print(gyro.gyro.y);
  Serial.print(" \tZ: ");
  Serial.print(gyro.gyro.z);
  Serial.println(" radians/s ");
  Serial.println();*/

}
