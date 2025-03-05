import pygame
import time
import RPi.GPIO as GPIO
import threading

# --- GPIO Pin Configuration ---
# Motor Driver Pins
MOTOR_A_EN = 12  # Enable pin for Motor A (left side)
MOTOR_A_FWD = 16  # Forward pin for Motor A
MOTOR_A_BCK = 18  # Backward pin for Motor A

MOTOR_B_EN = 13  # Enable pin for Motor B (right side)
MOTOR_B_FWD = 22  # Forward pin for Motor B
MOTOR_B_BCK = 24  # Backward pin for Motor B

# --- Constants ---
PWM_FREQ = 100  # PWM frequency
MAX_SPEED = 100  # Maximum speed value (0-100)
DEADZONE = 0.1   # Joystick deadzone to ignore small movements

# PS4 Controller Mappings (these may vary, adjust as needed)
LEFT_STICK_X = 0   # Left stick horizontal
LEFT_STICK_Y = 1   # Left stick vertical
RIGHT_STICK_X = 2  # Right stick horizontal
RIGHT_STICK_Y = 3  # Right stick vertical
L2_TRIGGER = 4     # L2 trigger
R2_TRIGGER = 5     # R2 trigger

X_BUTTON = 0
CIRCLE_BUTTON = 1
TRIANGLE_BUTTON = 2
SQUARE_BUTTON = 3

# --- Setup GPIO pins ---


def setup_gpio():
    GPIO.setmode(GPIO.BCM)
    GPIO.setwarnings(False)

    # Setup Motor A pins
    GPIO.setup(MOTOR_A_EN, GPIO.OUT)
    GPIO.setup(MOTOR_A_FWD, GPIO.OUT)
    GPIO.setup(MOTOR_A_BCK, GPIO.OUT)

    # Setup Motor B pins
    GPIO.setup(MOTOR_B_EN, GPIO.OUT)
    GPIO.setup(MOTOR_B_FWD, GPIO.OUT)
    GPIO.setup(MOTOR_B_BCK, GPIO.OUT)

    # Create PWM objects
    pwm_a = GPIO.PWM(MOTOR_A_EN, PWM_FREQ)
    pwm_b = GPIO.PWM(MOTOR_B_EN, PWM_FREQ)

    # Start PWM with 0% duty cycle
    pwm_a.start(0)
    pwm_b.start(0)

    return pwm_a, pwm_b

# --- Control Functions ---


def control_motor_a(pwm, speed):
    """Control left side motors"""
    if speed > 0:  # Forward
        GPIO.output(MOTOR_A_FWD, GPIO.HIGH)
        GPIO.output(MOTOR_A_BCK, GPIO.LOW)
        pwm.ChangeDutyCycle(abs(speed))
    elif speed < 0:  # Backward
        GPIO.output(MOTOR_A_FWD, GPIO.LOW)
        GPIO.output(MOTOR_A_BCK, GPIO.HIGH)
        pwm.ChangeDutyCycle(abs(speed))
    else:  # Stop
        GPIO.output(MOTOR_A_FWD, GPIO.LOW)
        GPIO.output(MOTOR_A_BCK, GPIO.LOW)
        pwm.ChangeDutyCycle(0)


def control_motor_b(pwm, speed):
    """Control right side motors"""
    if speed > 0:  # Forward
        GPIO.output(MOTOR_B_FWD, GPIO.HIGH)
        GPIO.output(MOTOR_B_BCK, GPIO.LOW)
        pwm.ChangeDutyCycle(abs(speed))
    elif speed < 0:  # Backward
        GPIO.output(MOTOR_B_FWD, GPIO.LOW)
        GPIO.output(MOTOR_B_BCK, GPIO.HIGH)
        pwm.ChangeDutyCycle(abs(speed))
    else:  # Stop
        GPIO.output(MOTOR_B_FWD, GPIO.LOW)
        GPIO.output(MOTOR_B_BCK, GPIO.LOW)
        pwm.ChangeDutyCycle(0)


def tank_drive(pwm_a, pwm_b, left_speed, right_speed):
    """
    Control motors in tank drive mode (each stick controls one side)
    left_speed and right_speed should be between -100 and 100
    """
    control_motor_a(pwm_a, left_speed)
    control_motor_b(pwm_b, right_speed)


