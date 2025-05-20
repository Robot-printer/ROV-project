//--------Script for testing one servo at a time--------

#include <Servo.h>              //Servo control library
#include "6AxisSensor.h"        //IMU

const int ESC_MAX = 2400;       //Max value to send to ESC
const int ESC_MIN = 544;        //Min value to send to ESC

Servo test_ESC;                 //Create variable of type "Servo" to represent the ESC
Servo test_ESC_2;
Servo test_ESC_3;
Servo test_ESC_4;

int input_control;              //Current value coming from input potentiometer
int input_control_2;
int input_control_3;
int input_control_4;

//Run once on board startup
void setup() {
    initialize_dso32();
    pinMode(A14, INPUT);
    pinMode(A15, INPUT);
    pinMode(50, INPUT);
    pinMode(A8, OUTPUT);
    set_ESC_pin(test_ESC, 52, ESC_MIN, ESC_MAX); //Default ESC pin set to pin 52
    set_ESC_pin(test_ESC_2, 50, ESC_MIN, ESC_MAX); //Default ESC pin set to pin 50
    set_ESC_pin(test_ESC_3, 48, ESC_MIN, ESC_MAX); //Default ESC pin set to pin 48
    set_ESC_pin(test_ESC_4, 46, ESC_MIN, ESC_MAX); //Default ESC pin set to pin 46
    Serial.begin(9600);
}

//Run continuously after setup completion
void loop() {
    sensor_test_loop();
    //Serial.println(analogRead(A11));
    analogWrite(A8, analogRead(A11));
    input_control = analogRead(A15);
    input_control_2 = analogRead(A14);
    input_control_3 = analogRead(A13);
    input_control_4 = analogRead(A12);
    
    int target_value = map(input_control, 0, 1023, ESC_MIN, ESC_MAX);
    int target_value_2 = map(input_control_2, 0, 1023, ESC_MIN, ESC_MAX);
    int target_value_3 = map(input_control_3, 0, 1023, ESC_MIN, ESC_MAX);
    int target_value_4 = map(input_control_4, 0, 1023, ESC_MIN, ESC_MAX);
    
    test_ESC.write(target_value);
    test_ESC_2.write(target_value_2);
    test_ESC_3.write(target_value_3);
    test_ESC_4.write(target_value_4);
    //Serial.println(analogRead(A15));
}

//Wrapper for servo.attach() to avoid overwriting existing attachment
void set_ESC_pin(Servo ESC, int pin, int min, int max){
    
    if (ESC.attached()){ //Detach ESC from a pin if it's already attached to one
        ESC.detach();
    }

    ESC.attach(pin, min, max); //Attach the ESC to the new pin
}