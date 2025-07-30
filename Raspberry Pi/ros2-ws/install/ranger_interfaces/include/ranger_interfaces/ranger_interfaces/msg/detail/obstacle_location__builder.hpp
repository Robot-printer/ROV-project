// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ranger_interfaces:msg/ObstacleLocation.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "ranger_interfaces/msg/obstacle_location.hpp"


#ifndef RANGER_INTERFACES__MSG__DETAIL__OBSTACLE_LOCATION__BUILDER_HPP_
#define RANGER_INTERFACES__MSG__DETAIL__OBSTACLE_LOCATION__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "ranger_interfaces/msg/detail/obstacle_location__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace ranger_interfaces
{

namespace msg
{

namespace builder
{

class Init_ObstacleLocation_z
{
public:
  explicit Init_ObstacleLocation_z(::ranger_interfaces::msg::ObstacleLocation & msg)
  : msg_(msg)
  {}
  ::ranger_interfaces::msg::ObstacleLocation z(::ranger_interfaces::msg::ObstacleLocation::_z_type arg)
  {
    msg_.z = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ranger_interfaces::msg::ObstacleLocation msg_;
};

class Init_ObstacleLocation_y
{
public:
  explicit Init_ObstacleLocation_y(::ranger_interfaces::msg::ObstacleLocation & msg)
  : msg_(msg)
  {}
  Init_ObstacleLocation_z y(::ranger_interfaces::msg::ObstacleLocation::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_ObstacleLocation_z(msg_);
  }

private:
  ::ranger_interfaces::msg::ObstacleLocation msg_;
};

class Init_ObstacleLocation_x
{
public:
  Init_ObstacleLocation_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ObstacleLocation_y x(::ranger_interfaces::msg::ObstacleLocation::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_ObstacleLocation_y(msg_);
  }

private:
  ::ranger_interfaces::msg::ObstacleLocation msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::ranger_interfaces::msg::ObstacleLocation>()
{
  return ranger_interfaces::msg::builder::Init_ObstacleLocation_x();
}

}  // namespace ranger_interfaces

#endif  // RANGER_INTERFACES__MSG__DETAIL__OBSTACLE_LOCATION__BUILDER_HPP_
