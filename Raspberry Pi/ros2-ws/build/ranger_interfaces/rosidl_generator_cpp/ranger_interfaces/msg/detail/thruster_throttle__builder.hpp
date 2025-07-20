// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ranger_interfaces:msg/ThrusterThrottle.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "ranger_interfaces/msg/thruster_throttle.hpp"


#ifndef RANGER_INTERFACES__MSG__DETAIL__THRUSTER_THROTTLE__BUILDER_HPP_
#define RANGER_INTERFACES__MSG__DETAIL__THRUSTER_THROTTLE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "ranger_interfaces/msg/detail/thruster_throttle__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace ranger_interfaces
{

namespace msg
{

namespace builder
{

class Init_ThrusterThrottle_value
{
public:
  explicit Init_ThrusterThrottle_value(::ranger_interfaces::msg::ThrusterThrottle & msg)
  : msg_(msg)
  {}
  ::ranger_interfaces::msg::ThrusterThrottle value(::ranger_interfaces::msg::ThrusterThrottle::_value_type arg)
  {
    msg_.value = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ranger_interfaces::msg::ThrusterThrottle msg_;
};

class Init_ThrusterThrottle_id
{
public:
  Init_ThrusterThrottle_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ThrusterThrottle_value id(::ranger_interfaces::msg::ThrusterThrottle::_id_type arg)
  {
    msg_.id = std::move(arg);
    return Init_ThrusterThrottle_value(msg_);
  }

private:
  ::ranger_interfaces::msg::ThrusterThrottle msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::ranger_interfaces::msg::ThrusterThrottle>()
{
  return ranger_interfaces::msg::builder::Init_ThrusterThrottle_id();
}

}  // namespace ranger_interfaces

#endif  // RANGER_INTERFACES__MSG__DETAIL__THRUSTER_THROTTLE__BUILDER_HPP_
