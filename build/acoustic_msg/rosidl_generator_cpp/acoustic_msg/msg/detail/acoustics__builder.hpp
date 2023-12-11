// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from acoustic_msg:msg/Acoustics.idl
// generated code does not contain a copyright notice

#ifndef ACOUSTIC_MSG__MSG__DETAIL__ACOUSTICS__BUILDER_HPP_
#define ACOUSTIC_MSG__MSG__DETAIL__ACOUSTICS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "acoustic_msg/msg/detail/acoustics__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace acoustic_msg
{

namespace msg
{

namespace builder
{

class Init_Acoustics_z
{
public:
  explicit Init_Acoustics_z(::acoustic_msg::msg::Acoustics & msg)
  : msg_(msg)
  {}
  ::acoustic_msg::msg::Acoustics z(::acoustic_msg::msg::Acoustics::_z_type arg)
  {
    msg_.z = std::move(arg);
    return std::move(msg_);
  }

private:
  ::acoustic_msg::msg::Acoustics msg_;
};

class Init_Acoustics_y
{
public:
  explicit Init_Acoustics_y(::acoustic_msg::msg::Acoustics & msg)
  : msg_(msg)
  {}
  Init_Acoustics_z y(::acoustic_msg::msg::Acoustics::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_Acoustics_z(msg_);
  }

private:
  ::acoustic_msg::msg::Acoustics msg_;
};

class Init_Acoustics_x
{
public:
  explicit Init_Acoustics_x(::acoustic_msg::msg::Acoustics & msg)
  : msg_(msg)
  {}
  Init_Acoustics_y x(::acoustic_msg::msg::Acoustics::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_Acoustics_y(msg_);
  }

private:
  ::acoustic_msg::msg::Acoustics msg_;
};

class Init_Acoustics_comms_bouy_output
{
public:
  Init_Acoustics_comms_bouy_output()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Acoustics_x comms_bouy_output(::acoustic_msg::msg::Acoustics::_comms_bouy_output_type arg)
  {
    msg_.comms_bouy_output = std::move(arg);
    return Init_Acoustics_x(msg_);
  }

private:
  ::acoustic_msg::msg::Acoustics msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::acoustic_msg::msg::Acoustics>()
{
  return acoustic_msg::msg::builder::Init_Acoustics_comms_bouy_output();
}

}  // namespace acoustic_msg

#endif  // ACOUSTIC_MSG__MSG__DETAIL__ACOUSTICS__BUILDER_HPP_
