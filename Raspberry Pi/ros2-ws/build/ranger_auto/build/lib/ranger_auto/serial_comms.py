import rclpy
from rclpy.executors import ExternalShutdownException
from rclpy.node import Node

from ranger_interfaces.msg import ThrusterThrottle
from sensor_msgs.msg import Imu, MagneticField, Range

import re

import serial


comport = '/dev/ttyACM0'
baudrate = 115200

pattern = re.compile(r'\S+')
ser = serial.Serial()

sensor_update_frequency = 5000  #Hz

latest_accel = [[0, 0, 0], [0, 0, 0], [0, 0, 0]]
latest_gyro = [[0, 0, 0], [0, 0, 0], [0, 0, 0]]

class SerialComms(Node):

    def __init__(self):
        super().__init__('serial_comms')
        open_serial(comport, baudrate)
        self.imu_publisher_ = self.create_publisher(Imu, 'imu_data', 10)
        self.magnet_publisher_ = self.create_publisher(MagneticField, 'magnetometer_data', 10)
        self.ultrasonic_publisher_ = self.create_publisher(Range, 'ultrasonic_data', 10)
        self.throttle_subscriber_ = self.create_subscription(ThrusterThrottle, 'throttle_data', throttle_data_callback, 10)
        self.timer = self.create_timer(1/sensor_update_frequency, self.timer_callback)
    
    def timer_callback(self):
        data = 0
        messages = []
        while data == 0:
            data = read_serial()
            if data != 0:
                messages.append(data)

        for message in messages:
            publishable = parse_message(message)

            if publishable != 0:
                if publishable is Imu:
                    self.imu_publisher_.publish(publishable)
                elif publishable is MagneticField:
                    self.magnet_publisher_.publish(publishable)
                elif publishable is Range:
                    self.ultrasonic_publisher_.publish(publishable)
    

def parse_message(message):
    result = pattern.split(message)
    command = result[0]
    id = result[1]
    data = []
    try:
        data = [result[2], result[3], result[4]]
    except:
        data = result[2]

    match command:
        case "ACCEL":
            latest_accel[id] = [data[0], data[1], data[2]]

            if latest_gyro[id] != [0, 0, 0]:
                pub = Imu()

                pub.header.frame_id = id
                pub.linear_acceleration.x = latest_accel[id][0]
                pub.linear_acceleration.y = latest_accel[id][1]
                pub.linear_acceleration.z = latest_accel[id][2]
                pub.angular_velocity.x = latest_gyro[id][0]
                pub.angular_velocity.y = latest_gyro[id][1]
                pub.angular_velocity.z = latest_gyro[id][2]

                latest_accel[id] = [0, 0, 0]
                latest_gyro[id] = [0, 0, 0]

                return pub


        case "GYRO":
            latest_gyro[id] = [data[0], data[1], data[2]]

            if latest_accel[id] != [0,0,0]:
                pub = Imu()

                pub.header.frame_id = id
                pub.linear_acceleration.x = latest_accel[id][0]
                pub.linear_acceleration.y = latest_accel[id][1]
                pub.linear_acceleration.z = latest_accel[id][2]
                pub.angular_velocity.x = latest_gyro[id][0]
                pub.angular_velocity.y = latest_gyro[id][1]
                pub.angular_velocity.z = latest_gyro[id][2]

                latest_accel[id] = [0, 0, 0]
                latest_gyro[id] = [0, 0, 0]

                return pub

        case "MAGNET":
            pub = MagneticField()

            pub.header.frame_id = id
            pub.magnetic_field.x = data[0]
            pub.magnetic_field.y = data[1]
            pub.magnetic_field.z = data[2]

            return pub
        case "USONIC":
            pub = Range()

            pub.header.frame_id = id
            pub.radiation_type = 0
            pub.range = data[0]

            return pub
        case _:
            return 0

def open_serial(comport, baudrate):
    global ser
    ser = serial.Serial(comport, baudrate, timeout=1.0)
    ser.reset_input_buffer()
    ser.reset_output_buffer()

def throttle_data_callback(data:ThrusterThrottle):
    message = "MOTOR " + str(data.id) + " " + str(data.value)
    write_serial(message)

def read_serial():
    global ser
    if ser.in_waiting > 0:
        data = ser.read_until(expected=b'\n')
        return data
    else:
        return 0

def write_serial(message):
    global ser
    ser.write(message)

def close_serial():
    global ser
    if ser.is_open:
        ser.close()

def main(args=None):
    try:
        with rclpy.init(args=args):
            serial_comms = SerialComms()

            rclpy.spin(serial_comms)
    except (KeyboardInterrupt, ExternalShutdownException):
        pass

if __name__ == '__main__':
    main()