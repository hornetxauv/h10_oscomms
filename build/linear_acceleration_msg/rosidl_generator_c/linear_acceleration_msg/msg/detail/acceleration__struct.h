// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from linear_acceleration_msg:msg/Acceleration.idl
// generated code does not contain a copyright notice

#ifndef LINEAR_ACCELERATION_MSG__MSG__DETAIL__ACCELERATION__STRUCT_H_
#define LINEAR_ACCELERATION_MSG__MSG__DETAIL__ACCELERATION__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/Acceleration in the package linear_acceleration_msg.
typedef struct linear_acceleration_msg__msg__Acceleration
{
  double x;
  double y;
  double z;
} linear_acceleration_msg__msg__Acceleration;

// Struct for a sequence of linear_acceleration_msg__msg__Acceleration.
typedef struct linear_acceleration_msg__msg__Acceleration__Sequence
{
  linear_acceleration_msg__msg__Acceleration * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} linear_acceleration_msg__msg__Acceleration__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // LINEAR_ACCELERATION_MSG__MSG__DETAIL__ACCELERATION__STRUCT_H_
