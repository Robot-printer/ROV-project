// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from ranger_interfaces:msg/UltrasonicDistance.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "ranger_interfaces/msg/detail/ultrasonic_distance__rosidl_typesupport_introspection_c.h"
#include "ranger_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "ranger_interfaces/msg/detail/ultrasonic_distance__functions.h"
#include "ranger_interfaces/msg/detail/ultrasonic_distance__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void ranger_interfaces__msg__UltrasonicDistance__rosidl_typesupport_introspection_c__UltrasonicDistance_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  ranger_interfaces__msg__UltrasonicDistance__init(message_memory);
}

void ranger_interfaces__msg__UltrasonicDistance__rosidl_typesupport_introspection_c__UltrasonicDistance_fini_function(void * message_memory)
{
  ranger_interfaces__msg__UltrasonicDistance__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember ranger_interfaces__msg__UltrasonicDistance__rosidl_typesupport_introspection_c__UltrasonicDistance_message_member_array[2] = {
  {
    "id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT64,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ranger_interfaces__msg__UltrasonicDistance, id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "value",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT64,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ranger_interfaces__msg__UltrasonicDistance, value),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers ranger_interfaces__msg__UltrasonicDistance__rosidl_typesupport_introspection_c__UltrasonicDistance_message_members = {
  "ranger_interfaces__msg",  // message namespace
  "UltrasonicDistance",  // message name
  2,  // number of fields
  sizeof(ranger_interfaces__msg__UltrasonicDistance),
  false,  // has_any_key_member_
  ranger_interfaces__msg__UltrasonicDistance__rosidl_typesupport_introspection_c__UltrasonicDistance_message_member_array,  // message members
  ranger_interfaces__msg__UltrasonicDistance__rosidl_typesupport_introspection_c__UltrasonicDistance_init_function,  // function to initialize message memory (memory has to be allocated)
  ranger_interfaces__msg__UltrasonicDistance__rosidl_typesupport_introspection_c__UltrasonicDistance_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t ranger_interfaces__msg__UltrasonicDistance__rosidl_typesupport_introspection_c__UltrasonicDistance_message_type_support_handle = {
  0,
  &ranger_interfaces__msg__UltrasonicDistance__rosidl_typesupport_introspection_c__UltrasonicDistance_message_members,
  get_message_typesupport_handle_function,
  &ranger_interfaces__msg__UltrasonicDistance__get_type_hash,
  &ranger_interfaces__msg__UltrasonicDistance__get_type_description,
  &ranger_interfaces__msg__UltrasonicDistance__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_ranger_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, ranger_interfaces, msg, UltrasonicDistance)() {
  if (!ranger_interfaces__msg__UltrasonicDistance__rosidl_typesupport_introspection_c__UltrasonicDistance_message_type_support_handle.typesupport_identifier) {
    ranger_interfaces__msg__UltrasonicDistance__rosidl_typesupport_introspection_c__UltrasonicDistance_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &ranger_interfaces__msg__UltrasonicDistance__rosidl_typesupport_introspection_c__UltrasonicDistance_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
