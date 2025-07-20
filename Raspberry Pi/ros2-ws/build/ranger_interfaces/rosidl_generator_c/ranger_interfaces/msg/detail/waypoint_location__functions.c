// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from ranger_interfaces:msg/WaypointLocation.idl
// generated code does not contain a copyright notice
#include "ranger_interfaces/msg/detail/waypoint_location__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
ranger_interfaces__msg__WaypointLocation__init(ranger_interfaces__msg__WaypointLocation * msg)
{
  if (!msg) {
    return false;
  }
  // id
  // x
  // y
  // z
  return true;
}

void
ranger_interfaces__msg__WaypointLocation__fini(ranger_interfaces__msg__WaypointLocation * msg)
{
  if (!msg) {
    return;
  }
  // id
  // x
  // y
  // z
}

bool
ranger_interfaces__msg__WaypointLocation__are_equal(const ranger_interfaces__msg__WaypointLocation * lhs, const ranger_interfaces__msg__WaypointLocation * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // id
  if (lhs->id != rhs->id) {
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
ranger_interfaces__msg__WaypointLocation__copy(
  const ranger_interfaces__msg__WaypointLocation * input,
  ranger_interfaces__msg__WaypointLocation * output)
{
  if (!input || !output) {
    return false;
  }
  // id
  output->id = input->id;
  // x
  output->x = input->x;
  // y
  output->y = input->y;
  // z
  output->z = input->z;
  return true;
}

ranger_interfaces__msg__WaypointLocation *
ranger_interfaces__msg__WaypointLocation__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ranger_interfaces__msg__WaypointLocation * msg = (ranger_interfaces__msg__WaypointLocation *)allocator.allocate(sizeof(ranger_interfaces__msg__WaypointLocation), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(ranger_interfaces__msg__WaypointLocation));
  bool success = ranger_interfaces__msg__WaypointLocation__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
ranger_interfaces__msg__WaypointLocation__destroy(ranger_interfaces__msg__WaypointLocation * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    ranger_interfaces__msg__WaypointLocation__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
ranger_interfaces__msg__WaypointLocation__Sequence__init(ranger_interfaces__msg__WaypointLocation__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ranger_interfaces__msg__WaypointLocation * data = NULL;

  if (size) {
    data = (ranger_interfaces__msg__WaypointLocation *)allocator.zero_allocate(size, sizeof(ranger_interfaces__msg__WaypointLocation), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = ranger_interfaces__msg__WaypointLocation__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        ranger_interfaces__msg__WaypointLocation__fini(&data[i - 1]);
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
ranger_interfaces__msg__WaypointLocation__Sequence__fini(ranger_interfaces__msg__WaypointLocation__Sequence * array)
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
      ranger_interfaces__msg__WaypointLocation__fini(&array->data[i]);
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

ranger_interfaces__msg__WaypointLocation__Sequence *
ranger_interfaces__msg__WaypointLocation__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ranger_interfaces__msg__WaypointLocation__Sequence * array = (ranger_interfaces__msg__WaypointLocation__Sequence *)allocator.allocate(sizeof(ranger_interfaces__msg__WaypointLocation__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = ranger_interfaces__msg__WaypointLocation__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
ranger_interfaces__msg__WaypointLocation__Sequence__destroy(ranger_interfaces__msg__WaypointLocation__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    ranger_interfaces__msg__WaypointLocation__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
ranger_interfaces__msg__WaypointLocation__Sequence__are_equal(const ranger_interfaces__msg__WaypointLocation__Sequence * lhs, const ranger_interfaces__msg__WaypointLocation__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!ranger_interfaces__msg__WaypointLocation__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
ranger_interfaces__msg__WaypointLocation__Sequence__copy(
  const ranger_interfaces__msg__WaypointLocation__Sequence * input,
  ranger_interfaces__msg__WaypointLocation__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(ranger_interfaces__msg__WaypointLocation);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    ranger_interfaces__msg__WaypointLocation * data =
      (ranger_interfaces__msg__WaypointLocation *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!ranger_interfaces__msg__WaypointLocation__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          ranger_interfaces__msg__WaypointLocation__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!ranger_interfaces__msg__WaypointLocation__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
