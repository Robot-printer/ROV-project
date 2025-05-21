#ifndef _6_AXIS_SENSOR_H
#define _6_AXIS_SENSOR_H
//Definitions of variables, structures, etc.
#include <Adafruit_LSM6DSO32.h>

bool initialize_dso32(void);

void sensor_test_loop();

#endif
