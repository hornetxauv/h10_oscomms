// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from acoustic_msg:msg/Acoustic.idl
// generated code does not contain a copyright notice
#include "acoustic_msg/msg/detail/acoustic__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
acoustic_msg__msg__Acoustic__init(acoustic_msg__msg__Acoustic * msg)
{
  if (!msg) {
    return false;
  }
  // x
  // y
  // z
  // comms_bouy_out
  return true;
}

void
acoustic_msg__msg__Acoustic__fini(acoustic_msg__msg__Acoustic * msg)
{
  if (!msg) {
    return;
  }
  // x
  // y
  // z
  // comms_bouy_out
}

bool
acoustic_msg__msg__Acoustic__are_equal(const acoustic_msg__msg__Acoustic * lhs, const acoustic_msg__msg__Acoustic * rhs)
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
  // comms_bouy_out
  if (lhs->comms_bouy_out != rhs->comms_bouy_out) {
    return false;
  }
  return true;
}

bool
acoustic_msg__msg__Acoustic__copy(
  const acoustic_msg__msg__Acoustic * input,
  acoustic_msg__msg__Acoustic * output)
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
  // comms_bouy_out
  output->comms_bouy_out = input->comms_bouy_out;
  return true;
}

acoustic_msg__msg__Acoustic *
acoustic_msg__msg__Acoustic__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  acoustic_msg__msg__Acoustic * msg = (acoustic_msg__msg__Acoustic *)allocator.allocate(sizeof(acoustic_msg__msg__Acoustic), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(acoustic_msg__msg__Acoustic));
  bool success = acoustic_msg__msg__Acoustic__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
acoustic_msg__msg__Acoustic__destroy(acoustic_msg__msg__Acoustic * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    acoustic_msg__msg__Acoustic__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
acoustic_msg__msg__Acoustic__Sequence__init(acoustic_msg__msg__Acoustic__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  acoustic_msg__msg__Acoustic * data = NULL;

  if (size) {
    data = (acoustic_msg__msg__Acoustic *)allocator.zero_allocate(size, sizeof(acoustic_msg__msg__Acoustic), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = acoustic_msg__msg__Acoustic__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        acoustic_msg__msg__Acoustic__fini(&data[i - 1]);
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
acoustic_msg__msg__Acoustic__Sequence__fini(acoustic_msg__msg__Acoustic__Sequence * array)
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
      acoustic_msg__msg__Acoustic__fini(&array->data[i]);
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

acoustic_msg__msg__Acoustic__Sequence *
acoustic_msg__msg__Acoustic__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  acoustic_msg__msg__Acoustic__Sequence * array = (acoustic_msg__msg__Acoustic__Sequence *)allocator.allocate(sizeof(acoustic_msg__msg__Acoustic__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = acoustic_msg__msg__Acoustic__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
acoustic_msg__msg__Acoustic__Sequence__destroy(acoustic_msg__msg__Acoustic__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    acoustic_msg__msg__Acoustic__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
acoustic_msg__msg__Acoustic__Sequence__are_equal(const acoustic_msg__msg__Acoustic__Sequence * lhs, const acoustic_msg__msg__Acoustic__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!acoustic_msg__msg__Acoustic__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
acoustic_msg__msg__Acoustic__Sequence__copy(
  const acoustic_msg__msg__Acoustic__Sequence * input,
  acoustic_msg__msg__Acoustic__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(acoustic_msg__msg__Acoustic);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    acoustic_msg__msg__Acoustic * data =
      (acoustic_msg__msg__Acoustic *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!acoustic_msg__msg__Acoustic__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          acoustic_msg__msg__Acoustic__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!acoustic_msg__msg__Acoustic__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
