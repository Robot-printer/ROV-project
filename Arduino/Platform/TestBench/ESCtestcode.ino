
#include <Servo.h>

Servo ESC;
Servo servo;

int potValue; 
int buttonValue;
int buttonOut;
bool oldButton;
bool currentButton;
int oldPot;

void setup() {
  // put your setup code here, to run once:
  ESC.attach(A2, 1000, 2000);
  servo.attach(8);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  Serial.begin(600);
  oldButton= true; //up is true, down is false, the switch starts up
  currentButton= false;
  //Serial.println(oldButton);
  buttonOut=0;
  oldPot=0;
};

void loop() {
  // put your main code here, to run repeatedly:
  potValue = analogRead(A0);
  buttonValue = analogRead(A1);
  //Serial.println(buttonValue);
  //Convert button value to boolean----------
  if (buttonValue>=525){
      currentButton=false;
  }
  else{
    currentButton=true;
  };
  //Set the output value
  if ((currentButton==false) && (currentButton != oldButton)){
    if (buttonOut==1){
      buttonOut=0;
    }
    else{
      buttonOut=1;
    };
  }
  oldButton=currentButton;
  //Serial.println(buttonOut);
  digitalWrite(2, buttonOut);
  digitalWrite(3, 1-buttonOut);
  if (buttonOut==1){
    //Serial.println(potValue);
    potValue= map(potValue, 0, 1023, 65, 112);
    if (potValue!= oldPot){
      servo.write(potValue);
      delay(15);
    oldPot=potValue;
  }
  };
  if (buttonOut==0){

  potValue = map(potValue, 0, 1023, 0,180);
  Serial.println(potValue);
  ESC.write(potValue);
  };

};
