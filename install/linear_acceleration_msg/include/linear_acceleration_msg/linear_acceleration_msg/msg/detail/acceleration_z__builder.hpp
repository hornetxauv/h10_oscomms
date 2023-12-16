// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from linear_acceleration_msg:msg/AccelerationZ.idl
// generated code does not contain a copyright notice

#ifndef LINEAR_ACCELERATION_MSG__MSG__DETAIL__ACCELERATION_Z__BUILDER_HPP_
#define LINEAR_ACCELERATION_MSG__MSG__DETAIL__ACCELERATION_Z__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "linear_acceleration_msg/msg/detail/acceleration_z__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace linear_acceleration_msg
{

namespace msg
{

namespace builder
{

class Init_AccelerationZ_z
{
public:
  Init_AccelerationZ_z()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::linear_acceleration_msg::msg::AccelerationZ z(::linear_acceleration_msg::msg::AccelerationZ::_z_type arg)
  {
    msg_.z = std::move(arg);
    return std::move(msg_);
  }

private:
  ::linear_acceleration_msg::msg::AccelerationZ msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::linear_acceleration_msg::msg::AccelerationZ>()
{
  return linear_acceleration_msg::msg::builder::Init_AccelerationZ_z();
}

}  // namespace linear_acceleration_msg

#endif  // LINEAR_ACCELERATION_MSG__MSG__DETAIL__ACCELERATION_Z__BUILDER_HPP_
