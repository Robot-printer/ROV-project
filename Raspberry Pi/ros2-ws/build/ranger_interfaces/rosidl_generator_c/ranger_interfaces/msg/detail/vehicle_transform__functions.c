// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from ranger_interfaces:msg/VehicleTransform.idl
// generated code does not contain a copyright notice
#include "ranger_interfaces/msg/detail/vehicle_transform__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
ranger_interfaces__msg__VehicleTransform__init(ranger_interfaces__msg__VehicleTransform * msg)
{
  if (!msg) {
    return false;
  }
  // x_pos
  // y_pos
  // z_pos
  // x_rot
  // y_rot
  // z_rot
  return true;
}

void
ranger_interfaces__msg__VehicleTransform__fini(ranger_interfaces__msg__VehicleTransform * msg)
{
  if (!msg) {
    return;
  }
  // x_pos
  // y_pos
  // z_pos
  // x_rot
  // y_rot
  // z_rot
}

bool
ranger_interfaces__msg__VehicleTransform__are_equal(const ranger_interfaces__msg__VehicleTransform * lhs, const ranger_interfaces__msg__VehicleTransform * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // x_pos
  if (lhs->x_pos != rhs->x_pos) {
    return false;
  }
  // y_pos
  if (lhs->y_pos != rhs->y_pos) {
    return false;
  }
  // z_pos
  if (lhs->z_pos != rhs->z_pos) {
    return false;
  }
  // x_rot
  if (lhs->x_rot != rhs->x_rot) {
    return false;
  }
  // y_rot
  if (lhs->y_rot != rhs->y_rot) {
    return false;
  }
  // z_rot
  if (lhs->z_rot != rhs->z_rot) {
    return false;
  }
  return true;
}

bool
ranger_interfaces__msg__VehicleTransform__copy(
  const ranger_interfaces__msg__VehicleTransform * input,
  ranger_interfaces__msg__VehicleTransform * output)
{
  if (!input || !output) {
    return false;
  }
  // x_pos
  output->x_pos = input->x_pos;
  // y_pos
  output->y_pos = input->y_pos;
  // z_pos
  output->z_pos = input->z_pos;
  // x_rot
  output->x_rot = input->x_rot;
  // y_rot
  output->y_rot = input->y_rot;
  // z_rot
  output->z_rot = input->z_rot;
  return true;
}

ranger_interfaces__msg__VehicleTransform *
ranger_interfaces__msg__VehicleTransform__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ranger_interfaces__msg__VehicleTransform * msg = (ranger_interfaces__msg__VehicleTransform *)allocator.allocate(sizeof(ranger_interfaces__msg__VehicleTransform), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(ranger_interfaces__msg__VehicleTransform));
  bool success = ranger_interfaces__msg__VehicleTransform__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
ranger_interfaces__msg__VehicleTransform__destroy(ranger_interfaces__msg__VehicleTransform * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    ranger_interfaces__msg__VehicleTransform__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
ranger_interfaces__msg__VehicleTransform__Sequence__init(ranger_interfaces__msg__VehicleTransform__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ranger_interfaces__msg__VehicleTransform * data = NULL;

  if (size) {
    data = (ranger_interfaces__msg__VehicleTransform *)allocator.zero_allocate(size, sizeof(ranger_interfaces__msg__VehicleTransform), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = ranger_interfaces__msg__VehicleTransform__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        ranger_interfaces__msg__VehicleTransform__fini(&data[i - 1]);
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
ranger_interfaces__msg__VehicleTransform__Sequence__fini(ranger_interfaces__msg__VehicleTransform__Sequence * array)
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
      ranger_interfaces__msg__VehicleTransform__fini(&array->data[i]);
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

ranger_interfaces__msg__VehicleTransform__Sequence *
ranger_interfaces__msg__VehicleTransform__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ranger_interfaces__msg__VehicleTransform__Sequence * array = (ranger_interfaces__msg__VehicleTransform__Sequence *)allocator.allocate(sizeof(ranger_interfaces__msg__VehicleTransform__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = ranger_interfaces__msg__VehicleTransform__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
ranger_interfaces__msg__VehicleTransform__Sequence__destroy(ranger_interfaces__msg__VehicleTransform__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    ranger_interfaces__msg__VehicleTransform__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
ranger_interfaces__msg__VehicleTransform__Sequence__are_equal(const ranger_interfaces__msg__VehicleTransform__Sequence * lhs, const ranger_interfaces__msg__VehicleTransform__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!ranger_interfaces__msg__VehicleTransform__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
ranger_interfaces__msg__VehicleTransform__Sequence__copy(
  const ranger_interfaces__msg__VehicleTransform__Sequence * input,
  ranger_interfaces__msg__VehicleTransform__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(ranger_interfaces__msg__VehicleTransform);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    ranger_interfaces__msg__VehicleTransform * data =
      (ranger_interfaces__msg__VehicleTransform *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!ranger_interfaces__msg__VehicleTransform__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          ranger_interfaces__msg__VehicleTransform__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!ranger_interfaces__msg__VehicleTransform__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
