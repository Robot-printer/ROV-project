#include <Servo.h>

Servo motorESCFL, motorESCFR, motorESCBL, motorESCBR;// Create a Servo object to control the ESC

int potMiddle = 1024 / 2;//the range of the potentiomiter and devided by two to find the middle

void setup() {//only runs once
  motorESCFL.attach(3); //8-11 tell the program how to accses each motor
  motorESCFR.attach(5);
  motorESCBL.attach(6);
  motorESCBR.attach(9);
  Serial.begin(9600);
}

void loop() {//repeats forever
  int power = analogRead(A1);//the overal power of the rov
  int leftRightBias = analogRead(A2) - potRange;//left-Right tilt control
  int forwardBackwardBias = analogRead(A3) - potRange;//forward-Backward tilt controll

  motorESCFL.write(map(power - leftRightBias - ForwardBackwardBias,-1024,2048,1000,2000));//writes the translated value to the motor front left
  motorESCFR.write(map(power + leftRightBias - ForwardBackwardBias,-1024,2048,1000,2000));//writes the translated value to the motor front right
  motorESCBL.write(map(power - leftRightBias + ForwardBackwardBias,-1024,2048,1000,2000));//writes the translated value to the motor back left
  motorESCBR.write(map(power + leftRightBias + ForwardBackwardBias,-1024,2048,1000,2000));//writes the translated value to the motor back right

  //Code from here to the end displays the values and is not nesseary

  // Serial.println(power); 
  // Serial.println(leftRightBias);
  // Serial.println(ForwardBackwardBias);

  // Serial.print("motorESCFL: ");
  // Serial.println(map(power - leftRightBias - ForwardBackwardBias,-1024,2048,1000,2000));

  // Serial.print("motorESCFR: ");
  // Serial.println(map(power + leftRightBias - ForwardBackwardBias,-1024,2048,1000,2000));

  // Serial.print("motorESCBL: ");
  // Serial.println(map(power - leftRightBias + ForwardBackwardBias,-1024,2048,1000,2000));

  // Serial.print("motorESCBR: ");
  // Serial.println(map(power + leftRightBias + ForwardBackwardBias,-1024,2048,1000,2000));

}
