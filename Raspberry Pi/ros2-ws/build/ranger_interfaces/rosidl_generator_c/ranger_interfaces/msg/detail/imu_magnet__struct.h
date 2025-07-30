// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from ranger_interfaces:msg/IMUMagnet.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "ranger_interfaces/msg/imu_magnet.h"


#ifndef RANGER_INTERFACES__MSG__DETAIL__IMU_MAGNET__STRUCT_H_
#define RANGER_INTERFACES__MSG__DETAIL__IMU_MAGNET__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

/// Struct defined in msg/IMUMagnet in the package ranger_interfaces.
typedef struct ranger_interfaces__msg__IMUMagnet
{
  int64_t id;
  double x;
  double y;
  double z;
} ranger_interfaces__msg__IMUMagnet;

// Struct for a sequence of ranger_interfaces__msg__IMUMagnet.
typedef struct ranger_interfaces__msg__IMUMagnet__Sequence
{
  ranger_interfaces__msg__IMUMagnet * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ranger_interfaces__msg__IMUMagnet__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // RANGER_INTERFACES__MSG__DETAIL__IMU_MAGNET__STRUCT_H_
