// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from acoustic_msg:msg/Acoustic.idl
// generated code does not contain a copyright notice

#ifndef ACOUSTIC_MSG__MSG__DETAIL__ACOUSTIC__STRUCT_HPP_
#define ACOUSTIC_MSG__MSG__DETAIL__ACOUSTIC__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__acoustic_msg__msg__Acoustic __attribute__((deprecated))
#else
# define DEPRECATED__acoustic_msg__msg__Acoustic __declspec(deprecated)
#endif

namespace acoustic_msg
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Acoustic_
{
  using Type = Acoustic_<ContainerAllocator>;

  explicit Acoustic_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->x = 0.0;
      this->y = 0.0;
      this->z = 0.0;
      this->comms_bouy_out = 0.0;
    }
  }

  explicit Acoustic_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->x = 0.0;
      this->y = 0.0;
      this->z = 0.0;
      this->comms_bouy_out = 0.0;
    }
  }

  // field types and members
  using _x_type =
    double;
  _x_type x;
  using _y_type =
    double;
  _y_type y;
  using _z_type =
    double;
  _z_type z;
  using _comms_bouy_out_type =
    double;
  _comms_bouy_out_type comms_bouy_out;

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
  Type & set__z(
    const double & _arg)
  {
    this->z = _arg;
    return *this;
  }
  Type & set__comms_bouy_out(
    const double & _arg)
  {
    this->comms_bouy_out = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    acoustic_msg::msg::Acoustic_<ContainerAllocator> *;
  using ConstRawPtr =
    const acoustic_msg::msg::Acoustic_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<acoustic_msg::msg::Acoustic_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<acoustic_msg::msg::Acoustic_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      acoustic_msg::msg::Acoustic_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<acoustic_msg::msg::Acoustic_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      acoustic_msg::msg::Acoustic_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<acoustic_msg::msg::Acoustic_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<acoustic_msg::msg::Acoustic_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<acoustic_msg::msg::Acoustic_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__acoustic_msg__msg__Acoustic
    std::shared_ptr<acoustic_msg::msg::Acoustic_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__acoustic_msg__msg__Acoustic
    std::shared_ptr<acoustic_msg::msg::Acoustic_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Acoustic_ & other) const
  {
    if (this->x != other.x) {
      return false;
    }
    if (this->y != other.y) {
      return false;
    }
    if (this->z != other.z) {
      return false;
    }
    if (this->comms_bouy_out != other.comms_bouy_out) {
      return false;
    }
    return true;
  }
  bool operator!=(const Acoustic_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Acoustic_

// alias to use template instance with default allocator
using Acoustic =
  acoustic_msg::msg::Acoustic_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace acoustic_msg

#endif  // ACOUSTIC_MSG__MSG__DETAIL__ACOUSTIC__STRUCT_HPP_
