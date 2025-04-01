#!/usr/bin/env python3

#----Main program for UUV Raspberry Pi----

import os #Use python's OS functions
import sys #Use python's system functions
import time #Use python's time functions
from glob import glob #Access python's glob function (so we can use the wildcard * character when searching directories)
for subdir in next(os.walk('.'))[1]: sys.path.append('./%s' %subdir) #Add all subdirectories to the import path, to make importing easier

import comms #Serial communication module for talking to Arduino
import message_prefixes as prefix #Constants for message prefixes to make code more human-readable. Put into separate module to avoid "name capture pattern" issue, as described here: https://stackoverflow.com/questions/67525257/capture-makes-remaining-patterns-unreachable

#Flag to indicate if the program should keep running (used as condition for program's main loop). Set to false for normal program exit.
program_active = True
#Flag to indicate if the Arduino is ready to begin serial communication
serial_ready = False
#Flag to indicate that the connected device has been verified as the Arduino
verified = False

#Main function of the program
def main():
    
    setup()
    
    while program_active:
        loop()
    
    cleanup()
    
    exit(0)

#One-time setup code that needs to happen when the program starts should be here
def setup():
    
    open_serial()
    
    await_serial_ready()
    
    verify()

#Code that needs to happen continuously/repeatedly should be here
def loop():
    
    #TEMP CODE to close the program so it doesn't run forever
    global program_active
    program_active = False

#Anything that needs to happen at the end of the program should be here
def cleanup():
    close_serial()

#Wrapper to open serial connection with error checking and console logging
def open_serial():
    port_open = False
    for port in glob('/dev/ttyACM*'):
        try:
            comms.open_serial(port, 115200)
        except:
            print("Could not open port:", port, ", continuing...")
        else:
            print("Opening serial connection on port:", port)
            port_open = True
            break
    if not port_open:
        print("Could not find an open port! If the serial monitor is open in Arduino IDE, try closing it. Exiting...")
        exit(1)

#Function to wait for the Arduino to send a "serial ready" message before continuing
def await_serial_ready():
    print("\nWaiting for Arduino to report serial connection is ready...")
    while not serial_ready:
        message = comms.read_serial()
        if not message == 0:
            parse_message(message)
    print("Serial ready!")

#Function to send a verification request to the Arduino and wait for a valid response before continuing
def verify():
    print("\nVerifying that this is the Arduino...")
    comms.write_serial(bytearray.fromhex("10 00 00 00 00 00 00 00"))
    while not verified:
        message = comms.read_serial()
        if not message == 0:
            parse_message(message)
    print("ID verified!")

#Wrapper to close the serial connection
def close_serial():
    comms.close_serial()
    print("\nClosing serial connection.")

#Take an incoming message and decide what to do with it
def parse_message(message:bytearray):
    
    try:
        if not len(message) == 8:
            print("Incorrect message length!")
            return False
    except:
        print("Message is not the correct type!")
        return False
    
    message_prefix = message[0]
    message_address = message[1]
    
    match message_prefix:
        #--Debug category--
        case prefix.ECHO_CONTROL:
            pass
        
        case prefix.ECHO_SIMPLE:
            pass
        
        case prefix.ECHO_MODIFY:
            pass
        
        case prefix.ECHO_LOGS:
            pass
        
        case prefix.UNKNOWN_MESSAGE:
            reported_prefix = message[6]
            reported_address = message[7]
            print("Arduino reported unknown message type: Prefix", hex(reported_prefix), "Address", hex(reported_address))
        
        #--Initialization category--
        case prefix.ID_QUERY:
            if message_address == 0x01:
                global verified
                verified = True
        
        case prefix.DEVICE_QUERY:
            pass
        
        case prefix.ACTUATOR_ID:
            pass
        
        case prefix.SENSOR_ID:
            pass
        
        case prefix.SERIAL_READY:
            if message_address == 0x01:
                global serial_ready
                serial_ready = True
        
        #--Thruster category--
        case prefix.THRUSTER_TIMEOUT:
            pass
        
        case prefix.THRUSTER_THROTTLE:
            pass
        
        #--Sensor category--
        case prefix.SENSOR_UPDATE_INTERVAL:
            pass
        
        case prefix.SENSOR_START:
            pass
        
        case prefix.SENSOR_DATA:
            pass
        
        case prefix.SENSOR_STOP:
            pass
    
    return True

#Check to see if this file was run as a program, then execute main function
if __name__ == '__main__':
    main()