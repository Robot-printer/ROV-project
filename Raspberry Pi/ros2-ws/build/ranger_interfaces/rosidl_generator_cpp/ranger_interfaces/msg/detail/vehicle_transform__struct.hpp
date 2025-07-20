// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from ranger_interfaces:msg/VehicleTransform.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "ranger_interfaces/msg/vehicle_transform.hpp"


#ifndef RANGER_INTERFACES__MSG__DETAIL__VEHICLE_TRANSFORM__STRUCT_HPP_
#define RANGER_INTERFACES__MSG__DETAIL__VEHICLE_TRANSFORM__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__ranger_interfaces__msg__VehicleTransform __attribute__((deprecated))
#else
# define DEPRECATED__ranger_interfaces__msg__VehicleTransform __declspec(deprecated)
#endif

namespace ranger_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct VehicleTransform_
{
  using Type = VehicleTransform_<ContainerAllocator>;

  explicit VehicleTransform_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->x_pos = 0.0;
      this->y_pos = 0.0;
      this->z_pos = 0.0;
      this->x_rot = 0.0;
      this->y_rot = 0.0;
      this->z_rot = 0.0;
    }
  }

  explicit VehicleTransform_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->x_pos = 0.0;
      this->y_pos = 0.0;
      this->z_pos = 0.0;
      this->x_rot = 0.0;
      this->y_rot = 0.0;
      this->z_rot = 0.0;
    }
  }

  // field types and members
  using _x_pos_type =
    double;
  _x_pos_type x_pos;
  using _y_pos_type =
    double;
  _y_pos_type y_pos;
  using _z_pos_type =
    double;
  _z_pos_type z_pos;
  using _x_rot_type =
    double;
  _x_rot_type x_rot;
  using _y_rot_type =
    double;
  _y_rot_type y_rot;
  using _z_rot_type =
    double;
  _z_rot_type z_rot;

  // setters for named parameter idiom
  Type & set__x_pos(
    const double & _arg)
  {
    this->x_pos = _arg;
    return *this;
  }
  Type & set__y_pos(
    const double & _arg)
  {
    this->y_pos = _arg;
    return *this;
  }
  Type & set__z_pos(
    const double & _arg)
  {
    this->z_pos = _arg;
    return *this;
  }
  Type & set__x_rot(
    const double & _arg)
  {
    this->x_rot = _arg;
    return *this;
  }
  Type & set__y_rot(
    const double & _arg)
  {
    this->y_rot = _arg;
    return *this;
  }
  Type & set__z_rot(
    const double & _arg)
  {
    this->z_rot = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    ranger_interfaces::msg::VehicleTransform_<ContainerAllocator> *;
  using ConstRawPtr =
    const ranger_interfaces::msg::VehicleTransform_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<ranger_interfaces::msg::VehicleTransform_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<ranger_interfaces::msg::VehicleTransform_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      ranger_interfaces::msg::VehicleTransform_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<ranger_interfaces::msg::VehicleTransform_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      ranger_interfaces::msg::VehicleTransform_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<ranger_interfaces::msg::VehicleTransform_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<ranger_interfaces::msg::VehicleTransform_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<ranger_interfaces::msg::VehicleTransform_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__ranger_interfaces__msg__VehicleTransform
    std::shared_ptr<ranger_interfaces::msg::VehicleTransform_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__ranger_interfaces__msg__VehicleTransform
    std::shared_ptr<ranger_interfaces::msg::VehicleTransform_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const VehicleTransform_ & other) const
  {
    if (this->x_pos != other.x_pos) {
      return false;
    }
    if (this->y_pos != other.y_pos) {
      return false;
    }
    if (this->z_pos != other.z_pos) {
      return false;
    }
    if (this->x_rot != other.x_rot) {
      return false;
    }
    if (this->y_rot != other.y_rot) {
      return false;
    }
    if (this->z_rot != other.z_rot) {
      return false;
    }
    return true;
  }
  bool operator!=(const VehicleTransform_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct VehicleTransform_

// alias to use template instance with default allocator
using VehicleTransform =
  ranger_interfaces::msg::VehicleTransform_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace ranger_interfaces

#endif  // RANGER_INTERFACES__MSG__DETAIL__VEHICLE_TRANSFORM__STRUCT_HPP_
