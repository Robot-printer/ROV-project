class_name Ultrasonic_Sensor
extends Area3D

@export var sensor_range:float = 5
@export var angle:float = 8

@onready var collider:CollisionShape3D = $CollisionShape3D
var collider_shape:CylinderShape3D = collider.shape

func _ready() -> void:
	collider_shape.height = sensor_range
	collider.position.z = -sensor_range / 2
