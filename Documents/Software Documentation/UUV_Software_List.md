# [Software for UUV Project]{.underline}

### Operator Laptop (Python)

-   Operator interface

    -   Read input from controller, send controller input to Raspberry
        Pi

    -   Command terminal to send commands directly to UUV

    -   Display video feed

    -   Display sensor data onscreen

### Raspberry Pi (Python)

-   Main program

    -   Call functions from sub-programs as needed

-   Operator communication interface

    -   Connect to operator interface program

    -   Receive controller input from operator computer

    -   Receive commands from operator computer

    -   Send sensor data to operator computer

-   Vector calculations

    -   Turn controller input into motor speed values

-   Video stream

    -   Read video from camera

    -   Send video to operator computer

-   Arduino serial communication interface

    -   Send commands (motor speeds, servo angles, etc) to Arduino

    -   Receive sensor data from Arduino

### Arduino (C++)

-   Main program

    -   Call functions from sub-programs as needed

-   Motor control program

    -   
