// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ranger_interfaces:msg/WaypointLocation.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "ranger_interfaces/msg/waypoint_location.hpp"


#ifndef RANGER_INTERFACES__MSG__DETAIL__WAYPOINT_LOCATION__BUILDER_HPP_
#define RANGER_INTERFACES__MSG__DETAIL__WAYPOINT_LOCATION__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "ranger_interfaces/msg/detail/waypoint_location__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace ranger_interfaces
{

namespace msg
{

namespace builder
{

class Init_WaypointLocation_z
{
public:
  explicit Init_WaypointLocation_z(::ranger_interfaces::msg::WaypointLocation & msg)
  : msg_(msg)
  {}
  ::ranger_interfaces::msg::WaypointLocation z(::ranger_interfaces::msg::WaypointLocation::_z_type arg)
  {
    msg_.z = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ranger_interfaces::msg::WaypointLocation msg_;
};

class Init_WaypointLocation_y
{
public:
  explicit Init_WaypointLocation_y(::ranger_interfaces::msg::WaypointLocation & msg)
  : msg_(msg)
  {}
  Init_WaypointLocation_z y(::ranger_interfaces::msg::WaypointLocation::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_WaypointLocation_z(msg_);
  }

private:
  ::ranger_interfaces::msg::WaypointLocation msg_;
};

class Init_WaypointLocation_x
{
public:
  explicit Init_WaypointLocation_x(::ranger_interfaces::msg::WaypointLocation & msg)
  : msg_(msg)
  {}
  Init_WaypointLocation_y x(::ranger_interfaces::msg::WaypointLocation::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_WaypointLocation_y(msg_);
  }

private:
  ::ranger_interfaces::msg::WaypointLocation msg_;
};

class Init_WaypointLocation_id
{
public:
  Init_WaypointLocation_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_WaypointLocation_x id(::ranger_interfaces::msg::WaypointLocation::_id_type arg)
  {
    msg_.id = std::move(arg);
    return Init_WaypointLocation_x(msg_);
  }

private:
  ::ranger_interfaces::msg::WaypointLocation msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::ranger_interfaces::msg::WaypointLocation>()
{
  return ranger_interfaces::msg::builder::Init_WaypointLocation_id();
}

}  // namespace ranger_interfaces

#endif  // RANGER_INTERFACES__MSG__DETAIL__WAYPOINT_LOCATION__BUILDER_HPP_
