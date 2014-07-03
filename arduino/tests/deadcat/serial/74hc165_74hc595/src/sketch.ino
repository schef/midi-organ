//**************************************************************//
//  Name    : shiftOutCode, Hello World                         //
//  Author  : Carlyn Maw,Tom Igoe                               //
//  Date    : 25 Oct, 2006                                      //
//  Version : 1.0                                               //
//  Notes   : Code for using a 74HC595 Shift Register           //
//          : to count from 0 to 255                            //
//****************************************************************

//Pin connected to ST_CP of 74HC595
int latchPin = 9;
//Pin connected to SH_CP of 74HC595
int clockPin = 13;
////Pin connected to DS of 74HC595
int dataPin = 11;

const int inlatchPin = 10;
// Pin connected to QH of 74HC165
const int indataPin = 12;

void setup() {
  Serial.begin(9600);
  //set pins to output because they are addressed in the main loop
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);

  // prepare the serial port

  // set pins as output
  pinMode(inlatchPin, OUTPUT);
  // set pins as input
  pinMode(indataPin, INPUT);
}

int status;
int oldStatus;

int oneByOne[8] = {1, 2, 4, 8, 16, 32, 64, 128};

void loop() {
    // Set the latchPin LOW ...
  digitalWrite (inlatchPin, LOW);
  delayMicroseconds(10);
  digitalWrite (inlatchPin, HIGH);
  byte inByte = shiftIn165(indataPin,clockPin,MSBFIRST);
  //Serial.print(inByte);
  
   //delay(500);
//for (int numberToDisplay = 0; numberToDisplay < 8; numberToDisplay++) {
    status = inByte;
    if (status != oldStatus){
    digitalWrite(latchPin, LOW);
    //shiftOut(dataPin, clockPin, MSBFIRST, oneByOne[numberToDisplay]);  
    Serial.println(inByte);
    shiftOut(dataPin, clockPin, MSBFIRST, 0);  
    shiftOut(dataPin, clockPin, MSBFIRST, inByte);  
    //return the latch pin high to signal chip that it
    //no longer needs to listen for information
    digitalWrite(latchPin, HIGH);
    //Serial.println(oneByOne[numberToDisplay]);
    oldStatus = status;
    //delay(2000);
    //}
}



}

uint8_t shiftIn165(uint8_t dataPin, uint8_t clockPin, uint8_t bitOrder) {
uint8_t value = 0;
uint8_t i;

for (i = 0; i < 8; ++i) {
digitalWrite(clockPin, LOW);
if (bitOrder == LSBFIRST)
value |= digitalRead(dataPin) << i;
else
value |= digitalRead(dataPin) << (7 - i);
digitalWrite(clockPin, HIGH);
}
return value;
}
