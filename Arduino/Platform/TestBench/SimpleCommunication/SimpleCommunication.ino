void setup()
{
  Serial.begin(115200);
  Serial.flush();
}

void loop()
{ 
  if (Serial.available() > 0)
  {
    byte message[8];
    Serial.readBytesUntil('\n', message, 8);
    Serial.write(message, 8);
  }
}
