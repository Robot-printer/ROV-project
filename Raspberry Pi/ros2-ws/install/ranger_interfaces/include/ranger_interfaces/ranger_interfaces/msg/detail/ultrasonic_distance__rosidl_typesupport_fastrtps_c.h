// generated from rosidl_typesupport_fastrtps_c/resource/idl__rosidl_typesupport_fastrtps_c.h.em
// with input from ranger_interfaces:msg/UltrasonicDistance.idl
// generated code does not contain a copyright notice
#ifndef RANGER_INTERFACES__MSG__DETAIL__ULTRASONIC_DISTANCE__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_
#define RANGER_INTERFACES__MSG__DETAIL__ULTRASONIC_DISTANCE__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_


#include <stddef.h>
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "ranger_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "ranger_interfaces/msg/detail/ultrasonic_distance__struct.h"
#include "fastcdr/Cdr.h"

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_ranger_interfaces
bool cdr_serialize_ranger_interfaces__msg__UltrasonicDistance(
  const ranger_interfaces__msg__UltrasonicDistance * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_ranger_interfaces
bool cdr_deserialize_ranger_interfaces__msg__UltrasonicDistance(
  eprosima::fastcdr::Cdr &,
  ranger_interfaces__msg__UltrasonicDistance * ros_message);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_ranger_interfaces
size_t get_serialized_size_ranger_interfaces__msg__UltrasonicDistance(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_ranger_interfaces
size_t max_serialized_size_ranger_interfaces__msg__UltrasonicDistance(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_ranger_interfaces
bool cdr_serialize_key_ranger_interfaces__msg__UltrasonicDistance(
  const ranger_interfaces__msg__UltrasonicDistance * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_ranger_interfaces
size_t get_serialized_size_key_ranger_interfaces__msg__UltrasonicDistance(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_ranger_interfaces
size_t max_serialized_size_key_ranger_interfaces__msg__UltrasonicDistance(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_ranger_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, ranger_interfaces, msg, UltrasonicDistance)();

#ifdef __cplusplus
}
#endif

#endif  // RANGER_INTERFACES__MSG__DETAIL__ULTRASONIC_DISTANCE__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_
