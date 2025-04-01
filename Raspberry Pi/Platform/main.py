#!/usr/bin/env python3

#----Main program for UUV Raspberry Pi----

import os #Use python's OS functions
import sys #Use python's system functions
import time #Use python's time functions
from glob import glob #Access python's glob function (so we can use the wildcard * character when searching directories)
for subdir in next(os.walk('.'))[1]: sys.path.append('./%s' %subdir) #Add all subdirectories to the import path, to make importing easier

import comms #Serial communication module for talking to Arduino

#Flag to indicate if the program should keep running (used as condition for program's main loop). Set to false for normal program exit.
program_active = True

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
    
    await_verification()

#Code that needs to happen continuously/repeatedly should be here
def loop():
    
    #TEMP CODE to close the program so it doesn't run forever
    global program_active
    program_active = False

#Anything that needs to happen at the end of the program should be here
def cleanup():
    close_serial()

#Wrapper to open serial connection with error checking and console output
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
    serial_ready = False
    print("\nWaiting for Arduino to report serial connection is ready...")
    while not serial_ready:
        message = comms.read_serial()
        if message == bytearray.fromhex("10 00 00 00 00 00 00 00"):
            serial_ready = True
    print("Serial ready!")

#Function to send a verification request to the Arduino and wait for a valid response before continuing
def await_verification():
    verified = False
    print("\nVerifying that this is the Arduino...")
    comms.write_serial(bytearray.fromhex("10 01 00 00 00 00 00 00"))
    while not verified:
        message = comms.read_serial()
        if message == bytearray.fromhex("10 02 00 00 00 00 00 00"):
            verified = True
    print("ID verified!")

#Wrapper to close the serial connection
def close_serial():
    comms.close_serial()
    print("\nClosing serial connection.")

#Check to see if this file was run as a program, then execute main function
if __name__ == '__main__':
    main()