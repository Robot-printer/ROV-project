extends BuoyantBody3D

@onready var motors = $Motors.get_children()

func _ready() -> void:
	
	for motor:Motor in motors:
		
		var leftdot = roundf(motor.basis.tdotz(Vector3.LEFT))
		var downdot = roundf(motor.basis.tdotz(Vector3.DOWN))
		var backdot = roundf(motor.basis.tdotz(Vector3.BACK))
		
		#region motor_actuation_component_assignment
		
		motor.actuation_components.pitch = sign(motor.position.z) * downdot * \
			float(not motor.control_group_exclusions.pitch)
		motor.actuation_components.yaw = sign(motor.position.x) * backdot * \
			float(not motor.control_group_exclusions.yaw)
		motor.actuation_components.roll = sign(motor.position.x) * downdot * \
			float(not motor.control_group_exclusions.roll)
		motor.actuation_components.lateral = leftdot * \
			float(not motor.control_group_exclusions.lateral)
		motor.actuation_components.vertical = downdot * \
			float(not motor.control_group_exclusions.vertical)
		motor.actuation_components.longitudinal = -backdot * \
			float(not motor.control_group_exclusions.longitudinal)
		
		#endregion
	

func _physics_process(delta: float) -> void:
	super._physics_process(delta)
	
	var translation_input = _get_translation_input()
	var rotation_input = _get_rotation_input()
	
	_calculate_motor_throttles(translation_input, rotation_input)
	
	_do_motor_thrust()
	

func _get_translation_input() -> Vector3:
	var lateral = Input.get_axis("input_lateral_negative", "input_lateral_positive")
	var vertical = Input.get_axis("input_vertical_negative", "input_vertical_positive")
	var longitudinal = Input.get_axis("input_longitudinal_negative", "input_longitudinal_positive")
	
	return Vector3(lateral, vertical, longitudinal)

func _get_rotation_input() -> Vector3:
	var pitch = Input.get_axis("input_pitch_negative", "input_pitch_positive")
	var yaw = Input.get_axis("input_yaw_negative", "input_yaw_positive")
	var roll = Input.get_axis("input_roll_negative", "input_roll_positive")
	
	return Vector3(pitch, yaw, roll)

func _calculate_motor_throttles(translation_input:Vector3, rotation_input:Vector3) -> void:
	
	for motor:Motor in motors:
		var throttle = motor.actuation_components.pitch * rotation_input.x +\
			motor.actuation_components.yaw * rotation_input.y +\
			motor.actuation_components.roll * rotation_input.z +\
			motor.actuation_components.lateral * translation_input.x +\
			motor.actuation_components.vertical * translation_input.y +\
			motor.actuation_components.longitudinal * translation_input.z
		
		_set_motor_throttle(motor, throttle)

func _set_motor_throttle(motor:Motor, throttle:float) -> void:
	motor.throttle = throttle

func _do_motor_thrust() -> void:
	for motor:Motor in motors:
		
		if motor.throttle == 0.0:
			continue
		
		self.apply_force(
			_make_vector_global(-motor.basis.z * motor.throttle),
			_make_vector_global(motor.position)
		)
