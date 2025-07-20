// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from ranger_interfaces:msg/VehicleTransform.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "ranger_interfaces/msg/vehicle_transform.hpp"


#ifndef RANGER_INTERFACES__MSG__DETAIL__VEHICLE_TRANSFORM__TRAITS_HPP_
#define RANGER_INTERFACES__MSG__DETAIL__VEHICLE_TRANSFORM__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "ranger_interfaces/msg/detail/vehicle_transform__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace ranger_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const VehicleTransform & msg,
  std::ostream & out)
{
  out << "{";
  // member: x_pos
  {
    out << "x_pos: ";
    rosidl_generator_traits::value_to_yaml(msg.x_pos, out);
    out << ", ";
  }

  // member: y_pos
  {
    out << "y_pos: ";
    rosidl_generator_traits::value_to_yaml(msg.y_pos, out);
    out << ", ";
  }

  // member: z_pos
  {
    out << "z_pos: ";
    rosidl_generator_traits::value_to_yaml(msg.z_pos, out);
    out << ", ";
  }

  // member: x_rot
  {
    out << "x_rot: ";
    rosidl_generator_traits::value_to_yaml(msg.x_rot, out);
    out << ", ";
  }

  // member: y_rot
  {
    out << "y_rot: ";
    rosidl_generator_traits::value_to_yaml(msg.y_rot, out);
    out << ", ";
  }

  // member: z_rot
  {
    out << "z_rot: ";
    rosidl_generator_traits::value_to_yaml(msg.z_rot, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const VehicleTransform & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: x_pos
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "x_pos: ";
    rosidl_generator_traits::value_to_yaml(msg.x_pos, out);
    out << "\n";
  }

  // member: y_pos
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "y_pos: ";
    rosidl_generator_traits::value_to_yaml(msg.y_pos, out);
    out << "\n";
  }

  // member: z_pos
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "z_pos: ";
    rosidl_generator_traits::value_to_yaml(msg.z_pos, out);
    out << "\n";
  }

  // member: x_rot
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "x_rot: ";
    rosidl_generator_traits::value_to_yaml(msg.x_rot, out);
    out << "\n";
  }

  // member: y_rot
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "y_rot: ";
    rosidl_generator_traits::value_to_yaml(msg.y_rot, out);
    out << "\n";
  }

  // member: z_rot
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "z_rot: ";
    rosidl_generator_traits::value_to_yaml(msg.z_rot, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const VehicleTransform & msg, bool use_flow_style = false)
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
  const ranger_interfaces::msg::VehicleTransform & msg,
  std::ostream & out, size_t indentation = 0)
{
  ranger_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use ranger_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const ranger_interfaces::msg::VehicleTransform & msg)
{
  return ranger_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<ranger_interfaces::msg::VehicleTransform>()
{
  return "ranger_interfaces::msg::VehicleTransform";
}

template<>
inline const char * name<ranger_interfaces::msg::VehicleTransform>()
{
  return "ranger_interfaces/msg/VehicleTransform";
}

template<>
struct has_fixed_size<ranger_interfaces::msg::VehicleTransform>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<ranger_interfaces::msg::VehicleTransform>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<ranger_interfaces::msg::VehicleTransform>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // RANGER_INTERFACES__MSG__DETAIL__VEHICLE_TRANSFORM__TRAITS_HPP_
