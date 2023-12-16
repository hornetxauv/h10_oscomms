// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from linear_acceleration_msg:msg/AccelerationXY.idl
// generated code does not contain a copyright notice

#ifndef LINEAR_ACCELERATION_MSG__MSG__DETAIL__ACCELERATION_XY__STRUCT_HPP_
#define LINEAR_ACCELERATION_MSG__MSG__DETAIL__ACCELERATION_XY__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__linear_acceleration_msg__msg__AccelerationXY __attribute__((deprecated))
#else
# define DEPRECATED__linear_acceleration_msg__msg__AccelerationXY __declspec(deprecated)
#endif

namespace linear_acceleration_msg
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct AccelerationXY_
{
  using Type = AccelerationXY_<ContainerAllocator>;

  explicit AccelerationXY_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->x = 0.0;
      this->y = 0.0;
    }
  }

  explicit AccelerationXY_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->x = 0.0;
      this->y = 0.0;
    }
  }

  // field types and members
  using _x_type =
    double;
  _x_type x;
  using _y_type =
    double;
  _y_type y;

  // setters for named parameter idiom
  Type & set__x(
    const double & _arg)
  {
    this->x = _arg;
    return *this;
  }
  Type & set__y(
    const double & _arg)
  {
    this->y = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    linear_acceleration_msg::msg::AccelerationXY_<ContainerAllocator> *;
  using ConstRawPtr =
    const linear_acceleration_msg::msg::AccelerationXY_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<linear_acceleration_msg::msg::AccelerationXY_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<linear_acceleration_msg::msg::AccelerationXY_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      linear_acceleration_msg::msg::AccelerationXY_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<linear_acceleration_msg::msg::AccelerationXY_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      linear_acceleration_msg::msg::AccelerationXY_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<linear_acceleration_msg::msg::AccelerationXY_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<linear_acceleration_msg::msg::AccelerationXY_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<linear_acceleration_msg::msg::AccelerationXY_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__linear_acceleration_msg__msg__AccelerationXY
    std::shared_ptr<linear_acceleration_msg::msg::AccelerationXY_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__linear_acceleration_msg__msg__AccelerationXY
    std::shared_ptr<linear_acceleration_msg::msg::AccelerationXY_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const AccelerationXY_ & other) const
  {
    if (this->x != other.x) {
      return false;
    }
    if (this->y != other.y) {
      return false;
    }
    return true;
  }
  bool operator!=(const AccelerationXY_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct AccelerationXY_

// alias to use template instance with default allocator
using AccelerationXY =
  linear_acceleration_msg::msg::AccelerationXY_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace linear_acceleration_msg

#endif  // LINEAR_ACCELERATION_MSG__MSG__DETAIL__ACCELERATION_XY__STRUCT_HPP_
