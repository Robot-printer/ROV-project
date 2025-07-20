// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ranger_interfaces:msg/IMUAccel.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "ranger_interfaces/msg/imu_accel.hpp"


#ifndef RANGER_INTERFACES__MSG__DETAIL__IMU_ACCEL__BUILDER_HPP_
#define RANGER_INTERFACES__MSG__DETAIL__IMU_ACCEL__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "ranger_interfaces/msg/detail/imu_accel__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace ranger_interfaces
{

namespace msg
{

namespace builder
{

class Init_IMUAccel_z
{
public:
  explicit Init_IMUAccel_z(::ranger_interfaces::msg::IMUAccel & msg)
  : msg_(msg)
  {}
  ::ranger_interfaces::msg::IMUAccel z(::ranger_interfaces::msg::IMUAccel::_z_type arg)
  {
    msg_.z = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ranger_interfaces::msg::IMUAccel msg_;
};

class Init_IMUAccel_y
{
public:
  explicit Init_IMUAccel_y(::ranger_interfaces::msg::IMUAccel & msg)
  : msg_(msg)
  {}
  Init_IMUAccel_z y(::ranger_interfaces::msg::IMUAccel::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_IMUAccel_z(msg_);
  }

private:
  ::ranger_interfaces::msg::IMUAccel msg_;
};

class Init_IMUAccel_x
{
public:
  explicit Init_IMUAccel_x(::ranger_interfaces::msg::IMUAccel & msg)
  : msg_(msg)
  {}
  Init_IMUAccel_y x(::ranger_interfaces::msg::IMUAccel::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_IMUAccel_y(msg_);
  }

private:
  ::ranger_interfaces::msg::IMUAccel msg_;
};

class Init_IMUAccel_id
{
public:
  Init_IMUAccel_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_IMUAccel_x id(::ranger_interfaces::msg::IMUAccel::_id_type arg)
  {
    msg_.id = std::move(arg);
    return Init_IMUAccel_x(msg_);
  }

private:
  ::ranger_interfaces::msg::IMUAccel msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::ranger_interfaces::msg::IMUAccel>()
{
  return ranger_interfaces::msg::builder::Init_IMUAccel_id();
}

}  // namespace ranger_interfaces

#endif  // RANGER_INTERFACES__MSG__DETAIL__IMU_ACCEL__BUILDER_HPP_
