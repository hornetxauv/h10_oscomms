// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from test_msg:msg/Num.idl
// generated code does not contain a copyright notice

#ifndef TEST_MSG__MSG__DETAIL__NUM__BUILDER_HPP_
#define TEST_MSG__MSG__DETAIL__NUM__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "test_msg/msg/detail/num__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace test_msg
{

namespace msg
{

namespace builder
{

class Init_Num_data
{
public:
  explicit Init_Num_data(::test_msg::msg::Num & msg)
  : msg_(msg)
  {}
  ::test_msg::msg::Num data(::test_msg::msg::Num::_data_type arg)
  {
    msg_.data = std::move(arg);
    return std::move(msg_);
  }

private:
  ::test_msg::msg::Num msg_;
};

class Init_Num_num
{
public:
  Init_Num_num()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Num_data num(::test_msg::msg::Num::_num_type arg)
  {
    msg_.num = std::move(arg);
    return Init_Num_data(msg_);
  }

private:
  ::test_msg::msg::Num msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::test_msg::msg::Num>()
{
  return test_msg::msg::builder::Init_Num_num();
}

}  // namespace test_msg

#endif  // TEST_MSG__MSG__DETAIL__NUM__BUILDER_HPP_
