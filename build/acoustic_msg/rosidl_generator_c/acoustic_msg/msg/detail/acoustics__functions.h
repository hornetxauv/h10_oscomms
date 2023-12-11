// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from acoustic_msg:msg/Acoustics.idl
// generated code does not contain a copyright notice

#ifndef ACOUSTIC_MSG__MSG__DETAIL__ACOUSTICS__FUNCTIONS_H_
#define ACOUSTIC_MSG__MSG__DETAIL__ACOUSTICS__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "acoustic_msg/msg/rosidl_generator_c__visibility_control.h"

#include "acoustic_msg/msg/detail/acoustics__struct.h"

/// Initialize msg/Acoustics message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * acoustic_msg__msg__Acoustics
 * )) before or use
 * acoustic_msg__msg__Acoustics__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_acoustic_msg
bool
acoustic_msg__msg__Acoustics__init(acoustic_msg__msg__Acoustics * msg);

/// Finalize msg/Acoustics message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_acoustic_msg
void
acoustic_msg__msg__Acoustics__fini(acoustic_msg__msg__Acoustics * msg);

/// Create msg/Acoustics message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * acoustic_msg__msg__Acoustics__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_acoustic_msg
acoustic_msg__msg__Acoustics *
acoustic_msg__msg__Acoustics__create();

/// Destroy msg/Acoustics message.
/**
 * It calls
 * acoustic_msg__msg__Acoustics__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_acoustic_msg
void
acoustic_msg__msg__Acoustics__destroy(acoustic_msg__msg__Acoustics * msg);

/// Check for msg/Acoustics message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_acoustic_msg
bool
acoustic_msg__msg__Acoustics__are_equal(const acoustic_msg__msg__Acoustics * lhs, const acoustic_msg__msg__Acoustics * rhs);

/// Copy a msg/Acoustics message.
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
ROSIDL_GENERATOR_C_PUBLIC_acoustic_msg
bool
acoustic_msg__msg__Acoustics__copy(
  const acoustic_msg__msg__Acoustics * input,
  acoustic_msg__msg__Acoustics * output);

/// Initialize array of msg/Acoustics messages.
/**
 * It allocates the memory for the number of elements and calls
 * acoustic_msg__msg__Acoustics__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_acoustic_msg
bool
acoustic_msg__msg__Acoustics__Sequence__init(acoustic_msg__msg__Acoustics__Sequence * array, size_t size);

/// Finalize array of msg/Acoustics messages.
/**
 * It calls
 * acoustic_msg__msg__Acoustics__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_acoustic_msg
void
acoustic_msg__msg__Acoustics__Sequence__fini(acoustic_msg__msg__Acoustics__Sequence * array);

/// Create array of msg/Acoustics messages.
/**
 * It allocates the memory for the array and calls
 * acoustic_msg__msg__Acoustics__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_acoustic_msg
acoustic_msg__msg__Acoustics__Sequence *
acoustic_msg__msg__Acoustics__Sequence__create(size_t size);

/// Destroy array of msg/Acoustics messages.
/**
 * It calls
 * acoustic_msg__msg__Acoustics__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_acoustic_msg
void
acoustic_msg__msg__Acoustics__Sequence__destroy(acoustic_msg__msg__Acoustics__Sequence * array);

/// Check for msg/Acoustics message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_acoustic_msg
bool
acoustic_msg__msg__Acoustics__Sequence__are_equal(const acoustic_msg__msg__Acoustics__Sequence * lhs, const acoustic_msg__msg__Acoustics__Sequence * rhs);

/// Copy an array of msg/Acoustics messages.
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
ROSIDL_GENERATOR_C_PUBLIC_acoustic_msg
bool
acoustic_msg__msg__Acoustics__Sequence__copy(
  const acoustic_msg__msg__Acoustics__Sequence * input,
  acoustic_msg__msg__Acoustics__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // ACOUSTIC_MSG__MSG__DETAIL__ACOUSTICS__FUNCTIONS_H_
