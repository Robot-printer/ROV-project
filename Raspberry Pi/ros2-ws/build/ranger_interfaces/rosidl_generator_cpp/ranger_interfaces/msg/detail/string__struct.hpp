// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from ranger_interfaces:msg/String.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "ranger_interfaces/msg/string.hpp"


#ifndef RANGER_INTERFACES__MSG__DETAIL__STRING__STRUCT_HPP_
#define RANGER_INTERFACES__MSG__DETAIL__STRING__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__ranger_interfaces__msg__String __attribute__((deprecated))
#else
# define DEPRECATED__ranger_interfaces__msg__String __declspec(deprecated)
#endif

namespace ranger_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct String_
{
  using Type = String_<ContainerAllocator>;

  explicit String_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->data = "";
    }
  }

  explicit String_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : data(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->data = "";
    }
  }

  // field types and members
  using _data_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _data_type data;

  // setters for named parameter idiom
  Type & set__data(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->data = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    ranger_interfaces::msg::String_<ContainerAllocator> *;
  using ConstRawPtr =
    const ranger_interfaces::msg::String_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<ranger_interfaces::msg::String_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<ranger_interfaces::msg::String_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      ranger_interfaces::msg::String_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<ranger_interfaces::msg::String_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      ranger_interfaces::msg::String_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<ranger_interfaces::msg::String_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<ranger_interfaces::msg::String_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<ranger_interfaces::msg::String_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__ranger_interfaces__msg__String
    std::shared_ptr<ranger_interfaces::msg::String_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__ranger_interfaces__msg__String
    std::shared_ptr<ranger_interfaces::msg::String_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const String_ & other) const
  {
    if (this->data != other.data) {
      return false;
    }
    return true;
  }
  bool operator!=(const String_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct String_

// alias to use template instance with default allocator
using String =
  ranger_interfaces::msg::String_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace ranger_interfaces

#endif  // RANGER_INTERFACES__MSG__DETAIL__STRING__STRUCT_HPP_
