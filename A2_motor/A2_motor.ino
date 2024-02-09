#include <Servo.h>

Servo motorESC; // Create a Servo object to control the ESC

void setup() {
  motorESC.attach(9); // Connect the ESC signal wire to pin 9
  Serial.begin(9600);
}

void loop() {
long sensorValue = analogRead(A1);
  
sensorValue = map(sensorValue,0,1000,1000,2000);

  Serial.println(sensorValue);

  motorESC.write(sensorValue);

}
