// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from ranger_interfaces:msg/ObstacleLocation.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "ranger_interfaces/msg/obstacle_location.h"


#ifndef RANGER_INTERFACES__MSG__DETAIL__OBSTACLE_LOCATION__STRUCT_H_
#define RANGER_INTERFACES__MSG__DETAIL__OBSTACLE_LOCATION__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

/// Struct defined in msg/ObstacleLocation in the package ranger_interfaces.
typedef struct ranger_interfaces__msg__ObstacleLocation
{
  double x;
  double y;
  double z;
} ranger_interfaces__msg__ObstacleLocation;

// Struct for a sequence of ranger_interfaces__msg__ObstacleLocation.
typedef struct ranger_interfaces__msg__ObstacleLocation__Sequence
{
  ranger_interfaces__msg__ObstacleLocation * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ranger_interfaces__msg__ObstacleLocation__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // RANGER_INTERFACES__MSG__DETAIL__OBSTACLE_LOCATION__STRUCT_H_
