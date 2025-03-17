class_name BuoyantBody3D
extends RigidBody3D

@export var buoyant_force:float = 9.81

func _physics_process(_delta: float) -> void:
	self.apply_central_force(Vector3.UP * buoyant_force * mass)
	
	var linear_drag = linear_velocity.length_squared() * -100
	self.apply_central_force(linear_drag * linear_velocity.normalized())


func _make_vector_global(vector:Vector3) -> Vector3:
	var new_vector:Vector3 = vector
	
	new_vector = new_vector.rotated(basis.z, rotation.z)
	new_vector = new_vector.rotated(basis.x, rotation.x)
	new_vector = new_vector.rotated(basis.y, rotation.y)
	
	return new_vector
