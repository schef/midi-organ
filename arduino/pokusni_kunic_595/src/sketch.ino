byte commandByte;
byte noteByte;
byte velocityByte;

byte noteOn = 144;

//light up led at pin 13 when receiving noteON message with note = 60

void setup(){
  Serial.begin(31250);
  pinMode(13,OUTPUT);
  digitalWrite(13,LOW);
}

void checkMIDI(){
  do{
    if (Serial.available()){
      commandByte = Serial.read();//read first byte
      noteByte = Serial.read();//read next byte
      velocityByte = Serial.read();//read final byte
      if (commandByte == noteOn){//if note on message
        //check if note == 60 and velocity > 0
        if (noteByte == 60 && velocityByte == 100){
          digitalWrite(13,HIGH);//turn on led
          Serial.write(144);
          Serial.write(59);
          Serial.write(100);
        }
      }
    }
  }
  while (Serial.available() > 2);//when at least three bytes available
}
    

void loop(){
  checkMIDI();
  delay(1);
  digitalWrite(13,LOW);//turn led off
}
