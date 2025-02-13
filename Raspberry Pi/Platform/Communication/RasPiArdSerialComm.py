#Raspberry Pi side of the RasPi-Arduino communication system
import serial #The PySerial library

#Function to read the serial data coming in over USB port passed in comport at a baud rate of baudrate
def read_serial(comport, baudrate):
    ser = serial.Serial(comport, baudrate, timeout=0.1) #Create a Serial object called ser

    while True: #Do forever
        data = ser.readline().decode().strip() #Read the data coming over the serial connection and store it in a variable called data

        if data: #If data exists (ie. if it's not empty)
            print(data) #Print the contents of data to the terminal

if __name__ == '__main__': #Temp function to initialize the program for testing & debug
    read_serial('/dev/ttyACM0', 115200) #Read data from port /dev/ttyACM0 at a baud rate of 115200