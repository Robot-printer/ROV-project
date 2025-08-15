import rclpy
from rclpy.executors import ExternalShutdownException
from rclpy.node import Node

from ranger_interfaces.msg import ThrusterThrottle, MovementVector, String
from sensor_msgs.msg import Imu, MagneticField, Range

class DebugListener(Node):
    
    def __init__(self):
        super().__init__('debug_listener')
        self.generic_debug_listener = self.create_subscription(String, 'debug_data', generic_debug_callback, 10)
        self.throttle_listener = self.create_subscription(ThrusterThrottle, 'throttle_data', throttle_data_callback, 10)
        self.movement_listener = self.create_subscription(MovementVector, 'movement_vector_data', movement_vector_callback, 10)
        self.imu_listener = self.create_subscription(Imu, 'imu_data', imu_data_callback, 10)
        self.magnet_listener = self.create_subscription(MagneticField, 'magnetometer_data', magnet_data_callback, 10)
        self.ultrasonic_listener = self.create_subscription(Range, 'ultrasonic_data', ultrasonic_data_callback, 10)
        
    
def generic_debug_callback(data:String):
    print(data)

def throttle_data_callback(data:ThrusterThrottle):
    print(data)

def movement_vector_callback(data:MovementVector):
    print(data)

def imu_data_callback(data:Imu):
    pass

def magnet_data_callback(data:MagneticField):
    pass

def ultrasonic_data_callback(data:Range):
    pass

def main(args=None):
    try:
        with rclpy.init(args=args):
            debug_listener = DebugListener()

            rclpy.spin(debug_listener)
    except (KeyboardInterrupt, ExternalShutdownException):
        pass  

if __name__ == '__main__':
    main()