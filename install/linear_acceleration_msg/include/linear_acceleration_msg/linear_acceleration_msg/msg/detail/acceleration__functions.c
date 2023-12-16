// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from linear_acceleration_msg:msg/Acceleration.idl
// generated code does not contain a copyright notice
#include "linear_acceleration_msg/msg/detail/acceleration__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
linear_acceleration_msg__msg__Acceleration__init(linear_acceleration_msg__msg__Acceleration * msg)
{
  if (!msg) {
    return false;
  }
  // x
  // y
  // z
  return true;
}

void
linear_acceleration_msg__msg__Acceleration__fini(linear_acceleration_msg__msg__Acceleration * msg)
{
  if (!msg) {
    return;
  }
  // x
  // y
  // z
}

bool
linear_acceleration_msg__msg__Acceleration__are_equal(const linear_acceleration_msg__msg__Acceleration * lhs, const linear_acceleration_msg__msg__Acceleration * rhs)
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
  // z
  if (lhs->z != rhs->z) {
    return false;
  }
  return true;
}

bool
linear_acceleration_msg__msg__Acceleration__copy(
  const linear_acceleration_msg__msg__Acceleration * input,
  linear_acceleration_msg__msg__Acceleration * output)
{
  if (!input || !output) {
    return false;
  }
  // x
  output->x = input->x;
  // y
  output->y = input->y;
  // z
  output->z = input->z;
  return true;
}

linear_acceleration_msg__msg__Acceleration *
linear_acceleration_msg__msg__Acceleration__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  linear_acceleration_msg__msg__Acceleration * msg = (linear_acceleration_msg__msg__Acceleration *)allocator.allocate(sizeof(linear_acceleration_msg__msg__Acceleration), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(linear_acceleration_msg__msg__Acceleration));
  bool success = linear_acceleration_msg__msg__Acceleration__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
linear_acceleration_msg__msg__Acceleration__destroy(linear_acceleration_msg__msg__Acceleration * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    linear_acceleration_msg__msg__Acceleration__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
linear_acceleration_msg__msg__Acceleration__Sequence__init(linear_acceleration_msg__msg__Acceleration__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  linear_acceleration_msg__msg__Acceleration * data = NULL;

  if (size) {
    data = (linear_acceleration_msg__msg__Acceleration *)allocator.zero_allocate(size, sizeof(linear_acceleration_msg__msg__Acceleration), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = linear_acceleration_msg__msg__Acceleration__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        linear_acceleration_msg__msg__Acceleration__fini(&data[i - 1]);
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
linear_acceleration_msg__msg__Acceleration__Sequence__fini(linear_acceleration_msg__msg__Acceleration__Sequence * array)
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
      linear_acceleration_msg__msg__Acceleration__fini(&array->data[i]);
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

linear_acceleration_msg__msg__Acceleration__Sequence *
linear_acceleration_msg__msg__Acceleration__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  linear_acceleration_msg__msg__Acceleration__Sequence * array = (linear_acceleration_msg__msg__Acceleration__Sequence *)allocator.allocate(sizeof(linear_acceleration_msg__msg__Acceleration__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = linear_acceleration_msg__msg__Acceleration__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
linear_acceleration_msg__msg__Acceleration__Sequence__destroy(linear_acceleration_msg__msg__Acceleration__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    linear_acceleration_msg__msg__Acceleration__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
linear_acceleration_msg__msg__Acceleration__Sequence__are_equal(const linear_acceleration_msg__msg__Acceleration__Sequence * lhs, const linear_acceleration_msg__msg__Acceleration__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!linear_acceleration_msg__msg__Acceleration__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
linear_acceleration_msg__msg__Acceleration__Sequence__copy(
  const linear_acceleration_msg__msg__Acceleration__Sequence * input,
  linear_acceleration_msg__msg__Acceleration__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(linear_acceleration_msg__msg__Acceleration);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    linear_acceleration_msg__msg__Acceleration * data =
      (linear_acceleration_msg__msg__Acceleration *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!linear_acceleration_msg__msg__Acceleration__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          linear_acceleration_msg__msg__Acceleration__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!linear_acceleration_msg__msg__Acceleration__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
