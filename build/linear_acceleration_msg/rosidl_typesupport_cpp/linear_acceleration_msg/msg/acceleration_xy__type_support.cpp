// generated from rosidl_typesupport_cpp/resource/idl__type_support.cpp.em
// with input from linear_acceleration_msg:msg/AccelerationXY.idl
// generated code does not contain a copyright notice

#include "cstddef"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "linear_acceleration_msg/msg/detail/acceleration_xy__struct.hpp"
#include "rosidl_typesupport_cpp/identifier.hpp"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
#include "rosidl_typesupport_cpp/visibility_control.h"
#include "rosidl_typesupport_interface/macros.h"

namespace linear_acceleration_msg
{

namespace msg
{

namespace rosidl_typesupport_cpp
{

typedef struct _AccelerationXY_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _AccelerationXY_type_support_ids_t;

static const _AccelerationXY_type_support_ids_t _AccelerationXY_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _AccelerationXY_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _AccelerationXY_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _AccelerationXY_type_support_symbol_names_t _AccelerationXY_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, linear_acceleration_msg, msg, AccelerationXY)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, linear_acceleration_msg, msg, AccelerationXY)),
  }
};

typedef struct _AccelerationXY_type_support_data_t
{
  void * data[2];
} _AccelerationXY_type_support_data_t;

static _AccelerationXY_type_support_data_t _AccelerationXY_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _AccelerationXY_message_typesupport_map = {
  2,
  "linear_acceleration_msg",
  &_AccelerationXY_message_typesupport_ids.typesupport_identifier[0],
  &_AccelerationXY_message_typesupport_symbol_names.symbol_name[0],
  &_AccelerationXY_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t AccelerationXY_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_AccelerationXY_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace msg

}  // namespace linear_acceleration_msg

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<linear_acceleration_msg::msg::AccelerationXY>()
{
  return &::linear_acceleration_msg::msg::rosidl_typesupport_cpp::AccelerationXY_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, linear_acceleration_msg, msg, AccelerationXY)() {
  return get_message_type_support_handle<linear_acceleration_msg::msg::AccelerationXY>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp
