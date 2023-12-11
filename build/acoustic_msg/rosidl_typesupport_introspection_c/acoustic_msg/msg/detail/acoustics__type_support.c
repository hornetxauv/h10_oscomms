// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from acoustic_msg:msg/Acoustics.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "acoustic_msg/msg/detail/acoustics__rosidl_typesupport_introspection_c.h"
#include "acoustic_msg/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "acoustic_msg/msg/detail/acoustics__functions.h"
#include "acoustic_msg/msg/detail/acoustics__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void acoustic_msg__msg__Acoustics__rosidl_typesupport_introspection_c__Acoustics_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  acoustic_msg__msg__Acoustics__init(message_memory);
}

void acoustic_msg__msg__Acoustics__rosidl_typesupport_introspection_c__Acoustics_fini_function(void * message_memory)
{
  acoustic_msg__msg__Acoustics__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember acoustic_msg__msg__Acoustics__rosidl_typesupport_introspection_c__Acoustics_message_member_array[4] = {
  {
    "comms_bouy_output",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(acoustic_msg__msg__Acoustics, comms_bouy_output),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "x",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(acoustic_msg__msg__Acoustics, x),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "y",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(acoustic_msg__msg__Acoustics, y),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "z",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(acoustic_msg__msg__Acoustics, z),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers acoustic_msg__msg__Acoustics__rosidl_typesupport_introspection_c__Acoustics_message_members = {
  "acoustic_msg__msg",  // message namespace
  "Acoustics",  // message name
  4,  // number of fields
  sizeof(acoustic_msg__msg__Acoustics),
  acoustic_msg__msg__Acoustics__rosidl_typesupport_introspection_c__Acoustics_message_member_array,  // message members
  acoustic_msg__msg__Acoustics__rosidl_typesupport_introspection_c__Acoustics_init_function,  // function to initialize message memory (memory has to be allocated)
  acoustic_msg__msg__Acoustics__rosidl_typesupport_introspection_c__Acoustics_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t acoustic_msg__msg__Acoustics__rosidl_typesupport_introspection_c__Acoustics_message_type_support_handle = {
  0,
  &acoustic_msg__msg__Acoustics__rosidl_typesupport_introspection_c__Acoustics_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_acoustic_msg
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, acoustic_msg, msg, Acoustics)() {
  if (!acoustic_msg__msg__Acoustics__rosidl_typesupport_introspection_c__Acoustics_message_type_support_handle.typesupport_identifier) {
    acoustic_msg__msg__Acoustics__rosidl_typesupport_introspection_c__Acoustics_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &acoustic_msg__msg__Acoustics__rosidl_typesupport_introspection_c__Acoustics_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
