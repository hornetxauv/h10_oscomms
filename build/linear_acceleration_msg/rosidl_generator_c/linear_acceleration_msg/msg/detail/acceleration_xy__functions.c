// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from linear_acceleration_msg:msg/AccelerationXY.idl
// generated code does not contain a copyright notice
#include "linear_acceleration_msg/msg/detail/acceleration_xy__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
linear_acceleration_msg__msg__AccelerationXY__init(linear_acceleration_msg__msg__AccelerationXY * msg)
{
  if (!msg) {
    return false;
  }
  // x
  // y
  return true;
}

void
linear_acceleration_msg__msg__AccelerationXY__fini(linear_acceleration_msg__msg__AccelerationXY * msg)
{
  if (!msg) {
    return;
  }
  // x
  // y
}

bool
linear_acceleration_msg__msg__AccelerationXY__are_equal(const linear_acceleration_msg__msg__AccelerationXY * lhs, const linear_acceleration_msg__msg__AccelerationXY * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // x
  if (lhs->x != rhs->x) {
    return false;
  }
  // y
  if (lhs->y != rhs->y) {
    return false;
  }
  return true;
}

bool
linear_acceleration_msg__msg__AccelerationXY__copy(
  const linear_acceleration_msg__msg__AccelerationXY * input,
  linear_acceleration_msg__msg__AccelerationXY * output)
{
  if (!input || !output) {
    return false;
  }
  // x
  output->x = input->x;
  // y
  output->y = input->y;
  return true;
}

linear_acceleration_msg__msg__AccelerationXY *
linear_acceleration_msg__msg__AccelerationXY__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  linear_acceleration_msg__msg__AccelerationXY * msg = (linear_acceleration_msg__msg__AccelerationXY *)allocator.allocate(sizeof(linear_acceleration_msg__msg__AccelerationXY), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(linear_acceleration_msg__msg__AccelerationXY));
  bool success = linear_acceleration_msg__msg__AccelerationXY__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
linear_acceleration_msg__msg__AccelerationXY__destroy(linear_acceleration_msg__msg__AccelerationXY * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    linear_acceleration_msg__msg__AccelerationXY__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
linear_acceleration_msg__msg__AccelerationXY__Sequence__init(linear_acceleration_msg__msg__AccelerationXY__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  linear_acceleration_msg__msg__AccelerationXY * data = NULL;

  if (size) {
    data = (linear_acceleration_msg__msg__AccelerationXY *)allocator.zero_allocate(size, sizeof(linear_acceleration_msg__msg__AccelerationXY), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = linear_acceleration_msg__msg__AccelerationXY__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        linear_acceleration_msg__msg__AccelerationXY__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
linear_acceleration_msg__msg__AccelerationXY__Sequence__fini(linear_acceleration_msg__msg__AccelerationXY__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      linear_acceleration_msg__msg__AccelerationXY__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

linear_acceleration_msg__msg__AccelerationXY__Sequence *
linear_acceleration_msg__msg__AccelerationXY__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  linear_acceleration_msg__msg__AccelerationXY__Sequence * array = (linear_acceleration_msg__msg__AccelerationXY__Sequence *)allocator.allocate(sizeof(linear_acceleration_msg__msg__AccelerationXY__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = linear_acceleration_msg__msg__AccelerationXY__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
linear_acceleration_msg__msg__AccelerationXY__Sequence__destroy(linear_acceleration_msg__msg__AccelerationXY__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    linear_acceleration_msg__msg__AccelerationXY__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
linear_acceleration_msg__msg__AccelerationXY__Sequence__are_equal(const linear_acceleration_msg__msg__AccelerationXY__Sequence * lhs, const linear_acceleration_msg__msg__AccelerationXY__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!linear_acceleration_msg__msg__AccelerationXY__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
linear_acceleration_msg__msg__AccelerationXY__Sequence__copy(
  const linear_acceleration_msg__msg__AccelerationXY__Sequence * input,
  linear_acceleration_msg__msg__AccelerationXY__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(linear_acceleration_msg__msg__AccelerationXY);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    linear_acceleration_msg__msg__AccelerationXY * data =
      (linear_acceleration_msg__msg__AccelerationXY *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!linear_acceleration_msg__msg__AccelerationXY__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          linear_acceleration_msg__msg__AccelerationXY__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!linear_acceleration_msg__msg__AccelerationXY__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
