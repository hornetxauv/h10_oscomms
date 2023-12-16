// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from test_msg:msg/Num.idl
// generated code does not contain a copyright notice

#ifndef TEST_MSG__MSG__DETAIL__NUM__STRUCT_H_
#define TEST_MSG__MSG__DETAIL__NUM__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/Num in the package test_msg.
typedef struct test_msg__msg__Num
{
  int64_t num;
  int64_t data;
} test_msg__msg__Num;

// Struct for a sequence of test_msg__msg__Num.
typedef struct test_msg__msg__Num__Sequence
{
  test_msg__msg__Num * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} test_msg__msg__Num__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // TEST_MSG__MSG__DETAIL__NUM__STRUCT_H_
