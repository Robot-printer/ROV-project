// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from ranger_interfaces:msg/String.idl
// generated code does not contain a copyright notice

#include "ranger_interfaces/msg/detail/string__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_ranger_interfaces
const rosidl_type_hash_t *
ranger_interfaces__msg__String__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xd6, 0x6c, 0x83, 0xca, 0x47, 0x1f, 0xc8, 0x96,
      0x77, 0x53, 0x37, 0xfa, 0x2d, 0x64, 0xca, 0x4f,
      0x78, 0x27, 0xcf, 0xf8, 0x31, 0xd7, 0xbe, 0x62,
      0x10, 0xd4, 0xde, 0xb4, 0xb9, 0x40, 0xc2, 0x19,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char ranger_interfaces__msg__String__TYPE_NAME[] = "ranger_interfaces/msg/String";

// Define type names, field names, and default values
static char ranger_interfaces__msg__String__FIELD_NAME__data[] = "data";

static rosidl_runtime_c__type_description__Field ranger_interfaces__msg__String__FIELDS[] = {
  {
    {ranger_interfaces__msg__String__FIELD_NAME__data, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
ranger_interfaces__msg__String__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {ranger_interfaces__msg__String__TYPE_NAME, 28, 28},
      {ranger_interfaces__msg__String__FIELDS, 1, 1},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "string data";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
ranger_interfaces__msg__String__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {ranger_interfaces__msg__String__TYPE_NAME, 28, 28},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 11, 11},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
ranger_interfaces__msg__String__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *ranger_interfaces__msg__String__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
