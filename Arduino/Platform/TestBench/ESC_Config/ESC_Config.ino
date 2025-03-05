//ESC Configuration script
//For configuration instructions, see https://www.rcelectricparts.com/defiant-esc-user-guide.html#04
#include <Servo.h>

#define pot_pin A0
#define ESC_pin 2

Servo ESC;

void setup() {
  pinMode(pot_pin,INPUT);
  ESC.attach(ESC_pin, 1000, 2000);
  Serial.begin(115200);
}

void loop() {
  int pot_val = analogRead(pot_pin);

  //Serial.println(pot_val);
  
  ESC.write(map(pot_val, 0, 1023, 0, 180));
}
