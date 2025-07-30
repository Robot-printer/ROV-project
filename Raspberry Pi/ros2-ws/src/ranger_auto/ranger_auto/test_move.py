import rclpy
from rclpy.executors import ExternalShutdownException
from rclpy.node import Node

from ranger_interfaces.msg import MovementVector

import time

class TestDriver(Node):
    
    def __init__(self):
        super().__init__('test_driver')
        self.movement_publisher = self.create_publisher(MovementVector, 'movement_vector_data', 10)

        self.simple_drive_routine()
    

    def simple_drive_routine(self):
        vector = MovementVector()
        
        time.sleep(10)

        print("Going forward...")
        vector.z = 1.0
        self.movement_publisher.publish(vector)
        time.sleep(3)

        print("Stopping...")
        vector.z = 0.0
        self.movement_publisher.publish(vector)
        time.sleep(1)

        print("Turning...")
        vector.yaw = 1.0
        self.movement_publisher.publish(vector)
        time.sleep(5)

        print("Stopping...")
        vector.yaw = 0.0
        self.movement_publisher.publish(vector)
        time.sleep(1)

        print("Going forward...")
        vector.z = 1.0
        self.movement_publisher.publish(vector)
        time.sleep(3)

        print("Stopping...")
        vector.z = 0.0
        self.movement_publisher.publish(vector)
        time.sleep(1)


def main(args=None):
    try:
        with rclpy.init(args=args):
            test_driver = TestDriver()

            rclpy.spin(test_driver)
    except (KeyboardInterrupt, ExternalShutdownException):
        pass

if __name__ == '__main__':
    main()
