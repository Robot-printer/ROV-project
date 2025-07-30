import rclpy
from rclpy.executors import ExternalShutdownException
from rclpy.node import Node

import math

from sensor_msgs.msg import Imu

previous_time_ns = 0
dt:int = 0
quat = [0,0,0,0]

class OrientationUpdater(Node):

    def __init__(self):
        super().__init__('orientation_updater')
        self.imu_subscriber_ = self.create_subscription(Imu, 'imu_data', imu_data_callback, 10)

def imu_data_callback(data:Imu):
    
    time_ns = data.header.stamp.sec * 1_000_000_000 + data.header.stamp.nanosec

    global dt
    global previous_time_ns

    if previous_time_ns != 0:
        
        dt = time_ns - previous_time_ns

        omega = [data.angular_velocity.x, data.angular_velocity.y, data.angular_velocity.z]
        omega_mag = math.sqrt(omega[0]**2 + omega[1]**2, omega[2]**2)
        theta = omega_mag * dt
        v = [omega[0] / omega_mag, omega[1] / omega_mag, omega[2] / omega_mag]

        quat_update = quaternion_from_euler(v[0], v[1], v[2])

        quat = quaternion_multiply(quat_update, quat)



    previous_time_ns = time_ns

# From https://gist.github.com/salmagro/2e698ad4fbf9dae40244769c5ab74434
def quaternion_from_euler(roll, pitch, yaw):
    """
    Converts euler roll, pitch, yaw to quaternion (w in last place)
    quat = [x, y, z, w]
    Bellow should be replaced when porting for ROS 2 Python tf_conversions is done.
    """
    cy = math.cos(yaw * 0.5)
    sy = math.sin(yaw * 0.5)
    cp = math.cos(pitch * 0.5)
    sp = math.sin(pitch * 0.5)
    cr = math.cos(roll * 0.5)
    sr = math.sin(roll * 0.5)

    q = [0] * 4
    q[0] = cy * cp * cr + sy * sp * sr
    q[1] = cy * cp * sr - sy * sp * cr
    q[2] = sy * cp * sr + cy * sp * cr
    q[3] = sy * cp * cr - cy * sp * sr

    return q

def quaternion_multiply(q1, q2):
    q_out = [0,0,0,0]

    q_out[0] = q1[0]*q2[1] + q1[1]*q2[0] + q1[2]*q2[3] - q1[3]*q2[2]
    q_out[1] = q1[0]*q2[2] - q1[1]*q2[3] + q1[2]*q2[0] + q1[3]*q2[1]
    q_out[2] = q1[0]*q2[3] + q1[1]*q2[2] - q1[2]*q2[1] + q1[3]*q2[0]
    q_out[3] = q1[0]*q2[0] - q1[1]*q2[1] - q1[2]*q2[2] - q1[3]*q2[3]

    return q_out

def main(args=None):
    try:
        with rclpy.init(args=args):
            orientation_updater = OrientationUpdater()

            rclpy.spin(orientation_updater)
    except (KeyboardInterrupt, ExternalShutdownException):
        pass

if __name__ == '__main__':
    main()