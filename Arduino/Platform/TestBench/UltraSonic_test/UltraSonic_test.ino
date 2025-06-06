
#define COM 0x55

unsigned char buffer[4] = {0};
int distance = 0;
uint8_t checkSum;

void setup() {
  Serial.begin(115200);
  Serial1.begin(115200);

}

void loop() {
  
  Serial1.write(COM);
  delay(100);
  if (Serial1.available() > 0)
  {
    delay(4);
    if (Serial1.read() == 0xff)
    {
      buffer[0] = 0xff;
      for (int i = 1; i < 4; i++)
      {
        buffer[i] = Serial1.read();
      }
      checkSum = buffer[0] + buffer[1] + buffer[2];

      if (buffer[3] == checkSum)
      {
        distance = (buffer[1] << 8) + buffer[2];
        Serial.print("Distance: ");
        Serial.print(distance);
        Serial.println("mm");

      }
    }
  }

}
