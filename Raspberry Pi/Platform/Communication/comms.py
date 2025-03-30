#!/usr/bin/env python3

#Raspberry Pi side of the RasPi-Arduino communication system
import serial #The PySerial library
import time #Python's built-in time library

#These variables are only used for testing
comport = '/dev/ttyACM0'
baudrate = 115200

#Global variable to represent the serial channel
ser = serial.Serial()

#Function to open the serial communication channel to the Arduino
def open_serial(comport, baudrate):
    global ser #Access global ser variable
    ser = serial.Serial(comport, baudrate, timeout=1.0) #Create a Serial object called ser
    time.sleep(3) #Wait a little while for the Arduino to be ready
    ser.reset_input_buffer() #Clear anything that's currently in the input buffer

#Function to read the serial data coming in over USB port
def read_serial():
    global ser #Access global ser variable
    if ser.in_waiting >= 8: #If there's 8 or more bytes of data waiting in the input buffer
        data = ser.read_until(size=8) #Read the data coming over the serial connection and store it in a variable called data
        return data
    else:
        return 0

#Function to write (send) a message to the Arduino
def write_serial(message):
    global ser #Access global ser variable
    ser.write(message) #Write the message to the serial output buffer

if __name__ == '__main__': #Temp function to initialize the program for testing & debug
    open_serial(comport, baudrate)
    message = bytearray.fromhex('00AA00AA 00FF00FF') 
    count = 0
    success_count = 0
    start = time.time()
    dur = 60 * (1/3)
    write_dur = 0
    read_dur = 0
    print("Running serial connection test for", dur, "seconds at", baudrate, "baud...")
    while time.time() < (start + dur):
        time_zero = time.time()
        write_serial(message)
        write_time = time.time()
        data = read_serial()
        read_time = time.time()
        count += 1
        write_dur += write_time - time_zero
        read_dur += read_time - write_time
        if data == message:
            success_count += 1
            #print(data.hex(' ', 1))
        elif data == 0:
            print("NoMsg")
        else:
            print(data.hex(' ', 1))
    print("-----Test results-----")
    print("Total messages:", count)
    print("Total successes:", success_count)
    
    print("Average messages per second:", count/dur)
    print("Average successes per second:", success_count/dur)
    
    print("Failed messages:", count - success_count)
    print("Success rate:", success_count/count*100, "%")
    
    print("Average write duration:", write_dur/count*1000, "milliseconds")
    print("Average read duration:", read_dur/count*1000, "milliseconds")
    print("Reading takes", read_dur/write_dur, "times as long as writing")
    print("Anything we missed:...")
    capture_wait = 10
    capture_start = time.time()
    while time.time() < capture_start + capture_wait:
        if ser.in_waiting > 0:
            data = ser.read_until(size=8)
            if len(data) == 8:
                print(data.hex(' ', 1))
            else:
                print(data)

