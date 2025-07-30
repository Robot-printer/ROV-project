// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from ranger_interfaces:msg/IMUMagnet.idl
// generated code does not contain a copyright notice

#include "ranger_interfaces/msg/detail/imu_magnet__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_ranger_interfaces
const rosidl_type_hash_t *
ranger_interfaces__msg__IMUMagnet__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xf8, 0xcc, 0x60, 0x9a, 0x3b, 0x65, 0xa5, 0x01,
      0x9f, 0x6d, 0x5f, 0x2a, 0x2c, 0x90, 0x47, 0x73,
      0xf0, 0xc5, 0xe2, 0x19, 0x10, 0x11, 0x42, 0xca,
      0x26, 0xea, 0xd6, 0x0a, 0x08, 0xcd, 0x8c, 0x32,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char ranger_interfaces__msg__IMUMagnet__TYPE_NAME[] = "ranger_interfaces/msg/IMUMagnet";

// Define type names, field names, and default values
static char ranger_interfaces__msg__IMUMagnet__FIELD_NAME__id[] = "id";
static char ranger_interfaces__msg__IMUMagnet__FIELD_NAME__x[] = "x";
static char ranger_interfaces__msg__IMUMagnet__FIELD_NAME__y[] = "y";
static char ranger_interfaces__msg__IMUMagnet__FIELD_NAME__z[] = "z";

static rosidl_runtime_c__type_description__Field ranger_interfaces__msg__IMUMagnet__FIELDS[] = {
  {
    {ranger_interfaces__msg__IMUMagnet__FIELD_NAME__id, 2, 2},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT64,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {ranger_interfaces__msg__IMUMagnet__FIELD_NAME__x, 1, 1},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {ranger_interfaces__msg__IMUMagnet__FIELD_NAME__y, 1, 1},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {ranger_interfaces__msg__IMUMagnet__FIELD_NAME__z, 1, 1},
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
ranger_interfaces__msg__IMUMagnet__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {ranger_interfaces__msg__IMUMagnet__TYPE_NAME, 31, 31},
      {ranger_interfaces__msg__IMUMagnet__FIELDS, 4, 4},
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
  "float64 x\n"
  "float64 y\n"
  "float64 z";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
ranger_interfaces__msg__IMUMagnet__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {ranger_interfaces__msg__IMUMagnet__TYPE_NAME, 31, 31},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 38, 38},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
ranger_interfaces__msg__IMUMagnet__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *ranger_interfaces__msg__IMUMagnet__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
