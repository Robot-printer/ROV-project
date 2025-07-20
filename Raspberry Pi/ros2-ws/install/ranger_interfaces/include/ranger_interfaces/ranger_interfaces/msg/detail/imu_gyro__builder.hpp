// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ranger_interfaces:msg/IMUGyro.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "ranger_interfaces/msg/imu_gyro.hpp"


#ifndef RANGER_INTERFACES__MSG__DETAIL__IMU_GYRO__BUILDER_HPP_
#define RANGER_INTERFACES__MSG__DETAIL__IMU_GYRO__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "ranger_interfaces/msg/detail/imu_gyro__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace ranger_interfaces
{

namespace msg
{

namespace builder
{

class Init_IMUGyro_z
{
public:
  explicit Init_IMUGyro_z(::ranger_interfaces::msg::IMUGyro & msg)
  : msg_(msg)
  {}
  ::ranger_interfaces::msg::IMUGyro z(::ranger_interfaces::msg::IMUGyro::_z_type arg)
  {
    msg_.z = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ranger_interfaces::msg::IMUGyro msg_;
};

class Init_IMUGyro_y
{
public:
  explicit Init_IMUGyro_y(::ranger_interfaces::msg::IMUGyro & msg)
  : msg_(msg)
  {}
  Init_IMUGyro_z y(::ranger_interfaces::msg::IMUGyro::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_IMUGyro_z(msg_);
  }

private:
  ::ranger_interfaces::msg::IMUGyro msg_;
};

class Init_IMUGyro_x
{
public:
  explicit Init_IMUGyro_x(::ranger_interfaces::msg::IMUGyro & msg)
  : msg_(msg)
  {}
  Init_IMUGyro_y x(::ranger_interfaces::msg::IMUGyro::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_IMUGyro_y(msg_);
  }

private:
  ::ranger_interfaces::msg::IMUGyro msg_;
};

class Init_IMUGyro_id
{
public:
  Init_IMUGyro_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_IMUGyro_x id(::ranger_interfaces::msg::IMUGyro::_id_type arg)
  {
    msg_.id = std::move(arg);
    return Init_IMUGyro_x(msg_);
  }

private:
  ::ranger_interfaces::msg::IMUGyro msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::ranger_interfaces::msg::IMUGyro>()
{
  return ranger_interfaces::msg::builder::Init_IMUGyro_id();
}

}  // namespace ranger_interfaces

#endif  // RANGER_INTERFACES__MSG__DETAIL__IMU_GYRO__BUILDER_HPP_
