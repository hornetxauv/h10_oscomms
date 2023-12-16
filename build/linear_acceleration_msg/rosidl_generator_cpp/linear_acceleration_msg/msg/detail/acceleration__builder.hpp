// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from linear_acceleration_msg:msg/Acceleration.idl
// generated code does not contain a copyright notice

#ifndef LINEAR_ACCELERATION_MSG__MSG__DETAIL__ACCELERATION__BUILDER_HPP_
#define LINEAR_ACCELERATION_MSG__MSG__DETAIL__ACCELERATION__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "linear_acceleration_msg/msg/detail/acceleration__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace linear_acceleration_msg
{

namespace msg
{

namespace builder
{

class Init_Acceleration_z
{
public:
  explicit Init_Acceleration_z(::linear_acceleration_msg::msg::Acceleration & msg)
  : msg_(msg)
  {}
  ::linear_acceleration_msg::msg::Acceleration z(::linear_acceleration_msg::msg::Acceleration::_z_type arg)
  {
    msg_.z = std::move(arg);
    return std::move(msg_);
  }

private:
  ::linear_acceleration_msg::msg::Acceleration msg_;
};

class Init_Acceleration_y
{
public:
  explicit Init_Acceleration_y(::linear_acceleration_msg::msg::Acceleration & msg)
  : msg_(msg)
  {}
  Init_Acceleration_z y(::linear_acceleration_msg::msg::Acceleration::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_Acceleration_z(msg_);
  }

private:
  ::linear_acceleration_msg::msg::Acceleration msg_;
};

class Init_Acceleration_x
{
public:
  Init_Acceleration_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Acceleration_y x(::linear_acceleration_msg::msg::Acceleration::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_Acceleration_y(msg_);
  }

private:
  ::linear_acceleration_msg::msg::Acceleration msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::linear_acceleration_msg::msg::Acceleration>()
{
  return linear_acceleration_msg::msg::builder::Init_Acceleration_x();
}

}  // namespace linear_acceleration_msg

#endif  // LINEAR_ACCELERATION_MSG__MSG__DETAIL__ACCELERATION__BUILDER_HPP_
