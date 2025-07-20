// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from ranger_interfaces:msg/ThrusterThrottle.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "ranger_interfaces/msg/thruster_throttle.hpp"


#ifndef RANGER_INTERFACES__MSG__DETAIL__THRUSTER_THROTTLE__TRAITS_HPP_
#define RANGER_INTERFACES__MSG__DETAIL__THRUSTER_THROTTLE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "ranger_interfaces/msg/detail/thruster_throttle__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace ranger_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const ThrusterThrottle & msg,
  std::ostream & out)
{
  out << "{";
  // member: id
  {
    out << "id: ";
    rosidl_generator_traits::value_to_yaml(msg.id, out);
    out << ", ";
  }

  // member: value
  {
    out << "value: ";
    rosidl_generator_traits::value_to_yaml(msg.value, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ThrusterThrottle & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "id: ";
    rosidl_generator_traits::value_to_yaml(msg.id, out);
    out << "\n";
  }

  // member: value
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "value: ";
    rosidl_generator_traits::value_to_yaml(msg.value, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ThrusterThrottle & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace ranger_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use ranger_interfaces::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const ranger_interfaces::msg::ThrusterThrottle & msg,
  std::ostream & out, size_t indentation = 0)
{
  ranger_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use ranger_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const ranger_interfaces::msg::ThrusterThrottle & msg)
{
  return ranger_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<ranger_interfaces::msg::ThrusterThrottle>()
{
  return "ranger_interfaces::msg::ThrusterThrottle";
}

template<>
inline const char * name<ranger_interfaces::msg::ThrusterThrottle>()
{
  return "ranger_interfaces/msg/ThrusterThrottle";
}

template<>
struct has_fixed_size<ranger_interfaces::msg::ThrusterThrottle>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<ranger_interfaces::msg::ThrusterThrottle>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<ranger_interfaces::msg::ThrusterThrottle>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // RANGER_INTERFACES__MSG__DETAIL__THRUSTER_THROTTLE__TRAITS_HPP_
