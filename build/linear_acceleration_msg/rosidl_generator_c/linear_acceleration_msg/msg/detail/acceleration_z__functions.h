// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from linear_acceleration_msg:msg/AccelerationZ.idl
// generated code does not contain a copyright notice

#ifndef LINEAR_ACCELERATION_MSG__MSG__DETAIL__ACCELERATION_Z__FUNCTIONS_H_
#define LINEAR_ACCELERATION_MSG__MSG__DETAIL__ACCELERATION_Z__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "linear_acceleration_msg/msg/rosidl_generator_c__visibility_control.h"

#include "linear_acceleration_msg/msg/detail/acceleration_z__struct.h"

/// Initialize msg/AccelerationZ message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * linear_acceleration_msg__msg__AccelerationZ
 * )) before or use
 * linear_acceleration_msg__msg__AccelerationZ__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_linear_acceleration_msg
bool
linear_acceleration_msg__msg__AccelerationZ__init(linear_acceleration_msg__msg__AccelerationZ * msg);

/// Finalize msg/AccelerationZ message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_linear_acceleration_msg
void
linear_acceleration_msg__msg__AccelerationZ__fini(linear_acceleration_msg__msg__AccelerationZ * msg);

/// Create msg/AccelerationZ message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * linear_acceleration_msg__msg__AccelerationZ__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_linear_acceleration_msg
linear_acceleration_msg__msg__AccelerationZ *
linear_acceleration_msg__msg__AccelerationZ__create();

/// Destroy msg/AccelerationZ message.
/**
 * It calls
 * linear_acceleration_msg__msg__AccelerationZ__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_linear_acceleration_msg
void
linear_acceleration_msg__msg__AccelerationZ__destroy(linear_acceleration_msg__msg__AccelerationZ * msg);

/// Check for msg/AccelerationZ message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_linear_acceleration_msg
bool
linear_acceleration_msg__msg__AccelerationZ__are_equal(const linear_acceleration_msg__msg__AccelerationZ * lhs, const linear_acceleration_msg__msg__AccelerationZ * rhs);

/// Copy a msg/AccelerationZ message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_linear_acceleration_msg
bool
linear_acceleration_msg__msg__AccelerationZ__copy(
  const linear_acceleration_msg__msg__AccelerationZ * input,
  linear_acceleration_msg__msg__AccelerationZ * output);

/// Initialize array of msg/AccelerationZ messages.
/**
 * It allocates the memory for the number of elements and calls
 * linear_acceleration_msg__msg__AccelerationZ__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_linear_acceleration_msg
bool
linear_acceleration_msg__msg__AccelerationZ__Sequence__init(linear_acceleration_msg__msg__AccelerationZ__Sequence * array, size_t size);

/// Finalize array of msg/AccelerationZ messages.
/**
 * It calls
 * linear_acceleration_msg__msg__AccelerationZ__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_linear_acceleration_msg
void
linear_acceleration_msg__msg__AccelerationZ__Sequence__fini(linear_acceleration_msg__msg__AccelerationZ__Sequence * array);

/// Create array of msg/AccelerationZ messages.
/**
 * It allocates the memory for the array and calls
 * linear_acceleration_msg__msg__AccelerationZ__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_linear_acceleration_msg
linear_acceleration_msg__msg__AccelerationZ__Sequence *
linear_acceleration_msg__msg__AccelerationZ__Sequence__create(size_t size);

/// Destroy array of msg/AccelerationZ messages.
/**
 * It calls
 * linear_acceleration_msg__msg__AccelerationZ__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_linear_acceleration_msg
void
linear_acceleration_msg__msg__AccelerationZ__Sequence__destroy(linear_acceleration_msg__msg__AccelerationZ__Sequence * array);

/// Check for msg/AccelerationZ message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_linear_acceleration_msg
bool
linear_acceleration_msg__msg__AccelerationZ__Sequence__are_equal(const linear_acceleration_msg__msg__AccelerationZ__Sequence * lhs, const linear_acceleration_msg__msg__AccelerationZ__Sequence * rhs);

/// Copy an array of msg/AccelerationZ messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_linear_acceleration_msg
bool
linear_acceleration_msg__msg__AccelerationZ__Sequence__copy(
  const linear_acceleration_msg__msg__AccelerationZ__Sequence * input,
  linear_acceleration_msg__msg__AccelerationZ__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // LINEAR_ACCELERATION_MSG__MSG__DETAIL__ACCELERATION_Z__FUNCTIONS_H_
