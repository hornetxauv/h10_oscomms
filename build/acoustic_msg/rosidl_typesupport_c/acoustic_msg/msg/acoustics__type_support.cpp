// generated from rosidl_typesupport_c/resource/idl__type_support.cpp.em
// with input from acoustic_msg:msg/Acoustics.idl
// generated code does not contain a copyright notice

#include "cstddef"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "acoustic_msg/msg/detail/acoustics__struct.h"
#include "acoustic_msg/msg/detail/acoustics__type_support.h"
#include "rosidl_typesupport_c/identifier.h"
#include "rosidl_typesupport_c/message_type_support_dispatch.h"
#include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_c/visibility_control.h"
#include "rosidl_typesupport_interface/macros.h"

namespace acoustic_msg
{

namespace msg
{

namespace rosidl_typesupport_c
{

typedef struct _Acoustics_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Acoustics_type_support_ids_t;

static const _Acoustics_type_support_ids_t _Acoustics_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _Acoustics_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Acoustics_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Acoustics_type_support_symbol_names_t _Acoustics_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, acoustic_msg, msg, Acoustics)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, acoustic_msg, msg, Acoustics)),
  }
};

typedef struct _Acoustics_type_support_data_t
{
  void * data[2];
} _Acoustics_type_support_data_t;

static _Acoustics_type_support_data_t _Acoustics_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Acoustics_message_typesupport_map = {
  2,
  "acoustic_msg",
  &_Acoustics_message_typesupport_ids.typesupport_identifier[0],
  &_Acoustics_message_typesupport_symbol_names.symbol_name[0],
  &_Acoustics_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t Acoustics_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Acoustics_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace msg

}  // namespace acoustic_msg

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, acoustic_msg, msg, Acoustics)() {
  return &::acoustic_msg::msg::rosidl_typesupport_c::Acoustics_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
