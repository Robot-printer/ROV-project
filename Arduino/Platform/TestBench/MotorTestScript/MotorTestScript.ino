//--------Script for testing one servo at a time--------

#include <Servo.h>              //Servo control library

const int ESC_MAX = 2400;       //Max value to send to ESC
const int ESC_MIN = 544;        //Min value to send to ESC

Servo test_ESC;                 //Create variable of type "Servo" to represent the ESC

int input_control;              //Current value coming from input potentiometer

//Run once on board startup
void setup() {
    pinMode(50, INPUT);
    set_ESC_pin(test_ESC, 52, ESC_MIN, ESC_MAX); //Default ESC pin set to pin 52
    Serial.begin(9600);
}

//Run continuously after setup completion
void loop() {
    input_control = analogRead(A15);
    
    int target_value = map(input_control, 0, 1023, ESC_MIN, ESC_MAX);
    
    test_ESC.write(target_value);
    Serial.write(digitalRead(50));
}

//Wrapper for servo.attach() to avoid overwriting existing attachment
void set_ESC_pin(Servo ESC, int pin, int min, int max){
    
    if (ESC.attached()){ //Detach ESC from a pin if it's already attached to one
        ESC.detach();
    }

    ESC.attach(pin, min, max); //Attach the ESC to the new pin
}