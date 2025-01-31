//--------This script is the Arduino side of the Arduino<->Raspberry Pi serial communication

//Structure to represent the 5-hex-digit (20 bit) message in the Arduino's memory
struct message {
  byte type;
  word destination;
  word content;
};


void setup(){
  message myMsg;

  myMsg.type = 0x5;
  myMsg.destination = 0x35;
  myMsg.content = 0x52;
  Serial.begin(9600);
  sendMessage(myMsg);
}

void loop(){

}
//Send a message across the serial connection to the Pi
void sendMessage(message msg){
  if (Serial){
    Serial.write(msg.type);
    Serial.write(msg.destination);
    Serial.write(msg.content);
  }
}
