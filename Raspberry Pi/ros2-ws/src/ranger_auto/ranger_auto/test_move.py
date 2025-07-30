import rclpy
from rclpy.executors import ExternalShutdownException
from rclpy.node import Node

from ranger_interfaces.msg import MovementVector

import time

class TestDriver(Node):
    
    def __init__(self):
        super().__init__('test_driver')
        self.movement_publisher = self.create_publisher(MovementVector, 'movement_vector_data', 10)
    

    def simple_drive_routine(self):
        vector:MovementVector
        
        time.sleep(10)

        vector.z = 1
        self.movement_publisher.publish(vector)
        time.sleep(3)

        vector.z = 0
        self.movement_publisher.publish(vector)
        time.sleep(1)

        vector.yaw = 1
        self.movement_publisher.publish(vector)
        time.sleep(5)

        vector.yaw = 0
        self.movement_publisher.publish(vector)
        time.sleep(1)

        vector.z = 1
        self.movement_publisher.publish(vector)
        time.sleep(3)

        vector.z = 0
        self.movement_publisher.publish(vector)
        time.sleep(1)

