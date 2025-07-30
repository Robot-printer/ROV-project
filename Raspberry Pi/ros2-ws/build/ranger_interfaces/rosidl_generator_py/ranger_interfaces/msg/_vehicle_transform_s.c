// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from ranger_interfaces:msg/VehicleTransform.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "ranger_interfaces/msg/detail/vehicle_transform__struct.h"
#include "ranger_interfaces/msg/detail/vehicle_transform__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool ranger_interfaces__msg__vehicle_transform__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
    if (class_attr == NULL) {
      return false;
    }
    PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
    if (name_attr == NULL) {
      Py_DECREF(class_attr);
      return false;
    }
    PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
    if (module_attr == NULL) {
      Py_DECREF(name_attr);
      Py_DECREF(class_attr);
      return false;
    }

    // PyUnicode_1BYTE_DATA is just a cast
    assert(strncmp("ranger_interfaces.msg._vehicle_transform", (char *)PyUnicode_1BYTE_DATA(module_attr), 40) == 0);
    assert(strncmp("VehicleTransform", (char *)PyUnicode_1BYTE_DATA(name_attr), 16) == 0);

    Py_DECREF(module_attr);
    Py_DECREF(name_attr);
    Py_DECREF(class_attr);
  }
  ranger_interfaces__msg__VehicleTransform * ros_message = _ros_message;
  {  // x_pos
    PyObject * field = PyObject_GetAttrString(_pymsg, "x_pos");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->x_pos = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // y_pos
    PyObject * field = PyObject_GetAttrString(_pymsg, "y_pos");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->y_pos = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // z_pos
    PyObject * field = PyObject_GetAttrString(_pymsg, "z_pos");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->z_pos = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // x_rot
    PyObject * field = PyObject_GetAttrString(_pymsg, "x_rot");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->x_rot = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // y_rot
    PyObject * field = PyObject_GetAttrString(_pymsg, "y_rot");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->y_rot = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // z_rot
    PyObject * field = PyObject_GetAttrString(_pymsg, "z_rot");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->z_rot = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * ranger_interfaces__msg__vehicle_transform__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of VehicleTransform */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("ranger_interfaces.msg._vehicle_transform");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "VehicleTransform");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  ranger_interfaces__msg__VehicleTransform * ros_message = (ranger_interfaces__msg__VehicleTransform *)raw_ros_message;
  {  // x_pos
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->x_pos);
    {
      int rc = PyObject_SetAttrString(_pymessage, "x_pos", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // y_pos
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->y_pos);
    {
      int rc = PyObject_SetAttrString(_pymessage, "y_pos", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // z_pos
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->z_pos);
    {
      int rc = PyObject_SetAttrString(_pymessage, "z_pos", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // x_rot
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->x_rot);
    {
      int rc = PyObject_SetAttrString(_pymessage, "x_rot", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // y_rot
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->y_rot);
    {
      int rc = PyObject_SetAttrString(_pymessage, "y_rot", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // z_rot
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->z_rot);
    {
      int rc = PyObject_SetAttrString(_pymessage, "z_rot", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
