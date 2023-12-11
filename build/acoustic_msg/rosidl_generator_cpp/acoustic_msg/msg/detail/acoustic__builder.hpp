// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from acoustic_msg:msg/Acoustic.idl
// generated code does not contain a copyright notice

#ifndef ACOUSTIC_MSG__MSG__DETAIL__ACOUSTIC__BUILDER_HPP_
#define ACOUSTIC_MSG__MSG__DETAIL__ACOUSTIC__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "acoustic_msg/msg/detail/acoustic__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace acoustic_msg
{

namespace msg
{

namespace builder
{

class Init_Acoustic_comms_bouy_out
{
public:
  explicit Init_Acoustic_comms_bouy_out(::acoustic_msg::msg::Acoustic & msg)
  : msg_(msg)
  {}
  ::acoustic_msg::msg::Acoustic comms_bouy_out(::acoustic_msg::msg::Acoustic::_comms_bouy_out_type arg)
  {
    msg_.comms_bouy_out = std::move(arg);
    return std::move(msg_);
  }

private:
  ::acoustic_msg::msg::Acoustic msg_;
};

class Init_Acoustic_z
{
public:
  explicit Init_Acoustic_z(::acoustic_msg::msg::Acoustic & msg)
  : msg_(msg)
  {}
  Init_Acoustic_comms_bouy_out z(::acoustic_msg::msg::Acoustic::_z_type arg)
  {
    msg_.z = std::move(arg);
    return Init_Acoustic_comms_bouy_out(msg_);
  }

private:
  ::acoustic_msg::msg::Acoustic msg_;
};

class Init_Acoustic_y
{
public:
  explicit Init_Acoustic_y(::acoustic_msg::msg::Acoustic & msg)
  : msg_(msg)
  {}
  Init_Acoustic_z y(::acoustic_msg::msg::Acoustic::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_Acoustic_z(msg_);
  }

private:
  ::acoustic_msg::msg::Acoustic msg_;
};

class Init_Acoustic_x
{
public:
  Init_Acoustic_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Acoustic_y x(::acoustic_msg::msg::Acoustic::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_Acoustic_y(msg_);
  }

private:
  ::acoustic_msg::msg::Acoustic msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::acoustic_msg::msg::Acoustic>()
{
  return acoustic_msg::msg::builder::Init_Acoustic_x();
}

}  // namespace acoustic_msg

#endif  // ACOUSTIC_MSG__MSG__DETAIL__ACOUSTIC__BUILDER_HPP_
