// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from ranger_interfaces:msg/IMUGyro.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "ranger_interfaces/msg/imu_gyro.hpp"


#ifndef RANGER_INTERFACES__MSG__DETAIL__IMU_GYRO__TRAITS_HPP_
#define RANGER_INTERFACES__MSG__DETAIL__IMU_GYRO__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "ranger_interfaces/msg/detail/imu_gyro__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace ranger_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const IMUGyro & msg,
  std::ostream & out)
{
  out << "{";
  // member: id
  {
    out << "id: ";
    rosidl_generator_traits::value_to_yaml(msg.id, out);
    out << ", ";
  }

  // member: x
  {
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
    out << ", ";
  }

  // member: y
  {
    out << "y: ";
    rosidl_generator_traits::value_to_yaml(msg.y, out);
    out << ", ";
  }

  // member: z
  {
    out << "z: ";
    rosidl_generator_traits::value_to_yaml(msg.z, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const IMUGyro & msg,
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

  // member: x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
    out << "\n";
  }

  // member: y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "y: ";
    rosidl_generator_traits::value_to_yaml(msg.y, out);
    out << "\n";
  }

  // member: z
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "z: ";
    rosidl_generator_traits::value_to_yaml(msg.z, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const IMUGyro & msg, bool use_flow_style = false)
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
  const ranger_interfaces::msg::IMUGyro & msg,
  std::ostream & out, size_t indentation = 0)
{
  ranger_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use ranger_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const ranger_interfaces::msg::IMUGyro & msg)
{
  return ranger_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<ranger_interfaces::msg::IMUGyro>()
{
  return "ranger_interfaces::msg::IMUGyro";
}

template<>
inline const char * name<ranger_interfaces::msg::IMUGyro>()
{
  return "ranger_interfaces/msg/IMUGyro";
}

template<>
struct has_fixed_size<ranger_interfaces::msg::IMUGyro>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<ranger_interfaces::msg::IMUGyro>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<ranger_interfaces::msg::IMUGyro>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // RANGER_INTERFACES__MSG__DETAIL__IMU_GYRO__TRAITS_HPP_
