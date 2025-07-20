// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from ranger_interfaces:msg/VehicleTransform.idl
// generated code does not contain a copyright notice

#include "ranger_interfaces/msg/detail/vehicle_transform__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_ranger_interfaces
const rosidl_type_hash_t *
ranger_interfaces__msg__VehicleTransform__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x65, 0x8a, 0xbb, 0x0e, 0x8a, 0xe2, 0x25, 0x5b,
      0x53, 0x57, 0x58, 0xd4, 0x56, 0xe6, 0xfc, 0xfe,
      0xfa, 0x18, 0x51, 0xce, 0x49, 0x70, 0x69, 0x1a,
      0x6e, 0xed, 0x1e, 0xc7, 0x69, 0x67, 0x13, 0xdf,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char ranger_interfaces__msg__VehicleTransform__TYPE_NAME[] = "ranger_interfaces/msg/VehicleTransform";

// Define type names, field names, and default values
static char ranger_interfaces__msg__VehicleTransform__FIELD_NAME__x_pos[] = "x_pos";
static char ranger_interfaces__msg__VehicleTransform__FIELD_NAME__y_pos[] = "y_pos";
static char ranger_interfaces__msg__VehicleTransform__FIELD_NAME__z_pos[] = "z_pos";
static char ranger_interfaces__msg__VehicleTransform__FIELD_NAME__x_rot[] = "x_rot";
static char ranger_interfaces__msg__VehicleTransform__FIELD_NAME__y_rot[] = "y_rot";
static char ranger_interfaces__msg__VehicleTransform__FIELD_NAME__z_rot[] = "z_rot";

static rosidl_runtime_c__type_description__Field ranger_interfaces__msg__VehicleTransform__FIELDS[] = {
  {
    {ranger_interfaces__msg__VehicleTransform__FIELD_NAME__x_pos, 5, 5},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {ranger_interfaces__msg__VehicleTransform__FIELD_NAME__y_pos, 5, 5},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {ranger_interfaces__msg__VehicleTransform__FIELD_NAME__z_pos, 5, 5},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {ranger_interfaces__msg__VehicleTransform__FIELD_NAME__x_rot, 5, 5},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {ranger_interfaces__msg__VehicleTransform__FIELD_NAME__y_rot, 5, 5},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {ranger_interfaces__msg__VehicleTransform__FIELD_NAME__z_rot, 5, 5},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
ranger_interfaces__msg__VehicleTransform__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {ranger_interfaces__msg__VehicleTransform__TYPE_NAME, 38, 38},
      {ranger_interfaces__msg__VehicleTransform__FIELDS, 6, 6},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "float64 x_pos\n"
  "float64 y_pos\n"
  "float64 z_pos\n"
  "float64 x_rot\n"
  "float64 y_rot\n"
  "float64 z_rot";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
ranger_interfaces__msg__VehicleTransform__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {ranger_interfaces__msg__VehicleTransform__TYPE_NAME, 38, 38},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 84, 84},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
ranger_interfaces__msg__VehicleTransform__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *ranger_interfaces__msg__VehicleTransform__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
