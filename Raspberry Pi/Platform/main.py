#!/usr/bin/env python3

#----Main program for UUV Raspberry Pi----

import os #Use python's OS functions
import sys #Use python's system functions
import time #Use python's time functions
from glob import glob #Access python's glob function
for subdir in next(os.walk('.'))[1]: sys.path.append('./%s' %subdir) #Add all subdirectories to the import path, to make importing easier

import comms #Serial communication module for talking to Arduino

if __name__ == '__main__':
    for port in glob('/dev/ttyACM*'):
        try:
            comms.open_serial(port, 115200)
        except:
            print("Could not open port:", port, ", continuing...")
        else:
            print("Opening serial connection on port:", port)
            break
    
    
    serial_ready = False
    while not serial_ready:
        message = comms.read_serial()
        if message == bytearray.fromhex("10000000 00000000"):
            serial_ready = True
    print("Serial ready!")
    comms.close_serial()
    