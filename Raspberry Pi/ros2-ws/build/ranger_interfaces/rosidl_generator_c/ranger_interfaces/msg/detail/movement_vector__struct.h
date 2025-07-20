// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from ranger_interfaces:msg/MovementVector.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "ranger_interfaces/msg/movement_vector.h"


#ifndef RANGER_INTERFACES__MSG__DETAIL__MOVEMENT_VECTOR__STRUCT_H_
#define RANGER_INTERFACES__MSG__DETAIL__MOVEMENT_VECTOR__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

/// Struct defined in msg/MovementVector in the package ranger_interfaces.
typedef struct ranger_interfaces__msg__MovementVector
{
  double x;
  double y;
  double z;
} ranger_interfaces__msg__MovementVector;

// Struct for a sequence of ranger_interfaces__msg__MovementVector.
typedef struct ranger_interfaces__msg__MovementVector__Sequence
{
  ranger_interfaces__msg__MovementVector * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ranger_interfaces__msg__MovementVector__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // RANGER_INTERFACES__MSG__DETAIL__MOVEMENT_VECTOR__STRUCT_H_
