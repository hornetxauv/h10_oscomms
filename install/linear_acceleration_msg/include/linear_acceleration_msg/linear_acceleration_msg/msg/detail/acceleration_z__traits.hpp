// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from linear_acceleration_msg:msg/AccelerationZ.idl
// generated code does not contain a copyright notice

#ifndef LINEAR_ACCELERATION_MSG__MSG__DETAIL__ACCELERATION_Z__TRAITS_HPP_
#define LINEAR_ACCELERATION_MSG__MSG__DETAIL__ACCELERATION_Z__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "linear_acceleration_msg/msg/detail/acceleration_z__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace linear_acceleration_msg
{

namespace msg
{

inline void to_flow_style_yaml(
  const AccelerationZ & msg,
  std::ostream & out)
{
  out << "{";
  // member: z
  {
    out << "z: ";
    rosidl_generator_traits::value_to_yaml(msg.z, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const AccelerationZ & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: z
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "z: ";
    rosidl_generator_traits::value_to_yaml(msg.z, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const AccelerationZ & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace linear_acceleration_msg

namespace rosidl_generator_traits
{

[[deprecated("use linear_acceleration_msg::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const linear_acceleration_msg::msg::AccelerationZ & msg,
  std::ostream & out, size_t indentation = 0)
{
  linear_acceleration_msg::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use linear_acceleration_msg::msg::to_yaml() instead")]]
inline std::string to_yaml(const linear_acceleration_msg::msg::AccelerationZ & msg)
{
  return linear_acceleration_msg::msg::to_yaml(msg);
}

template<>
inline const char * data_type<linear_acceleration_msg::msg::AccelerationZ>()
{
  return "linear_acceleration_msg::msg::AccelerationZ";
}

template<>
inline const char * name<linear_acceleration_msg::msg::AccelerationZ>()
{
  return "linear_acceleration_msg/msg/AccelerationZ";
}

template<>
struct has_fixed_size<linear_acceleration_msg::msg::AccelerationZ>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<linear_acceleration_msg::msg::AccelerationZ>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<linear_acceleration_msg::msg::AccelerationZ>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // LINEAR_ACCELERATION_MSG__MSG__DETAIL__ACCELERATION_Z__TRAITS_HPP_
