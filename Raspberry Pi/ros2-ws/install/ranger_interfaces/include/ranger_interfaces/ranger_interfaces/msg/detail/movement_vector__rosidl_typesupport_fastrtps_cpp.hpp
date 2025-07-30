// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__rosidl_typesupport_fastrtps_cpp.hpp.em
// with input from ranger_interfaces:msg/MovementVector.idl
// generated code does not contain a copyright notice

#ifndef RANGER_INTERFACES__MSG__DETAIL__MOVEMENT_VECTOR__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
#define RANGER_INTERFACES__MSG__DETAIL__MOVEMENT_VECTOR__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_

#include <cstddef>
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "ranger_interfaces/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"
#include "ranger_interfaces/msg/detail/movement_vector__struct.hpp"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

#include "fastcdr/Cdr.h"

namespace ranger_interfaces
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ranger_interfaces
cdr_serialize(
  const ranger_interfaces::msg::MovementVector & ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ranger_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  ranger_interfaces::msg::MovementVector & ros_message);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ranger_interfaces
get_serialized_size(
  const ranger_interfaces::msg::MovementVector & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ranger_interfaces
max_serialized_size_MovementVector(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ranger_interfaces
cdr_serialize_key(
  const ranger_interfaces::msg::MovementVector & ros_message,
  eprosima::fastcdr::Cdr &);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ranger_interfaces
get_serialized_size_key(
  const ranger_interfaces::msg::MovementVector & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ranger_interfaces
max_serialized_size_key_MovementVector(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace ranger_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ranger_interfaces
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, ranger_interfaces, msg, MovementVector)();

#ifdef __cplusplus
}
#endif

#endif  // RANGER_INTERFACES__MSG__DETAIL__MOVEMENT_VECTOR__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
