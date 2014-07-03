//**************************************************************//
//  Name    : shiftOutCode, Hello World                                
//  Author  : Carlyn Maw,Tom Igoe, David A. Mellis 
//  Date    : 25 Oct, 2006    
//  Modified: 23 Mar 2010                                 
//  Version : 2.0                                             
//  Notes   : Code for using a 74HC595 Shift Register           //
//          : to count from 0 to 255                           
// http://arduino.cc/en/tutorial/ShiftOut
//****************************************************************

//Pin connected to ST_CP of 74HC595
int latchPin = 9; //SS
//Pin connected to SH_CP of 74HC595
int clockPin = 13; //SCK
////Pin connected to DS of 74HC595
int dataPin = 11; //MOSI

int oneByOne[8] = {1, 2, 4, 8, 16, 32, 64, 128};

void setup() {
	//set pins to output so you can control the shift register
	pinMode(latchPin, OUTPUT);
	pinMode(clockPin, OUTPUT);
	pinMode(dataPin, OUTPUT);
}

void loop() {
	// count from 0 to 255 and display the number 
	// on the LEDs
	for (int j = 0; j < 6; j++){
		for (int i = 0; i<6; i++){
			if (j == i){
				digitalWrite(latchPin, LOW);
				shiftOut(dataPin, clockPin, MSBFIRST, 255);  
				digitalWrite(latchPin, HIGH);
			}
			else {
				digitalWrite(latchPin, LOW);
				shiftOut(dataPin, clockPin, MSBFIRST, 0);  
				digitalWrite(latchPin, HIGH);
			}
			//  for (int i = 0; i < 8; i++) {
			//    // take the latchPin low so 
			//    // the LEDs don't change while you're sending in bits:
			//    digitalWrite(latchPin, LOW);
			//    // shift out the bits:
			//    shiftOut(dataPin, clockPin, MSBFIRST, oneByOne[i]);  
			//
			//    //take the latch pin high so the LEDs will light up:
			//    digitalWrite(latchPin, HIGH);
			//    // pause before next value:
			//    delay(100);
			//  }
			delay(100);
		}
	}
}
