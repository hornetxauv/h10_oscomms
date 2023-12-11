// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from acoustic_msg:msg/Acoustics.idl
// generated code does not contain a copyright notice

#ifndef ACOUSTIC_MSG__MSG__DETAIL__ACOUSTICS__STRUCT_H_
#define ACOUSTIC_MSG__MSG__DETAIL__ACOUSTICS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/Acoustics in the package acoustic_msg.
typedef struct acoustic_msg__msg__Acoustics
{
  double comms_bouy_output;
  double x;
  double y;
  double z;
} acoustic_msg__msg__Acoustics;

// Struct for a sequence of acoustic_msg__msg__Acoustics.
typedef struct acoustic_msg__msg__Acoustics__Sequence
{
  acoustic_msg__msg__Acoustics * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} acoustic_msg__msg__Acoustics__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ACOUSTIC_MSG__MSG__DETAIL__ACOUSTICS__STRUCT_H_
