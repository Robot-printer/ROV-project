#!/usr/bin/env python3

#----Main program for UUV Raspberry Pi----

import os #Use python's OS functions
import sys #Use python's system functions
import time #Use python's time functions
from glob import glob #Access python's glob function (so we can use the wildcard * character when searching directories)
for subdir in next(os.walk('.'))[1]: sys.path.append('./%s' %subdir) #Add all subdirectories to the import path, to make importing easier

import comms #Serial communication module for talking to Arduino

program_active = True

#Main function of the program
def main():
    
    setup()
    
    while program_active:
        loop()
    
    cleanup()
    
    exit()

#One-time setup code that needs to happen when the program starts should be here
def setup():
    
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
        exit()
    
    serial_ready = False
    while not serial_ready:
        message = comms.read_serial()
        if message == bytearray.fromhex("10000000 00000000"):
            serial_ready = True
    print("Serial ready!")
    
    verified = False
    comms.write_serial(bytearray.fromhex("10 01 00 00 00 00 00 00"))
    while not verified:
        message = comms.read_serial()
        if message == bytearray.fromhex("10 02 00 00 00 00 00 00"):
            verified = True
    print("ID verified!")

#Code that needs to happen continuously/repeatedly should be here
def loop():
    global program_active
    program_active = False

#Anything that needs to happen at the end of the program should be here
def cleanup():
    comms.close_serial()

if __name__ == '__main__':
    main()