// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from ranger_interfaces:msg/VehicleTransform.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "ranger_interfaces/msg/vehicle_transform.h"


#ifndef RANGER_INTERFACES__MSG__DETAIL__VEHICLE_TRANSFORM__STRUCT_H_
#define RANGER_INTERFACES__MSG__DETAIL__VEHICLE_TRANSFORM__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

/// Struct defined in msg/VehicleTransform in the package ranger_interfaces.
typedef struct ranger_interfaces__msg__VehicleTransform
{
  double x_pos;
  double y_pos;
  double z_pos;
  double x_rot;
  double y_rot;
  double z_rot;
} ranger_interfaces__msg__VehicleTransform;

// Struct for a sequence of ranger_interfaces__msg__VehicleTransform.
typedef struct ranger_interfaces__msg__VehicleTransform__Sequence
{
  ranger_interfaces__msg__VehicleTransform * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ranger_interfaces__msg__VehicleTransform__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // RANGER_INTERFACES__MSG__DETAIL__VEHICLE_TRANSFORM__STRUCT_H_
