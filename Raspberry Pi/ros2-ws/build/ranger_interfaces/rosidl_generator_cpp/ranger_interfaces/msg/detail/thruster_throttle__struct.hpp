// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from ranger_interfaces:msg/ThrusterThrottle.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "ranger_interfaces/msg/thruster_throttle.hpp"


#ifndef RANGER_INTERFACES__MSG__DETAIL__THRUSTER_THROTTLE__STRUCT_HPP_
#define RANGER_INTERFACES__MSG__DETAIL__THRUSTER_THROTTLE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__ranger_interfaces__msg__ThrusterThrottle __attribute__((deprecated))
#else
# define DEPRECATED__ranger_interfaces__msg__ThrusterThrottle __declspec(deprecated)
#endif

namespace ranger_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct ThrusterThrottle_
{
  using Type = ThrusterThrottle_<ContainerAllocator>;

  explicit ThrusterThrottle_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->id = 0ll;
      this->value = 0ll;
    }
  }

  explicit ThrusterThrottle_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->id = 0ll;
      this->value = 0ll;
    }
  }

  // field types and members
  using _id_type =
    int64_t;
  _id_type id;
  using _value_type =
    int64_t;
  _value_type value;

  // setters for named parameter idiom
  Type & set__id(
    const int64_t & _arg)
  {
    this->id = _arg;
    return *this;
  }
  Type & set__value(
    const int64_t & _arg)
  {
    this->value = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    ranger_interfaces::msg::ThrusterThrottle_<ContainerAllocator> *;
  using ConstRawPtr =
    const ranger_interfaces::msg::ThrusterThrottle_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<ranger_interfaces::msg::ThrusterThrottle_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<ranger_interfaces::msg::ThrusterThrottle_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      ranger_interfaces::msg::ThrusterThrottle_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<ranger_interfaces::msg::ThrusterThrottle_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      ranger_interfaces::msg::ThrusterThrottle_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<ranger_interfaces::msg::ThrusterThrottle_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<ranger_interfaces::msg::ThrusterThrottle_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<ranger_interfaces::msg::ThrusterThrottle_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__ranger_interfaces__msg__ThrusterThrottle
    std::shared_ptr<ranger_interfaces::msg::ThrusterThrottle_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__ranger_interfaces__msg__ThrusterThrottle
    std::shared_ptr<ranger_interfaces::msg::ThrusterThrottle_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ThrusterThrottle_ & other) const
  {
    if (this->id != other.id) {
      return false;
    }
    if (this->value != other.value) {
      return false;
    }
    return true;
  }
  bool operator!=(const ThrusterThrottle_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ThrusterThrottle_

// alias to use template instance with default allocator
using ThrusterThrottle =
  ranger_interfaces::msg::ThrusterThrottle_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace ranger_interfaces

#endif  // RANGER_INTERFACES__MSG__DETAIL__THRUSTER_THROTTLE__STRUCT_HPP_
