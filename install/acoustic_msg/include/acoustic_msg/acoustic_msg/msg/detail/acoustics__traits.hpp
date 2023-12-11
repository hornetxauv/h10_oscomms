// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from acoustic_msg:msg/Acoustics.idl
// generated code does not contain a copyright notice

#ifndef ACOUSTIC_MSG__MSG__DETAIL__ACOUSTICS__TRAITS_HPP_
#define ACOUSTIC_MSG__MSG__DETAIL__ACOUSTICS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "acoustic_msg/msg/detail/acoustics__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace acoustic_msg
{

namespace msg
{

inline void to_flow_style_yaml(
  const Acoustics & msg,
  std::ostream & out)
{
  out << "{";
  // member: comms_bouy_output
  {
    out << "comms_bouy_output: ";
    rosidl_generator_traits::value_to_yaml(msg.comms_bouy_output, out);
    out << ", ";
  }

  // member: x
  {
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
    out << ", ";
  }

  // member: y
  {
    out << "y: ";
    rosidl_generator_traits::value_to_yaml(msg.y, out);
    out << ", ";
  }

  // member: z
  {
    out << "z: ";
    rosidl_generator_traits::value_to_yaml(msg.z, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Acoustics & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: comms_bouy_output
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "comms_bouy_output: ";
    rosidl_generator_traits::value_to_yaml(msg.comms_bouy_output, out);
    out << "\n";
  }

  // member: x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
    out << "\n";
  }

  // member: y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "y: ";
    rosidl_generator_traits::value_to_yaml(msg.y, out);
    out << "\n";
  }

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

inline std::string to_yaml(const Acoustics & msg, bool use_flow_style = false)
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

}  // namespace acoustic_msg

namespace rosidl_generator_traits
{

[[deprecated("use acoustic_msg::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const acoustic_msg::msg::Acoustics & msg,
  std::ostream & out, size_t indentation = 0)
{
  acoustic_msg::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use acoustic_msg::msg::to_yaml() instead")]]
inline std::string to_yaml(const acoustic_msg::msg::Acoustics & msg)
{
  return acoustic_msg::msg::to_yaml(msg);
}

template<>
inline const char * data_type<acoustic_msg::msg::Acoustics>()
{
  return "acoustic_msg::msg::Acoustics";
}

template<>
inline const char * name<acoustic_msg::msg::Acoustics>()
{
  return "acoustic_msg/msg/Acoustics";
}

template<>
struct has_fixed_size<acoustic_msg::msg::Acoustics>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<acoustic_msg::msg::Acoustics>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<acoustic_msg::msg::Acoustics>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // ACOUSTIC_MSG__MSG__DETAIL__ACOUSTICS__TRAITS_HPP_
