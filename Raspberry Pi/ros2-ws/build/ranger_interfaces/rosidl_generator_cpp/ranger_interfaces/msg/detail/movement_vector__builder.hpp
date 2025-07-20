// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ranger_interfaces:msg/MovementVector.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "ranger_interfaces/msg/movement_vector.hpp"


#ifndef RANGER_INTERFACES__MSG__DETAIL__MOVEMENT_VECTOR__BUILDER_HPP_
#define RANGER_INTERFACES__MSG__DETAIL__MOVEMENT_VECTOR__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "ranger_interfaces/msg/detail/movement_vector__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace ranger_interfaces
{

namespace msg
{

namespace builder
{

class Init_MovementVector_z
{
public:
  explicit Init_MovementVector_z(::ranger_interfaces::msg::MovementVector & msg)
  : msg_(msg)
  {}
  ::ranger_interfaces::msg::MovementVector z(::ranger_interfaces::msg::MovementVector::_z_type arg)
  {
    msg_.z = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ranger_interfaces::msg::MovementVector msg_;
};

class Init_MovementVector_y
{
public:
  explicit Init_MovementVector_y(::ranger_interfaces::msg::MovementVector & msg)
  : msg_(msg)
  {}
  Init_MovementVector_z y(::ranger_interfaces::msg::MovementVector::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_MovementVector_z(msg_);
  }

private:
  ::ranger_interfaces::msg::MovementVector msg_;
};

class Init_MovementVector_x
{
public:
  Init_MovementVector_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MovementVector_y x(::ranger_interfaces::msg::MovementVector::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_MovementVector_y(msg_);
  }

private:
  ::ranger_interfaces::msg::MovementVector msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::ranger_interfaces::msg::MovementVector>()
{
  return ranger_interfaces::msg::builder::Init_MovementVector_x();
}

}  // namespace ranger_interfaces

#endif  // RANGER_INTERFACES__MSG__DETAIL__MOVEMENT_VECTOR__BUILDER_HPP_
