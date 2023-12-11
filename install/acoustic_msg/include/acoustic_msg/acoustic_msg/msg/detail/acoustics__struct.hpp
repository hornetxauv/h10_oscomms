// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from acoustic_msg:msg/Acoustics.idl
// generated code does not contain a copyright notice

#ifndef ACOUSTIC_MSG__MSG__DETAIL__ACOUSTICS__STRUCT_HPP_
#define ACOUSTIC_MSG__MSG__DETAIL__ACOUSTICS__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__acoustic_msg__msg__Acoustics __attribute__((deprecated))
#else
# define DEPRECATED__acoustic_msg__msg__Acoustics __declspec(deprecated)
#endif

namespace acoustic_msg
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Acoustics_
{
  using Type = Acoustics_<ContainerAllocator>;

  explicit Acoustics_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->comms_bouy_output = 0.0;
      this->x = 0.0;
      this->y = 0.0;
      this->z = 0.0;
    }
  }

  explicit Acoustics_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->comms_bouy_output = 0.0;
      this->x = 0.0;
      this->y = 0.0;
      this->z = 0.0;
    }
  }

  // field types and members
  using _comms_bouy_output_type =
    double;
  _comms_bouy_output_type comms_bouy_output;
  using _x_type =
    double;
  _x_type x;
  using _y_type =
    double;
  _y_type y;
  using _z_type =
    double;
  _z_type z;

  // setters for named parameter idiom
  Type & set__comms_bouy_output(
    const double & _arg)
  {
    this->comms_bouy_output = _arg;
    return *this;
  }
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
  Type & set__z(
    const double & _arg)
  {
    this->z = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    acoustic_msg::msg::Acoustics_<ContainerAllocator> *;
  using ConstRawPtr =
    const acoustic_msg::msg::Acoustics_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<acoustic_msg::msg::Acoustics_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<acoustic_msg::msg::Acoustics_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      acoustic_msg::msg::Acoustics_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<acoustic_msg::msg::Acoustics_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      acoustic_msg::msg::Acoustics_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<acoustic_msg::msg::Acoustics_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<acoustic_msg::msg::Acoustics_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<acoustic_msg::msg::Acoustics_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__acoustic_msg__msg__Acoustics
    std::shared_ptr<acoustic_msg::msg::Acoustics_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__acoustic_msg__msg__Acoustics
    std::shared_ptr<acoustic_msg::msg::Acoustics_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Acoustics_ & other) const
  {
    if (this->comms_bouy_output != other.comms_bouy_output) {
      return false;
    }
    if (this->x != other.x) {
      return false;
    }
    if (this->y != other.y) {
      return false;
    }
    if (this->z != other.z) {
      return false;
    }
    return true;
  }
  bool operator!=(const Acoustics_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Acoustics_

// alias to use template instance with default allocator
using Acoustics =
  acoustic_msg::msg::Acoustics_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace acoustic_msg

#endif  // ACOUSTIC_MSG__MSG__DETAIL__ACOUSTICS__STRUCT_HPP_
