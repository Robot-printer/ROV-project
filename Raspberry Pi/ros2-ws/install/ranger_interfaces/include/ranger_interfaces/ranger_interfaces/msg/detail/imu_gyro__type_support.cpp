// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from ranger_interfaces:msg/IMUGyro.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "ranger_interfaces/msg/detail/imu_gyro__functions.h"
#include "ranger_interfaces/msg/detail/imu_gyro__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace ranger_interfaces
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void IMUGyro_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) ranger_interfaces::msg::IMUGyro(_init);
}

void IMUGyro_fini_function(void * message_memory)
{
  auto typed_message = static_cast<ranger_interfaces::msg::IMUGyro *>(message_memory);
  typed_message->~IMUGyro();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember IMUGyro_message_member_array[4] = {
  {
    "id",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT64,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ranger_interfaces::msg::IMUGyro, id),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "x",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ranger_interfaces::msg::IMUGyro, x),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "y",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ranger_interfaces::msg::IMUGyro, y),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "z",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ranger_interfaces::msg::IMUGyro, z),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers IMUGyro_message_members = {
  "ranger_interfaces::msg",  // message namespace
  "IMUGyro",  // message name
  4,  // number of fields
  sizeof(ranger_interfaces::msg::IMUGyro),
  false,  // has_any_key_member_
  IMUGyro_message_member_array,  // message members
  IMUGyro_init_function,  // function to initialize message memory (memory has to be allocated)
  IMUGyro_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t IMUGyro_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &IMUGyro_message_members,
  get_message_typesupport_handle_function,
  &ranger_interfaces__msg__IMUGyro__get_type_hash,
  &ranger_interfaces__msg__IMUGyro__get_type_description,
  &ranger_interfaces__msg__IMUGyro__get_type_description_sources,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace ranger_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<ranger_interfaces::msg::IMUGyro>()
{
  return &::ranger_interfaces::msg::rosidl_typesupport_introspection_cpp::IMUGyro_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, ranger_interfaces, msg, IMUGyro)() {
  return &::ranger_interfaces::msg::rosidl_typesupport_introspection_cpp::IMUGyro_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
