// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from acoustic_msg:msg/Acoustic.idl
// generated code does not contain a copyright notice

#ifndef ACOUSTIC_MSG__MSG__DETAIL__ACOUSTIC__STRUCT_H_
#define ACOUSTIC_MSG__MSG__DETAIL__ACOUSTIC__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/Acoustic in the package acoustic_msg.
typedef struct acoustic_msg__msg__Acoustic
{
  double x;
  double y;
  double z;
  double comms_bouy_out;
} acoustic_msg__msg__Acoustic;

// Struct for a sequence of acoustic_msg__msg__Acoustic.
typedef struct acoustic_msg__msg__Acoustic__Sequence
{
  acoustic_msg__msg__Acoustic * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} acoustic_msg__msg__Acoustic__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ACOUSTIC_MSG__MSG__DETAIL__ACOUSTIC__STRUCT_H_