def arcade_drive(pwm_a, pwm_b, forward, turn):
    """
    Control motors in arcade drive mode (one stick for forward/backward, one for turning)
    forward and turn should be between -100 and 100
    """
    left_speed = forward + turn
    right_speed = forward - turn

    # Ensure we don't exceed max speed
    left_speed = max(min(left_speed, 100), -100)
    right_speed = max(min(right_speed, 100), -100)

    control_motor_a(pwm_a, left_speed)
    control_motor_b(pwm_b, right_speed)

# --- Main Program ---


def main():
    # Initialize GPIO
    pwm_a, pwm_b = setup_gpio()

    # Initialize pygame and the joystick module
    pygame.init()
    pygame.joystick.init()

    # Controller connection status
    connected = False
    joystick = None

    # Status display thread
    stop_display_thread = threading.Event()

    def display_status():
        while not stop_display_thread.is_set():
            if connected:
                # This would be a good place to add an LED indicator
                pass
            else:
                print("Waiting for controller...", end="\r")
            time.sleep(1)

    # Start status display thread
    status_thread = threading.Thread(target=display_status)
    status_thread.daemon = True
    status_thread.start()

    try:
        while True:
            # Process pygame events
            pygame.event.pump()

            # Check if controller is connected
            if pygame.joystick.get_count() > 0 and not connected:
                joystick = pygame.joystick.Joystick(0)
                joystick.init()
                connected = True
                print(f"Controller connected: {joystick.get_name()}")
                print("Control mode: Left stick = steering, Right trigger = throttle")
            elif pygame.joystick.get_count() == 0 and connected:
                connected = False
                print("Controller disconnected")
                # Stop motors when controller disconnects
                tank_drive(pwm_a, pwm_b, 0, 0)

            # If controller is connected, read inputs and control motors
            if connected:
                # Process buttons for mode selection
                drive_mode = "arcade"  # Default mode

                # Read joystick values
                if drive_mode == "tank":
                    # Tank drive mode - each stick controls one side
                    # Invert so positive is forward
                    left_y = joystick.get_axis(LEFT_STICK_Y) * -1
                    # Invert so positive is forward
                    right_y = joystick.get_axis(RIGHT_STICK_Y) * -1

                    # Apply deadzone and scale to motor speed range
                    left_speed = 0 if abs(
                        left_y) < DEADZONE else left_y * MAX_SPEED
                    right_speed = 0 if abs(
                        right_y) < DEADZONE else right_y * MAX_SPEED

                    tank_drive(pwm_a, pwm_b, left_speed, right_speed)

                elif drive_mode == "arcade":
                    # Arcade drive mode - one stick for forward/backward, one for turning
                    # Using left stick for steering, right trigger for throttle
                    steering = joystick.get_axis(
                        LEFT_STICK_X)  # Positive is right

                    # For throttle, we use R2 trigger for forward, L2 for reverse
                    forward = joystick.get_axis(R2_TRIGGER)
                    reverse = joystick.get_axis(L2_TRIGGER)

                    # PS4 triggers rest at -1 and go to 1 when pressed, convert to 0-1
                    forward = (forward + 1) / 2
                    reverse = (reverse + 1) / 2

                    # Calculate throttle (-100 to 100)
                    throttle = (forward - reverse) * MAX_SPEED

                    # Apply deadzone to steering and scale
                    turn = 0 if abs(
                        steering) < DEADZONE else steering * MAX_SPEED * 0.5

                    arcade_drive(pwm_a, pwm_b, throttle, turn)

                # Display current values (debugging)
                # Uncomment for debugging
                # print(f"Left: {left_speed:.1f}  Right: {right_speed:.1f}", end="\r")

            # Small delay to reduce CPU usage
            time.sleep(0.05)

    except KeyboardInterrupt:
        print("\nProgram stopped by user")
    finally:
        # Clean up
        stop_display_thread.set()
        status_thread.join(timeout=1)

        # Stop motors and clean up GPIO
        if 'pwm_a' in locals() and 'pwm_b' in locals():
            pwm_a.stop()
            pwm_b.stop()
        GPIO.cleanup()
        pygame.quit()
        print("Cleanup complete")


if __name__ == "__main__":
    main()
