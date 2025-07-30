// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from ranger_interfaces:msg/ThrusterThrottle.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "ranger_interfaces/msg/detail/thruster_throttle__functions.h"
#include "ranger_interfaces/msg/detail/thruster_throttle__struct.hpp"
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

void ThrusterThrottle_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) ranger_interfaces::msg::ThrusterThrottle(_init);
}

void ThrusterThrottle_fini_function(void * message_memory)
{
  auto typed_message = static_cast<ranger_interfaces::msg::ThrusterThrottle *>(message_memory);
  typed_message->~ThrusterThrottle();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember ThrusterThrottle_message_member_array[2] = {
  {
    "id",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT64,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ranger_interfaces::msg::ThrusterThrottle, id),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "value",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT64,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ranger_interfaces::msg::ThrusterThrottle, value),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers ThrusterThrottle_message_members = {
  "ranger_interfaces::msg",  // message namespace
  "ThrusterThrottle",  // message name
  2,  // number of fields
  sizeof(ranger_interfaces::msg::ThrusterThrottle),
  false,  // has_any_key_member_
  ThrusterThrottle_message_member_array,  // message members
  ThrusterThrottle_init_function,  // function to initialize message memory (memory has to be allocated)
  ThrusterThrottle_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t ThrusterThrottle_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &ThrusterThrottle_message_members,
  get_message_typesupport_handle_function,
  &ranger_interfaces__msg__ThrusterThrottle__get_type_hash,
  &ranger_interfaces__msg__ThrusterThrottle__get_type_description,
  &ranger_interfaces__msg__ThrusterThrottle__get_type_description_sources,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace ranger_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<ranger_interfaces::msg::ThrusterThrottle>()
{
  return &::ranger_interfaces::msg::rosidl_typesupport_introspection_cpp::ThrusterThrottle_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, ranger_interfaces, msg, ThrusterThrottle)() {
  return &::ranger_interfaces::msg::rosidl_typesupport_introspection_cpp::ThrusterThrottle_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
