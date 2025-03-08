#!/usr/bin/env python3

#Raspberry Pi side of the RasPi-Arduino communication system
import serial #The PySerial library
import time

comport = '/dev/ttyACM0'
baudrate = 57600

ser = serial.Serial()

def open_serial(comport, baudrate):
    global ser
    ser = serial.Serial(comport, baudrate, timeout=1.0) #Create a Serial object called ser
    time.sleep(3)
    ser.reset_input_buffer()

#Function to read the serial data coming in over USB port passed in comport at a baud rate of baudrate
def read_serial():
    global ser
    data = ser.read_until(size=8) #Read the data coming over the serial connection and store it in a variable called data
    return data

def write_serial(message):
    global ser
    ser.write(message)

if __name__ == '__main__': #Temp function to initialize the program for testing & debug
    open_serial(comport, baudrate)
    message = bytearray.fromhex('00 00 AA AA AA AA AA AA')
    count = 0
    start = time.time()
    dur = 10
    while time.time() < (start + dur):
        #time.sleep(64/baudrate)
        write_serial(message)
        #while ser.in_waiting <= 0:
            #time.sleep(64/baudrate)
        data = read_serial()
        count += 1
        #if data == message:
            #print(data.hex(' ', 1))
        #else:
            #print(data)
    print(count/dur)

