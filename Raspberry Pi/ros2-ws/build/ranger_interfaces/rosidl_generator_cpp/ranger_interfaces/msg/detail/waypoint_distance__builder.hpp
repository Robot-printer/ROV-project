// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ranger_interfaces:msg/WaypointDistance.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "ranger_interfaces/msg/waypoint_distance.hpp"


#ifndef RANGER_INTERFACES__MSG__DETAIL__WAYPOINT_DISTANCE__BUILDER_HPP_
#define RANGER_INTERFACES__MSG__DETAIL__WAYPOINT_DISTANCE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "ranger_interfaces/msg/detail/waypoint_distance__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace ranger_interfaces
{

namespace msg
{

namespace builder
{

class Init_WaypointDistance_value
{
public:
  explicit Init_WaypointDistance_value(::ranger_interfaces::msg::WaypointDistance & msg)
  : msg_(msg)
  {}
  ::ranger_interfaces::msg::WaypointDistance value(::ranger_interfaces::msg::WaypointDistance::_value_type arg)
  {
    msg_.value = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ranger_interfaces::msg::WaypointDistance msg_;
};

class Init_WaypointDistance_id
{
public:
  Init_WaypointDistance_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_WaypointDistance_value id(::ranger_interfaces::msg::WaypointDistance::_id_type arg)
  {
    msg_.id = std::move(arg);
    return Init_WaypointDistance_value(msg_);
  }

private:
  ::ranger_interfaces::msg::WaypointDistance msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::ranger_interfaces::msg::WaypointDistance>()
{
  return ranger_interfaces::msg::builder::Init_WaypointDistance_id();
}

}  // namespace ranger_interfaces

#endif  // RANGER_INTERFACES__MSG__DETAIL__WAYPOINT_DISTANCE__BUILDER_HPP_
