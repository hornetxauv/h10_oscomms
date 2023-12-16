// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__rosidl_typesupport_fastrtps_cpp.hpp.em
// with input from linear_acceleration_msg:msg/Acceleration.idl
// generated code does not contain a copyright notice

#ifndef LINEAR_ACCELERATION_MSG__MSG__DETAIL__ACCELERATION__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
#define LINEAR_ACCELERATION_MSG__MSG__DETAIL__ACCELERATION__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_

#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "linear_acceleration_msg/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"
#include "linear_acceleration_msg/msg/detail/acceleration__struct.hpp"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

#include "fastcdr/Cdr.h"

namespace linear_acceleration_msg
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_linear_acceleration_msg
cdr_serialize(
  const linear_acceleration_msg::msg::Acceleration & ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_linear_acceleration_msg
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  linear_acceleration_msg::msg::Acceleration & ros_message);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_linear_acceleration_msg
get_serialized_size(
  const linear_acceleration_msg::msg::Acceleration & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_linear_acceleration_msg
max_serialized_size_Acceleration(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace linear_acceleration_msg

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_linear_acceleration_msg
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, linear_acceleration_msg, msg, Acceleration)();

#ifdef __cplusplus
}
#endif

#endif  // LINEAR_ACCELERATION_MSG__MSG__DETAIL__ACCELERATION__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
