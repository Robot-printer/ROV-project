class_name Motor
extends Node3D

@export var max_thrust:float = 1.0

@export var control_group_exclusions:Dictionary = {
	pitch = false,
	yaw = false,
	roll = false,
	lateral = false,
	vertical = false,
	longitudinal = false
}

@onready var thruster_mesh_node = $ThrustVectorMesh

var actuation_components:Dictionary = {
	pitch = 0,
	yaw = 0,
	roll = 0,
	lateral = 0,
	vertical = 0,
	longitudinal = 0
}

var throttle:float = 0.0:
	set(value):
		throttle = clampf(value, -1.0, 1.0)

func _physics_process(_delta: float) -> void:
	thruster_mesh_node.visible = bool(throttle)
	thruster_mesh_node.scale.y = throttle
	thruster_mesh_node.position.z = thruster_mesh_node.mesh.height / 2 * throttle * 1.01
