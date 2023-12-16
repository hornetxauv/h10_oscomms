// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from linear_acceleration_msg:msg/AccelerationXY.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "linear_acceleration_msg/msg/detail/acceleration_xy__struct.hpp"
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

void AccelerationXY_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) linear_acceleration_msg::msg::AccelerationXY(_init);
}

void AccelerationXY_fini_function(void * message_memory)
{
  auto typed_message = static_cast<linear_acceleration_msg::msg::AccelerationXY *>(message_memory);
  typed_message->~AccelerationXY();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember AccelerationXY_message_member_array[2] = {
  {
    "x",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(linear_acceleration_msg::msg::AccelerationXY, x),  // bytes offset in struct
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
    offsetof(linear_acceleration_msg::msg::AccelerationXY, y),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers AccelerationXY_message_members = {
  "linear_acceleration_msg::msg",  // message namespace
  "AccelerationXY",  // message name
  2,  // number of fields
  sizeof(linear_acceleration_msg::msg::AccelerationXY),
  AccelerationXY_message_member_array,  // message members
  AccelerationXY_init_function,  // function to initialize message memory (memory has to be allocated)
  AccelerationXY_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t AccelerationXY_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &AccelerationXY_message_members,
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
get_message_type_support_handle<linear_acceleration_msg::msg::AccelerationXY>()
{
  return &::linear_acceleration_msg::msg::rosidl_typesupport_introspection_cpp::AccelerationXY_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, linear_acceleration_msg, msg, AccelerationXY)() {
  return &::linear_acceleration_msg::msg::rosidl_typesupport_introspection_cpp::AccelerationXY_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
