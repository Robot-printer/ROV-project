#include <Servo.h>

Servo ESC1;
Servo ESC2;
Servo ESC3;
Servo ESC4;
Servo ESC5;
Servo ESC6;

int potValue; 
int buttonValue;
int buttonOut;
bool oldButton;
bool currentButton;
void setup() {
  // put your setup code here, to run once:
  ESC1.attach(51, 1000, 2000);
  ESC2.attach(49, 1000, 2000);
  ESC3.attach(47, 1000, 2000);
  ESC4.attach(45, 1000, 2000);
  ESC5.attach(43, 1000, 2000);
  ESC6.attach(41, 1000, 2000);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  oldButton= true; //up is true, down is false, the switch starts up
  currentButton= false;
  buttonOut=0;
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  potValue = analogRead(A0);
  buttonValue = analogRead(A1);
  //Serial.println(buttonValue);
  //Convert button value to boolean----------
  if (buttonValue>=625){
      currentButton=false;
  }
  else{
    currentButton=true;
  };
  //Set the output value
  if ((currentButton==false) && (currentButton != oldButton)){
    //Serial.println("pressed");
    if (buttonOut<6){
      buttonOut=buttonOut+1;
    }
    else{
      buttonOut=0;
    }
  };
  digitalWrite(8, 0);
  digitalWrite(9, 0);
  digitalWrite(4, 0);
  digitalWrite(5, 0);
  digitalWrite(6, 0);
  digitalWrite(7, 0);
  digitalWrite(buttonOut+4, HIGH);
  oldButton=currentButton;
  //Serial.println(buttonOut);
  if (buttonOut==0){
    Serial.println(potValue);
    potValue = map(potValue, 0, 1023, 0,180);
    //Serial.println(potValue);
    ESC1.write(potValue);
    ESC2.write(0);
    ESC3.write(0);
    ESC4.write(0);
    ESC5.write(0);
    ESC6.write(0);
  };
  if (buttonOut==1){
    potValue = map(potValue, 0, 1023, 0,180);
    ESC1.write(0);
    ESC2.write(potValue);
    ESC3.write(0);
    ESC4.write(0);
    ESC5.write(0);
    ESC6.write(0);
  };
  if (buttonOut==2){
    potValue = map(potValue, 0, 1023, 0,180);
    ESC1.write(0);
    ESC2.write(0);
    ESC3.write(potValue);
    ESC4.write(0);
    ESC5.write(0);
    ESC6.write(0);
  };
  if (buttonOut==3){
    potValue = map(potValue, 0, 1023, 0,180);
    ESC1.write(0);
    ESC2.write(0);
    ESC3.write(0);
    ESC4.write(potValue);
    ESC5.write(0);
    ESC6.write(0);
  };
  if (buttonOut==4){
    potValue = map(potValue, 0, 1023, 0,180);
    ESC1.write(0);
    ESC2.write(0);
    ESC3.write(0);
    ESC4.write(0);
    ESC5.write(potValue);
    ESC6.write(0);
  };
  if (buttonOut==5){
    potValue = map(potValue, 0, 1023, 0,180);
    ESC1.write(0);
    ESC2.write(0);
    ESC3.write(0);
    ESC4.write(0);
    ESC5.write(0);
    ESC6.write(potValue);
  };
}
