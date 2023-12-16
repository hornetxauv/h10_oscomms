// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from linear_acceleration_msg:msg/Acceleration.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "linear_acceleration_msg/msg/detail/acceleration__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace linear_acceleration_msg
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void Acceleration_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) linear_acceleration_msg::msg::Acceleration(_init);
}

void Acceleration_fini_function(void * message_memory)
{
  auto typed_message = static_cast<linear_acceleration_msg::msg::Acceleration *>(message_memory);
  typed_message->~Acceleration();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember Acceleration_message_member_array[3] = {
  {
    "x",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(linear_acceleration_msg::msg::Acceleration, x),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "y",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(linear_acceleration_msg::msg::Acceleration, y),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "z",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(linear_acceleration_msg::msg::Acceleration, z),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers Acceleration_message_members = {
  "linear_acceleration_msg::msg",  // message namespace
  "Acceleration",  // message name
  3,  // number of fields
  sizeof(linear_acceleration_msg::msg::Acceleration),
  Acceleration_message_member_array,  // message members
  Acceleration_init_function,  // function to initialize message memory (memory has to be allocated)
  Acceleration_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t Acceleration_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &Acceleration_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace linear_acceleration_msg


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<linear_acceleration_msg::msg::Acceleration>()
{
  return &::linear_acceleration_msg::msg::rosidl_typesupport_introspection_cpp::Acceleration_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, linear_acceleration_msg, msg, Acceleration)() {
  return &::linear_acceleration_msg::msg::rosidl_typesupport_introspection_cpp::Acceleration_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
