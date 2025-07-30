// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from ranger_interfaces:msg/MovementVector.idl
// generated code does not contain a copyright notice

#include "ranger_interfaces/msg/detail/movement_vector__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_ranger_interfaces
const rosidl_type_hash_t *
ranger_interfaces__msg__MovementVector__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xfa, 0x2d, 0x29, 0x8a, 0xe2, 0x73, 0xfb, 0xe6,
      0xf0, 0xe1, 0xa9, 0x35, 0x2c, 0x21, 0x49, 0x40,
      0x7a, 0xba, 0x01, 0x04, 0xa2, 0x24, 0xd1, 0xf5,
      0x12, 0x55, 0x38, 0x51, 0x91, 0x0a, 0x19, 0xf3,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char ranger_interfaces__msg__MovementVector__TYPE_NAME[] = "ranger_interfaces/msg/MovementVector";

// Define type names, field names, and default values
static char ranger_interfaces__msg__MovementVector__FIELD_NAME__x[] = "x";
static char ranger_interfaces__msg__MovementVector__FIELD_NAME__y[] = "y";
static char ranger_interfaces__msg__MovementVector__FIELD_NAME__z[] = "z";
static char ranger_interfaces__msg__MovementVector__FIELD_NAME__roll[] = "roll";
static char ranger_interfaces__msg__MovementVector__FIELD_NAME__pitch[] = "pitch";
static char ranger_interfaces__msg__MovementVector__FIELD_NAME__yaw[] = "yaw";

static rosidl_runtime_c__type_description__Field ranger_interfaces__msg__MovementVector__FIELDS[] = {
  {
    {ranger_interfaces__msg__MovementVector__FIELD_NAME__x, 1, 1},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {ranger_interfaces__msg__MovementVector__FIELD_NAME__y, 1, 1},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {ranger_interfaces__msg__MovementVector__FIELD_NAME__z, 1, 1},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {ranger_interfaces__msg__MovementVector__FIELD_NAME__roll, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {ranger_interfaces__msg__MovementVector__FIELD_NAME__pitch, 5, 5},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {ranger_interfaces__msg__MovementVector__FIELD_NAME__yaw, 3, 3},
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
ranger_interfaces__msg__MovementVector__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {ranger_interfaces__msg__MovementVector__TYPE_NAME, 36, 36},
      {ranger_interfaces__msg__MovementVector__FIELDS, 6, 6},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "float64 x\n"
  "float64 y\n"
  "float64 z\n"
  "\n"
  "float64 roll\n"
  "float64 pitch\n"
  "float64 yaw";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
ranger_interfaces__msg__MovementVector__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {ranger_interfaces__msg__MovementVector__TYPE_NAME, 36, 36},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 69, 69},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
ranger_interfaces__msg__MovementVector__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *ranger_interfaces__msg__MovementVector__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
