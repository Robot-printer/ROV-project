// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from ranger_interfaces:msg/WaypointLocation.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "ranger_interfaces/msg/waypoint_location.h"


#ifndef RANGER_INTERFACES__MSG__DETAIL__WAYPOINT_LOCATION__STRUCT_H_
#define RANGER_INTERFACES__MSG__DETAIL__WAYPOINT_LOCATION__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

/// Struct defined in msg/WaypointLocation in the package ranger_interfaces.
typedef struct ranger_interfaces__msg__WaypointLocation
{
  int64_t id;
  double x;
  double y;
  double z;
} ranger_interfaces__msg__WaypointLocation;

// Struct for a sequence of ranger_interfaces__msg__WaypointLocation.
typedef struct ranger_interfaces__msg__WaypointLocation__Sequence
{
  ranger_interfaces__msg__WaypointLocation * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ranger_interfaces__msg__WaypointLocation__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // RANGER_INTERFACES__MSG__DETAIL__WAYPOINT_LOCATION__STRUCT_H_
