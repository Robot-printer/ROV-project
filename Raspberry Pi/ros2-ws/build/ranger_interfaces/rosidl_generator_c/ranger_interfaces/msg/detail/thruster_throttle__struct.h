// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from ranger_interfaces:msg/ThrusterThrottle.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "ranger_interfaces/msg/thruster_throttle.h"


#ifndef RANGER_INTERFACES__MSG__DETAIL__THRUSTER_THROTTLE__STRUCT_H_
#define RANGER_INTERFACES__MSG__DETAIL__THRUSTER_THROTTLE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

/// Struct defined in msg/ThrusterThrottle in the package ranger_interfaces.
typedef struct ranger_interfaces__msg__ThrusterThrottle
{
  int64_t id;
  int64_t value;
} ranger_interfaces__msg__ThrusterThrottle;

// Struct for a sequence of ranger_interfaces__msg__ThrusterThrottle.
typedef struct ranger_interfaces__msg__ThrusterThrottle__Sequence
{
  ranger_interfaces__msg__ThrusterThrottle * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ranger_interfaces__msg__ThrusterThrottle__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // RANGER_INTERFACES__MSG__DETAIL__THRUSTER_THROTTLE__STRUCT_H_
