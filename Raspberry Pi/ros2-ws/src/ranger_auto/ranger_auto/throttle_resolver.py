import rclpy
from rclpy.executors import ExternalShutdownException
from rclpy.node import Node

from ranger_interfaces.msg import ThrusterThrottle

class ThrottleResolver(Node):
    
    thrusters = []

    def __init__(self):
        super().__init__('throttle_resolver')
        self.throttle_publisher = self.create_publisher(ThrusterThrottle, 'throttle_data', 10)

        self.thrusters.append(Thruster(1, [0,0,0], [0, -1, 0, 0.5,0, 0.5])) # Thruster 1
        self.thrusters.append(Thruster(2, [0,0,0], [0,  1, 0, 0.5,0,-0.5])) # Thruster 2
        self.thrusters.append(Thruster(3, [0,0,0], [0, -1, 0, 0.5,0, 0.5])) # Thruster 3
        self.thrusters.append(Thruster(4, [0,0,0], [0,  1, 0, 0.5,0,-0.5])) # Thruster 4
        self.thrusters.append(Thruster(5, [0,0,0], [1,  0, 1, 0,  1, 0])) # Thruster 5
        self.thrusters.append(Thruster(6, [0,0,0], [1,  0,-1, 0,  1, 0])) # Thruster 6
        self.thrusters.append(Thruster(7, [0,0,0], [-1, 0, 1, 0,  1, 0])) # Thruster 7
        self.thrusters.append(Thruster(8, [0,0,0], [-1, 0,-1, 0,  1, 0])) # Thruster 8
    
    def calculate_throttles(self, translation_input, rotation_input):

        for thruster in self.thrusters:
            pitch_comp = thruster.actuation_components[0] * rotation_input[0]
            yaw_comp = thruster.actuation_components[1] * rotation_input[1]
            roll_comp = thruster.actuation_components[2] * rotation_input[2]
            lateral_comp = thruster.actuation_components[3] * translation_input[0]
            vertical_comp = thruster.actuation_components[4] * translation_input[1]
            longitudinal_comp = thruster.actuation_components[5] * translation_input[2]

            throttle = pitch_comp + yaw_comp + roll_comp + lateral_comp + vertical_comp + longitudinal_comp
            throttle = throttle * 100

            pub = ThrusterThrottle()
            pub.id = thruster.id_num
            pub.value = throttle

            self.throttle_publisher.publish(pub)
    

class Thruster():

    id_num:int
    position = [0,0,0] # X, Y, Z
    actuation_components = [0,0,0, 0,0,0] # Pitch, Yaw, Roll,  Lateral, Vertical, Horizontal

    def __init__(self, id_num, pos, actuation_comps):
        self.id_num = id_num
        self.position = pos
        self.actuation_components = actuation_comps

def main(args=None):
    try:
        with rclpy.init(args=args):
            throttle_resolver = ThrottleResolver()

            rclpy.spin(throttle_resolver)
    except (KeyboardInterrupt, ExternalShutdownException):
        pass

if __name__ == '__main__':
    main()