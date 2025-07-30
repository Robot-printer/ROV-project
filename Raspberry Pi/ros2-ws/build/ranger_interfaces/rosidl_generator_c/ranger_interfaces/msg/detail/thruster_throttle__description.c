// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from ranger_interfaces:msg/ThrusterThrottle.idl
// generated code does not contain a copyright notice

#include "ranger_interfaces/msg/detail/thruster_throttle__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_ranger_interfaces
const rosidl_type_hash_t *
ranger_interfaces__msg__ThrusterThrottle__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xe9, 0xbc, 0x1a, 0xa7, 0x29, 0x13, 0xdd, 0x95,
      0x24, 0x4c, 0x55, 0xba, 0x6b, 0x14, 0x1b, 0xba,
      0xd0, 0x9f, 0xa0, 0x25, 0x8f, 0x43, 0x72, 0xb2,
      0x8c, 0x01, 0x37, 0x84, 0x1d, 0xac, 0x19, 0xe1,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char ranger_interfaces__msg__ThrusterThrottle__TYPE_NAME[] = "ranger_interfaces/msg/ThrusterThrottle";

// Define type names, field names, and default values
static char ranger_interfaces__msg__ThrusterThrottle__FIELD_NAME__id[] = "id";
static char ranger_interfaces__msg__ThrusterThrottle__FIELD_NAME__value[] = "value";

static rosidl_runtime_c__type_description__Field ranger_interfaces__msg__ThrusterThrottle__FIELDS[] = {
  {
    {ranger_interfaces__msg__ThrusterThrottle__FIELD_NAME__id, 2, 2},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT64,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {ranger_interfaces__msg__ThrusterThrottle__FIELD_NAME__value, 5, 5},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT64,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
ranger_interfaces__msg__ThrusterThrottle__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {ranger_interfaces__msg__ThrusterThrottle__TYPE_NAME, 38, 38},
      {ranger_interfaces__msg__ThrusterThrottle__FIELDS, 2, 2},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "int64 id\n"
  "int64 value";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
ranger_interfaces__msg__ThrusterThrottle__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {ranger_interfaces__msg__ThrusterThrottle__TYPE_NAME, 38, 38},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 20, 20},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
ranger_interfaces__msg__ThrusterThrottle__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *ranger_interfaces__msg__ThrusterThrottle__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
