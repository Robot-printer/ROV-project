// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ranger_interfaces:msg/String.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "ranger_interfaces/msg/string.hpp"


#ifndef RANGER_INTERFACES__MSG__DETAIL__STRING__BUILDER_HPP_
#define RANGER_INTERFACES__MSG__DETAIL__STRING__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "ranger_interfaces/msg/detail/string__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace ranger_interfaces
{

namespace msg
{

namespace builder
{

class Init_String_data
{
public:
  Init_String_data()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::ranger_interfaces::msg::String data(::ranger_interfaces::msg::String::_data_type arg)
  {
    msg_.data = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ranger_interfaces::msg::String msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::ranger_interfaces::msg::String>()
{
  return ranger_interfaces::msg::builder::Init_String_data();
}

}  // namespace ranger_interfaces

#endif  // RANGER_INTERFACES__MSG__DETAIL__STRING__BUILDER_HPP_
