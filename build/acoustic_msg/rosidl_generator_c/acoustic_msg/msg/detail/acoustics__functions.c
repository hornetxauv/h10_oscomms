// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from acoustic_msg:msg/Acoustics.idl
// generated code does not contain a copyright notice
#include "acoustic_msg/msg/detail/acoustics__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
acoustic_msg__msg__Acoustics__init(acoustic_msg__msg__Acoustics * msg)
{
  if (!msg) {
    return false;
  }
  // comms_bouy_output
  // x
  // y
  // z
  return true;
}

void
acoustic_msg__msg__Acoustics__fini(acoustic_msg__msg__Acoustics * msg)
{
  if (!msg) {
    return;
  }
  // comms_bouy_output
  // x
  // y
  // z
}

bool
acoustic_msg__msg__Acoustics__are_equal(const acoustic_msg__msg__Acoustics * lhs, const acoustic_msg__msg__Acoustics * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // comms_bouy_output
  if (lhs->comms_bouy_output != rhs->comms_bouy_output) {
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
acoustic_msg__msg__Acoustics__copy(
  const acoustic_msg__msg__Acoustics * input,
  acoustic_msg__msg__Acoustics * output)
{
  if (!input || !output) {
    return false;
  }
  // comms_bouy_output
  output->comms_bouy_output = input->comms_bouy_output;
  // x
  output->x = input->x;
  // y
  output->y = input->y;
  // z
  output->z = input->z;
  return true;
}

acoustic_msg__msg__Acoustics *
acoustic_msg__msg__Acoustics__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  acoustic_msg__msg__Acoustics * msg = (acoustic_msg__msg__Acoustics *)allocator.allocate(sizeof(acoustic_msg__msg__Acoustics), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(acoustic_msg__msg__Acoustics));
  bool success = acoustic_msg__msg__Acoustics__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
acoustic_msg__msg__Acoustics__destroy(acoustic_msg__msg__Acoustics * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    acoustic_msg__msg__Acoustics__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
acoustic_msg__msg__Acoustics__Sequence__init(acoustic_msg__msg__Acoustics__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  acoustic_msg__msg__Acoustics * data = NULL;

  if (size) {
    data = (acoustic_msg__msg__Acoustics *)allocator.zero_allocate(size, sizeof(acoustic_msg__msg__Acoustics), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = acoustic_msg__msg__Acoustics__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        acoustic_msg__msg__Acoustics__fini(&data[i - 1]);
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
acoustic_msg__msg__Acoustics__Sequence__fini(acoustic_msg__msg__Acoustics__Sequence * array)
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
      acoustic_msg__msg__Acoustics__fini(&array->data[i]);
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

acoustic_msg__msg__Acoustics__Sequence *
acoustic_msg__msg__Acoustics__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  acoustic_msg__msg__Acoustics__Sequence * array = (acoustic_msg__msg__Acoustics__Sequence *)allocator.allocate(sizeof(acoustic_msg__msg__Acoustics__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = acoustic_msg__msg__Acoustics__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
acoustic_msg__msg__Acoustics__Sequence__destroy(acoustic_msg__msg__Acoustics__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    acoustic_msg__msg__Acoustics__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
acoustic_msg__msg__Acoustics__Sequence__are_equal(const acoustic_msg__msg__Acoustics__Sequence * lhs, const acoustic_msg__msg__Acoustics__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!acoustic_msg__msg__Acoustics__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
acoustic_msg__msg__Acoustics__Sequence__copy(
  const acoustic_msg__msg__Acoustics__Sequence * input,
  acoustic_msg__msg__Acoustics__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(acoustic_msg__msg__Acoustics);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    acoustic_msg__msg__Acoustics * data =
      (acoustic_msg__msg__Acoustics *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!acoustic_msg__msg__Acoustics__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          acoustic_msg__msg__Acoustics__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!acoustic_msg__msg__Acoustics__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
