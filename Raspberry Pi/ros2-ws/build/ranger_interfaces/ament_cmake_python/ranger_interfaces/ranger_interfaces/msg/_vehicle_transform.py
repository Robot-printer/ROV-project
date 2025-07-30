# generated from rosidl_generator_py/resource/_idl.py.em
# with input from ranger_interfaces:msg/VehicleTransform.idl
# generated code does not contain a copyright notice

# This is being done at the module level and not on the instance level to avoid looking
# for the same variable multiple times on each instance. This variable is not supposed to
# change during runtime so it makes sense to only look for it once.
from os import getenv

ros_python_check_fields = getenv('ROS_PYTHON_CHECK_FIELDS', default='')


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_VehicleTransform(type):
    """Metaclass of message 'VehicleTransform'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('ranger_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'ranger_interfaces.msg.VehicleTransform')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__vehicle_transform
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__vehicle_transform
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__vehicle_transform
            cls._TYPE_SUPPORT = module.type_support_msg__msg__vehicle_transform
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__vehicle_transform

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class VehicleTransform(metaclass=Metaclass_VehicleTransform):
    """Message class 'VehicleTransform'."""

    __slots__ = [
        '_x_pos',
        '_y_pos',
        '_z_pos',
        '_x_rot',
        '_y_rot',
        '_z_rot',
        '_check_fields',
    ]

    _fields_and_field_types = {
        'x_pos': 'double',
        'y_pos': 'double',
        'z_pos': 'double',
        'x_rot': 'double',
        'y_rot': 'double',
        'z_rot': 'double',
    }

    # This attribute is used to store an rosidl_parser.definition variable
    # related to the data type of each of the components the message.
    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        if 'check_fields' in kwargs:
            self._check_fields = kwargs['check_fields']
        else:
            self._check_fields = ros_python_check_fields == '1'
        if self._check_fields:
            assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
                'Invalid arguments passed to constructor: %s' % \
                ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.x_pos = kwargs.get('x_pos', float())
        self.y_pos = kwargs.get('y_pos', float())
        self.z_pos = kwargs.get('z_pos', float())
        self.x_rot = kwargs.get('x_rot', float())
        self.y_rot = kwargs.get('y_rot', float())
        self.z_rot = kwargs.get('z_rot', float())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.get_fields_and_field_types().keys(), self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    if self._check_fields:
                        assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.x_pos != other.x_pos:
            return False
        if self.y_pos != other.y_pos:
            return False
        if self.z_pos != other.z_pos:
            return False
        if self.x_rot != other.x_rot:
            return False
        if self.y_rot != other.y_rot:
            return False
        if self.z_rot != other.z_rot:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def x_pos(self):
        """Message field 'x_pos'."""
        return self._x_pos

    @x_pos.setter
    def x_pos(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'x_pos' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'x_pos' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._x_pos = value

    @builtins.property
    def y_pos(self):
        """Message field 'y_pos'."""
        return self._y_pos

    @y_pos.setter
    def y_pos(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'y_pos' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'y_pos' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._y_pos = value

    @builtins.property
    def z_pos(self):
        """Message field 'z_pos'."""
        return self._z_pos

    @z_pos.setter
    def z_pos(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'z_pos' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'z_pos' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._z_pos = value

    @builtins.property
    def x_rot(self):
        """Message field 'x_rot'."""
        return self._x_rot

    @x_rot.setter
    def x_rot(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'x_rot' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'x_rot' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._x_rot = value

    @builtins.property
    def y_rot(self):
        """Message field 'y_rot'."""
        return self._y_rot

    @y_rot.setter
    def y_rot(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'y_rot' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'y_rot' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._y_rot = value

    @builtins.property
    def z_rot(self):
        """Message field 'z_rot'."""
        return self._z_rot

    @z_rot.setter
    def z_rot(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'z_rot' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'z_rot' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._z_rot = value
