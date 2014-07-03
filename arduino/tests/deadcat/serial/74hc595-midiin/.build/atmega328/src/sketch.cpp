#include <Arduino.h>

void setup();
void checkMIDI();
void mojShift();
void loop();
#line 1 "src/sketch.ino"
//inicializacija programa

//595
int load595Pin = 9;
int data595Pin = 11;

//clock pin is shared between 165 and 595
int clockPin = 13;


void setup() {
	Serial.begin(31250);

	        //595
        pinMode(load595Pin, OUTPUT);
        pinMode(data595Pin, OUTPUT);


        //shared pin
        pinMode(clockPin, OUTPUT);

}

byte commandByte;
byte noteByte;
byte velocityByte;

int ledLista[6];
int midiLista[128];
int bitToByte[8] = {1, 2, 4, 8, 16, 32, 64, 128};

int myByte = 0;
byte noteOn = 144;
byte noteOff = 128;

void checkMIDI(){
	do{
		if (Serial.available()){
			commandByte = Serial.read();//read first byte
			noteByte = Serial.read();//read next byte
			velocityByte = Serial.read();//read final byte
			if (commandByte == noteOn){//if note on message
				//check if note == 60 and velocity > 0
				if (velocityByte > 0){
					//midiLista[noteByte] = 1;
				Serial.write(commandByte);
				Serial.write(noteByte);
				Serial.write(velocityByte);
				}
				//else {
				//	midiLista[noteByte] = 0;
				//}
			}
			else{//if note on message
				//midiLista[noteByte] = 0;
				Serial.write(commandByte);
				Serial.write(noteByte);
				Serial.write(velocityByte);
			}
		}
	}
	while (Serial.available() > 2);//when at least three bytes available
}

void mojShift(){
	//bajt 1
	myByte = 0;
	for (int i = 0; i < 8; i++){
		myByte += (midiLista[(i+35)] * bitToByte[i]);
	}
	ledLista[0] = myByte;
	//Serial.println(ledLista[0]);

	//bajt 2
	myByte = 0;
	for (int i = 0; i < 8; i++){
		myByte += (midiLista[(i+8+35)] * bitToByte[i]);
	}
	ledLista[1] = myByte;
	//Serial.println(ledLista[1]);
	//bajt 3
	myByte = 0;
	for (int i = 0; i < 8; i++){
		myByte += (midiLista[(i+16+35)] * bitToByte[i]);
	}
	ledLista[2] = myByte;
	//Serial.println(ledLista[2]);
	//bajt 4
	myByte = 0;
	for (int i = 0; i < 8; i++){
		myByte += (midiLista[(i+24+35)] * bitToByte[i]);
	}
	ledLista[3] = myByte;
	//Serial.println(ledLista[3]);
	//bajt 5
	myByte = 0;
	for (int i = 0; i < 8; i++){
		myByte += (midiLista[(i+32+35)] * bitToByte[i]);
	}
	ledLista[4] = myByte;
	//Serial.println(ledLista[4]);
	//bajt 6
	myByte = 0;
	for (int i = 0; i < 8; i++){
		myByte += (midiLista[(i+40+35)] * bitToByte[i]);
	}
	ledLista[5] = myByte;
	//Serial.println(ledLista[5]);

	//Serial.println("");
	//Serial.print(myByte);
	//Serial.println("");
	//Serial.println(ledLista[0]);
	//ledLista[0] = ;
	digitalWrite(load595Pin, LOW);
	shiftOut(data595Pin, clockPin, MSBFIRST, ledLista[5]);
	shiftOut(data595Pin, clockPin, MSBFIRST, ledLista[4]);
	shiftOut(data595Pin, clockPin, MSBFIRST, ledLista[3]);
	shiftOut(data595Pin, clockPin, MSBFIRST, ledLista[2]);
	shiftOut(data595Pin, clockPin, MSBFIRST, ledLista[1]);
	shiftOut(data595Pin, clockPin, MSBFIRST, ledLista[0]);
	digitalWrite(load595Pin, HIGH);
	//kraj ledica
	//Serial.println("--------");
	//delay(300);
}

void loop() {

	checkMIDI();
	//mojShift();
}
