// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from ranger_interfaces:msg/WaypointDistance.idl
// generated code does not contain a copyright notice

#include "ranger_interfaces/msg/detail/waypoint_distance__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_ranger_interfaces
const rosidl_type_hash_t *
ranger_interfaces__msg__WaypointDistance__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xd2, 0xa9, 0xdd, 0x71, 0xd2, 0xa4, 0xeb, 0xe6,
      0xf1, 0xe1, 0x0f, 0x80, 0x5a, 0x07, 0xf2, 0x20,
      0x39, 0xd9, 0x04, 0x86, 0xc3, 0x0d, 0x60, 0x27,
      0xd1, 0x74, 0x52, 0x87, 0x4c, 0xc0, 0x55, 0x89,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char ranger_interfaces__msg__WaypointDistance__TYPE_NAME[] = "ranger_interfaces/msg/WaypointDistance";

// Define type names, field names, and default values
static char ranger_interfaces__msg__WaypointDistance__FIELD_NAME__id[] = "id";
static char ranger_interfaces__msg__WaypointDistance__FIELD_NAME__value[] = "value";

static rosidl_runtime_c__type_description__Field ranger_interfaces__msg__WaypointDistance__FIELDS[] = {
  {
    {ranger_interfaces__msg__WaypointDistance__FIELD_NAME__id, 2, 2},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT64,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {ranger_interfaces__msg__WaypointDistance__FIELD_NAME__value, 5, 5},
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
ranger_interfaces__msg__WaypointDistance__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {ranger_interfaces__msg__WaypointDistance__TYPE_NAME, 38, 38},
      {ranger_interfaces__msg__WaypointDistance__FIELDS, 2, 2},
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
  "float64 value";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
ranger_interfaces__msg__WaypointDistance__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {ranger_interfaces__msg__WaypointDistance__TYPE_NAME, 38, 38},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 22, 22},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
ranger_interfaces__msg__WaypointDistance__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *ranger_interfaces__msg__WaypointDistance__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
