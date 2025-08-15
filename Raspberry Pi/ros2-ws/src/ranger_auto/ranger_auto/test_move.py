import rclpy
from rclpy.executors import ExternalShutdownException
from rclpy.node import Node

from ranger_interfaces.msg import MovementVector, ThrusterThrottle

import time

class TestDriver(Node):
    
    def __init__(self):
        super().__init__('test_driver')
        self.movement_publisher = self.create_publisher(MovementVector, 'movement_vector_data', 10)
        self.throttle_publisher = self.create_publisher(ThrusterThrottle, 'throttle_data', 10)

        #self.simple_drive_routine()
        self.ramp_up()
        #self.motor_roll_call()
    

    def ramp_up(self):
        throttle = ThrusterThrottle()
        print("Beginning test")
        time.sleep(3)

        throttle.id = 1
        for i in range(1,11):
            print("Setting to " + str(i * 10) + "% power")
            
            throttle.value = i * 10
            self.throttle_publisher.publish(throttle)
            time.sleep(5)
        
        throttle.value = 0
        self.throttle_publisher.publish(throttle)

        print("Done")


    def motor_roll_call(self):
        throttle = ThrusterThrottle()
        print("Beginning test")
        time.sleep(3)

        for i in range(1,9):
            print("testing motor " + str(i))
            throttle.id = i
            throttle.value = 100
            self.throttle_publisher.publish(throttle)
            time.sleep(3)
            throttle.value = 0
            self.throttle_publisher.publish(throttle)
            time.sleep(1)
            throttle.value = -100
            self.throttle_publisher.publish(throttle)
            time.sleep(3)
            throttle.value = 0
            self.throttle_publisher.publish(throttle)
            time.sleep(1)
        
        print("Done")
        

    def simple_drive_routine(self):
        vector = MovementVector()
        
        #time.sleep(10)

        print("Submerging...")
        vector.y = -1.0
        self.movement_publisher.publish(vector)
        time.sleep(3)

        print("Stopping...")
        vector.y = 0.0
        self.movement_publisher.publish(vector)
        time.sleep(1)

        print("Going forward...")
        vector.z = 1.0
        self.movement_publisher.publish(vector)
        time.sleep(5)

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
        time.sleep(5)

        print("Stopping...")
        vector.z = 0.0
        self.movement_publisher.publish(vector)
        time.sleep(1)

        print("Surfacing...")
        vector.y = 1.0
        self.movement_publisher.publish(vector)
        time.sleep(3)

        print("Stopping...")
        vector.y = 0.0
        self.movement_publisher.publish(vector)
        time.sleep(1)

        print("Finished")


def main(args=None):
    try:
        with rclpy.init(args=args):
            test_driver = TestDriver()

            rclpy.spin(test_driver)
    except (KeyboardInterrupt, ExternalShutdownException):
        pass

if __name__ == '__main__':
    main()
