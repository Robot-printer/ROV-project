// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ranger_interfaces:msg/IMUMagnet.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "ranger_interfaces/msg/imu_magnet.hpp"


#ifndef RANGER_INTERFACES__MSG__DETAIL__IMU_MAGNET__BUILDER_HPP_
#define RANGER_INTERFACES__MSG__DETAIL__IMU_MAGNET__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "ranger_interfaces/msg/detail/imu_magnet__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace ranger_interfaces
{

namespace msg
{

namespace builder
{

class Init_IMUMagnet_z
{
public:
  explicit Init_IMUMagnet_z(::ranger_interfaces::msg::IMUMagnet & msg)
  : msg_(msg)
  {}
  ::ranger_interfaces::msg::IMUMagnet z(::ranger_interfaces::msg::IMUMagnet::_z_type arg)
  {
    msg_.z = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ranger_interfaces::msg::IMUMagnet msg_;
};

class Init_IMUMagnet_y
{
public:
  explicit Init_IMUMagnet_y(::ranger_interfaces::msg::IMUMagnet & msg)
  : msg_(msg)
  {}
  Init_IMUMagnet_z y(::ranger_interfaces::msg::IMUMagnet::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_IMUMagnet_z(msg_);
  }

private:
  ::ranger_interfaces::msg::IMUMagnet msg_;
};

class Init_IMUMagnet_x
{
public:
  explicit Init_IMUMagnet_x(::ranger_interfaces::msg::IMUMagnet & msg)
  : msg_(msg)
  {}
  Init_IMUMagnet_y x(::ranger_interfaces::msg::IMUMagnet::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_IMUMagnet_y(msg_);
  }

private:
  ::ranger_interfaces::msg::IMUMagnet msg_;
};

class Init_IMUMagnet_id
{
public:
  Init_IMUMagnet_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_IMUMagnet_x id(::ranger_interfaces::msg::IMUMagnet::_id_type arg)
  {
    msg_.id = std::move(arg);
    return Init_IMUMagnet_x(msg_);
  }

private:
  ::ranger_interfaces::msg::IMUMagnet msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::ranger_interfaces::msg::IMUMagnet>()
{
  return ranger_interfaces::msg::builder::Init_IMUMagnet_id();
}

}  // namespace ranger_interfaces

#endif  // RANGER_INTERFACES__MSG__DETAIL__IMU_MAGNET__BUILDER_HPP_
