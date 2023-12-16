// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from linear_acceleration_msg:msg/AccelerationXY.idl
// generated code does not contain a copyright notice

#ifndef LINEAR_ACCELERATION_MSG__MSG__DETAIL__ACCELERATION_XY__BUILDER_HPP_
#define LINEAR_ACCELERATION_MSG__MSG__DETAIL__ACCELERATION_XY__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "linear_acceleration_msg/msg/detail/acceleration_xy__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace linear_acceleration_msg
{

namespace msg
{

namespace builder
{

class Init_AccelerationXY_y
{
public:
  explicit Init_AccelerationXY_y(::linear_acceleration_msg::msg::AccelerationXY & msg)
  : msg_(msg)
  {}
  ::linear_acceleration_msg::msg::AccelerationXY y(::linear_acceleration_msg::msg::AccelerationXY::_y_type arg)
  {
    msg_.y = std::move(arg);
    return std::move(msg_);
  }

private:
  ::linear_acceleration_msg::msg::AccelerationXY msg_;
};

class Init_AccelerationXY_x
{
public:
  Init_AccelerationXY_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_AccelerationXY_y x(::linear_acceleration_msg::msg::AccelerationXY::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_AccelerationXY_y(msg_);
  }

private:
  ::linear_acceleration_msg::msg::AccelerationXY msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::linear_acceleration_msg::msg::AccelerationXY>()
{
  return linear_acceleration_msg::msg::builder::Init_AccelerationXY_x();
}

}  // namespace linear_acceleration_msg

#endif  // LINEAR_ACCELERATION_MSG__MSG__DETAIL__ACCELERATION_XY__BUILDER_HPP_
