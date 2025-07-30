// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from ranger_interfaces:msg/WaypointDistance.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "ranger_interfaces/msg/waypoint_distance.h"


#ifndef RANGER_INTERFACES__MSG__DETAIL__WAYPOINT_DISTANCE__STRUCT_H_
#define RANGER_INTERFACES__MSG__DETAIL__WAYPOINT_DISTANCE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

/// Struct defined in msg/WaypointDistance in the package ranger_interfaces.
typedef struct ranger_interfaces__msg__WaypointDistance
{
  int64_t id;
  double value;
} ranger_interfaces__msg__WaypointDistance;

// Struct for a sequence of ranger_interfaces__msg__WaypointDistance.
typedef struct ranger_interfaces__msg__WaypointDistance__Sequence
{
  ranger_interfaces__msg__WaypointDistance * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ranger_interfaces__msg__WaypointDistance__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // RANGER_INTERFACES__MSG__DETAIL__WAYPOINT_DISTANCE__STRUCT_H_
