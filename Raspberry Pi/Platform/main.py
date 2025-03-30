#!/usr/bin/env python3

#----Main program for UUV Raspberry Pi----

import os #Use python's OS functions
import sys #Use python's system functions
import time #Use python's time functions
for subdir in next(os.walk('.'))[1]: sys.path.append('./%s' %subdir) #Add all subdirectories to the import path, to make importing easier

import comms #Serial communication module for talking to Arduino

if __name__ == '__main__':
    comms.open_serial('/dev/ttyACM0', 115200)
    comms.write_serial(bytearray.fromhex("00AA00AA 00FF00FF"))
    time.sleep(1)
    print(comms.read_serial().hex(' ',1))
    