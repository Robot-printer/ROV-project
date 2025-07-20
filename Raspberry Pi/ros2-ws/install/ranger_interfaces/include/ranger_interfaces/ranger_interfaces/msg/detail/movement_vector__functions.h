// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from ranger_interfaces:msg/MovementVector.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "ranger_interfaces/msg/movement_vector.h"


#ifndef RANGER_INTERFACES__MSG__DETAIL__MOVEMENT_VECTOR__FUNCTIONS_H_
#define RANGER_INTERFACES__MSG__DETAIL__MOVEMENT_VECTOR__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/action_type_support_struct.h"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_runtime_c/service_type_support_struct.h"
#include "rosidl_runtime_c/type_description/type_description__struct.h"
#include "rosidl_runtime_c/type_description/type_source__struct.h"
#include "rosidl_runtime_c/type_hash.h"
#include "rosidl_runtime_c/visibility_control.h"
#include "ranger_interfaces/msg/rosidl_generator_c__visibility_control.h"

#include "ranger_interfaces/msg/detail/movement_vector__struct.h"

/// Initialize msg/MovementVector message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * ranger_interfaces__msg__MovementVector
 * )) before or use
 * ranger_interfaces__msg__MovementVector__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_ranger_interfaces
bool
ranger_interfaces__msg__MovementVector__init(ranger_interfaces__msg__MovementVector * msg);

/// Finalize msg/MovementVector message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_ranger_interfaces
void
ranger_interfaces__msg__MovementVector__fini(ranger_interfaces__msg__MovementVector * msg);

/// Create msg/MovementVector message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * ranger_interfaces__msg__MovementVector__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_ranger_interfaces
ranger_interfaces__msg__MovementVector *
ranger_interfaces__msg__MovementVector__create(void);

/// Destroy msg/MovementVector message.
/**
 * It calls
 * ranger_interfaces__msg__MovementVector__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_ranger_interfaces
void
ranger_interfaces__msg__MovementVector__destroy(ranger_interfaces__msg__MovementVector * msg);

/// Check for msg/MovementVector message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_ranger_interfaces
bool
ranger_interfaces__msg__MovementVector__are_equal(const ranger_interfaces__msg__MovementVector * lhs, const ranger_interfaces__msg__MovementVector * rhs);

/// Copy a msg/MovementVector message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_ranger_interfaces
bool
ranger_interfaces__msg__MovementVector__copy(
  const ranger_interfaces__msg__MovementVector * input,
  ranger_interfaces__msg__MovementVector * output);

/// Retrieve pointer to the hash of the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_ranger_interfaces
const rosidl_type_hash_t *
ranger_interfaces__msg__MovementVector__get_type_hash(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_ranger_interfaces
const rosidl_runtime_c__type_description__TypeDescription *
ranger_interfaces__msg__MovementVector__get_type_description(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the single raw source text that defined this type.
ROSIDL_GENERATOR_C_PUBLIC_ranger_interfaces
const rosidl_runtime_c__type_description__TypeSource *
ranger_interfaces__msg__MovementVector__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the recursive raw sources that defined the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_ranger_interfaces
const rosidl_runtime_c__type_description__TypeSource__Sequence *
ranger_interfaces__msg__MovementVector__get_type_description_sources(
  const rosidl_message_type_support_t * type_support);

/// Initialize array of msg/MovementVector messages.
/**
 * It allocates the memory for the number of elements and calls
 * ranger_interfaces__msg__MovementVector__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_ranger_interfaces
bool
ranger_interfaces__msg__MovementVector__Sequence__init(ranger_interfaces__msg__MovementVector__Sequence * array, size_t size);

/// Finalize array of msg/MovementVector messages.
/**
 * It calls
 * ranger_interfaces__msg__MovementVector__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_ranger_interfaces
void
ranger_interfaces__msg__MovementVector__Sequence__fini(ranger_interfaces__msg__MovementVector__Sequence * array);

/// Create array of msg/MovementVector messages.
/**
 * It allocates the memory for the array and calls
 * ranger_interfaces__msg__MovementVector__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_ranger_interfaces
ranger_interfaces__msg__MovementVector__Sequence *
ranger_interfaces__msg__MovementVector__Sequence__create(size_t size);

/// Destroy array of msg/MovementVector messages.
/**
 * It calls
 * ranger_interfaces__msg__MovementVector__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_ranger_interfaces
void
ranger_interfaces__msg__MovementVector__Sequence__destroy(ranger_interfaces__msg__MovementVector__Sequence * array);

/// Check for msg/MovementVector message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_ranger_interfaces
bool
ranger_interfaces__msg__MovementVector__Sequence__are_equal(const ranger_interfaces__msg__MovementVector__Sequence * lhs, const ranger_interfaces__msg__MovementVector__Sequence * rhs);

/// Copy an array of msg/MovementVector messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_ranger_interfaces
bool
ranger_interfaces__msg__MovementVector__Sequence__copy(
  const ranger_interfaces__msg__MovementVector__Sequence * input,
  ranger_interfaces__msg__MovementVector__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // RANGER_INTERFACES__MSG__DETAIL__MOVEMENT_VECTOR__FUNCTIONS_H_
