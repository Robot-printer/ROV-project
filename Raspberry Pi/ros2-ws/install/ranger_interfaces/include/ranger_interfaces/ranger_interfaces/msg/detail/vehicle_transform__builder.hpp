// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ranger_interfaces:msg/VehicleTransform.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "ranger_interfaces/msg/vehicle_transform.hpp"


#ifndef RANGER_INTERFACES__MSG__DETAIL__VEHICLE_TRANSFORM__BUILDER_HPP_
#define RANGER_INTERFACES__MSG__DETAIL__VEHICLE_TRANSFORM__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "ranger_interfaces/msg/detail/vehicle_transform__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace ranger_interfaces
{

namespace msg
{

namespace builder
{

class Init_VehicleTransform_z_rot
{
public:
  explicit Init_VehicleTransform_z_rot(::ranger_interfaces::msg::VehicleTransform & msg)
  : msg_(msg)
  {}
  ::ranger_interfaces::msg::VehicleTransform z_rot(::ranger_interfaces::msg::VehicleTransform::_z_rot_type arg)
  {
    msg_.z_rot = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ranger_interfaces::msg::VehicleTransform msg_;
};

class Init_VehicleTransform_y_rot
{
public:
  explicit Init_VehicleTransform_y_rot(::ranger_interfaces::msg::VehicleTransform & msg)
  : msg_(msg)
  {}
  Init_VehicleTransform_z_rot y_rot(::ranger_interfaces::msg::VehicleTransform::_y_rot_type arg)
  {
    msg_.y_rot = std::move(arg);
    return Init_VehicleTransform_z_rot(msg_);
  }

private:
  ::ranger_interfaces::msg::VehicleTransform msg_;
};

class Init_VehicleTransform_x_rot
{
public:
  explicit Init_VehicleTransform_x_rot(::ranger_interfaces::msg::VehicleTransform & msg)
  : msg_(msg)
  {}
  Init_VehicleTransform_y_rot x_rot(::ranger_interfaces::msg::VehicleTransform::_x_rot_type arg)
  {
    msg_.x_rot = std::move(arg);
    return Init_VehicleTransform_y_rot(msg_);
  }

private:
  ::ranger_interfaces::msg::VehicleTransform msg_;
};

class Init_VehicleTransform_z_pos
{
public:
  explicit Init_VehicleTransform_z_pos(::ranger_interfaces::msg::VehicleTransform & msg)
  : msg_(msg)
  {}
  Init_VehicleTransform_x_rot z_pos(::ranger_interfaces::msg::VehicleTransform::_z_pos_type arg)
  {
    msg_.z_pos = std::move(arg);
    return Init_VehicleTransform_x_rot(msg_);
  }

private:
  ::ranger_interfaces::msg::VehicleTransform msg_;
};

class Init_VehicleTransform_y_pos
{
public:
  explicit Init_VehicleTransform_y_pos(::ranger_interfaces::msg::VehicleTransform & msg)
  : msg_(msg)
  {}
  Init_VehicleTransform_z_pos y_pos(::ranger_interfaces::msg::VehicleTransform::_y_pos_type arg)
  {
    msg_.y_pos = std::move(arg);
    return Init_VehicleTransform_z_pos(msg_);
  }

private:
  ::ranger_interfaces::msg::VehicleTransform msg_;
};

class Init_VehicleTransform_x_pos
{
public:
  Init_VehicleTransform_x_pos()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_VehicleTransform_y_pos x_pos(::ranger_interfaces::msg::VehicleTransform::_x_pos_type arg)
  {
    msg_.x_pos = std::move(arg);
    return Init_VehicleTransform_y_pos(msg_);
  }

private:
  ::ranger_interfaces::msg::VehicleTransform msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::ranger_interfaces::msg::VehicleTransform>()
{
  return ranger_interfaces::msg::builder::Init_VehicleTransform_x_pos();
}

}  // namespace ranger_interfaces

#endif  // RANGER_INTERFACES__MSG__DETAIL__VEHICLE_TRANSFORM__BUILDER_HPP_
