#include <Arduino.h>
#include <MIDI.h>
void bootSequence();
void setup();
void noteon(byte channel, byte note, byte velocity);
void noteoff(byte channel, byte note, byte velocity);
void serialPrint(int key, int i, int stanje);
void mojShift();
void loop();
#line 1 "src/sketch.ino"
//#include <MIDI.h>
//definiranje nozista

//164 pins
//int clearPin = 2; // enablepin
int data164Pin = 2;
int clock164Pin = 3;

//165 pins
//int inclearPin = 11; // enablepin
int data165Pin = 12;
int load165Pin = 10; // toggling this tells the 165 to read the value into its memory for reading

//595
int load595Pin = 9;
int data595Pin = 11;

//clock pin is shared between 165 and 595
int clockPin = 13;

byte commandByte;
byte noteByte;
byte velocityByte;

int potPin = 1;
int potVal = 0;
int potOldVal = 0;
int cc = 0;

int relay = 7;

int boot = 0;
//int sekvencaOne[24] = {	B00000001, //24
//			B00000010,
//			B00000100,
//			B00001000,
//			B00010000,
//			B00100000,
//			B01000000,
//			B10000000,
//			B00000000,
//			B00000000,
//			B00000000,
//			B00000000,
//			B00000000,
//			B00000000,
//			B00000000,
//			B00000000,
//			B00000000,
//			B10000000,
//			B01000000,
//			B00100000,
//			B00010000,
//			B00001000,
//			B00000100,
//			B00000010,
//};
//
//int sekvencaTwo[24] = {	B00000000, //24
//			B00000000,
//			B00000000,
//			B00000000,
//			B00000000,
//			B00000000,
//			B00000000,
//			B00000000,
//			B00000001,
//			B00000010,
//			B00000100,
//			B00001000,
//			B00010000,
//			B00001000,
//			B00000100,
//		B00000010,
//			B00000001,
//			B00000000,
//			B00000000,
//			B00000000,
//			B00000000,
//			B00000000,
//			B00000000,
//			B00000000,
//};
//inicializacija programa
void bootSequence(){
	do{
	//if(boot == 24)
	//  boot = 0;
  digitalWrite(load595Pin, LOW);
  //shiftOut(data595Pin, clockPin, MSBFIRST, sekvencaTwo[boot]);
  //shiftOut(data595Pin, clockPin, MSBFIRST, sekvencaOne[boot]);
  shiftOut(data595Pin, clockPin, MSBFIRST, boot);
  shiftOut(data595Pin, clockPin, MSBFIRST, boot);
  shiftOut(data595Pin, clockPin, MSBFIRST, boot);
  shiftOut(data595Pin, clockPin, MSBFIRST, boot);
  digitalWrite(load595Pin, HIGH);
  delay(100);
	if(MIDI.read()){
	//if (boot == 20){
    		//MIDI.setHandleNoteOn(noteon);
    		//MIDI.setHandleNoteOff(noteoff);
		break;
	}
boot++;
}
while(1);
  digitalWrite(load595Pin, LOW);
  shiftOut(data595Pin, clockPin, MSBFIRST, 0);
  shiftOut(data595Pin, clockPin, MSBFIRST, 0);
  shiftOut(data595Pin, clockPin, MSBFIRST, 0);
  shiftOut(data595Pin, clockPin, MSBFIRST, 0);
  digitalWrite(load595Pin, HIGH);
}

void setup() {

	//start serial
	//Serial.begin(9600);

	//164
	pinMode(data164Pin, OUTPUT);
	pinMode(clock164Pin, OUTPUT);  

	//165
	pinMode(data165Pin, INPUT);
	pinMode(load165Pin, OUTPUT);

	//595
	pinMode(load595Pin, OUTPUT);
	pinMode(data595Pin, OUTPUT);


	//shared pin
	pinMode(clockPin, OUTPUT);
  	pinMode(relay, OUTPUT);


  MIDI.begin(5);          // Launch MIDI and listen to channel 4
  //MIDI.turnThruOff();
bootSequence();
  //digitalWrite(relay, HIGH);
}

//definicija varijabla

//treba biti broj ulaza sa 165 u test primjeru 8 a u punoj funkciji 32
int readPin[32];

int buttonOne[64];
int oldButtonOne[64];
int buttonTwo[64];
int oldButtonTwo[64];
int buttonThree[64];
int oldButtonThree[64];
int buttonFour[64];
int oldButtonFour[64];

int ledStatus[64];
int oldLedStatus[64];

int midiLista[128];

int myByte = 0;
//byte noteOn = 144;
//byte noteOff = 128;

int ledLista[6];
int bitToByte[8] = {1, 2, 4, 8, 16, 32, 64, 128};

//definicija funkcija

void noteon(byte channel, byte note, byte velocity) {
  //if((channel == 5)&&(note == 127)){
  //  digitalWrite(relay, HIGH);
  //  }
  //else{
  midiLista[note] = 1;
  mojShift();
  //}
}

void noteoff(byte channel, byte note, byte velocity) {
  //if((channel == 5)&&(note == 127)){
  //  digitalWrite(relay, LOW);
  //  }
  //else{
  midiLista[note] = 0;
  mojShift();
  //}
}

void serialPrint(int key, int i, int stanje){ 
	Serial.print("k");
	Serial.print(key);
	Serial.print("-");
	Serial.print(i);
	Serial.print(":");
	Serial.print(stanje);
	Serial.println(""); 
}


void mojShift(){
  //bajt 1
  myByte = 0;
  for (int i = 0; i < 8; i++){
    myByte += (midiLista[(i+36)] * bitToByte[i]);
  }
  ledLista[0] = myByte;
//  //Serial.println(ledLista[0]);
//
  //bajt 2
  myByte = 0;
  for (int i = 0; i < 8; i++){
    myByte += (midiLista[(i+8+36)] * bitToByte[i]);
  }
  ledLista[1] = myByte;
  //Serial.println(ledLista[1]);
  //bajt 3
  myByte = 0;
  for (int i = 0; i < 8; i++){
    myByte += (midiLista[(i+16+36)] * bitToByte[i]);
  }
  ledLista[2] = myByte;
  //Serial.println(ledLista[2]);
  //bajt 4
  myByte = 0;
  for (int i = 0; i < 8; i++){
    myByte += (midiLista[(i+24+36)] * bitToByte[i]);
  }
  ledLista[3] = myByte;
//  //Serial.println(ledLista[3]);
//  //bajt 5
//  myByte = 0;
//  for (int i = 0; i < 8; i++){
//    myByte += (midiLista[(i+32+36)] * bitToByte[i]);
//  }
//  ledLista[4] = myByte;
//  //Serial.println(ledLista[4]);
//  //bajt 6
//  myByte = 0;
//  for (int i = 0; i < 8; i++){
//    myByte += (midiLista[(i+40+36)] * bitToByte[i]);
//  }
//  ledLista[5] = myByte;
  //Serial.println(ledLista[5]);

  //Serial.println("");
  //Serial.print(myByte);
  //Serial.println("");
  //Serial.println(ledLista[0]);
  //ledLista[0] = ;
  digitalWrite(load595Pin, LOW);
  //shiftOut(data595Pin, clockPin, MSBFIRST, ledLista[5]);
  //shiftOut(data595Pin, clockPin, MSBFIRST, ledLista[4]);
  shiftOut(data595Pin, clockPin, MSBFIRST, ledLista[3]);
  shiftOut(data595Pin, clockPin, MSBFIRST, ledLista[2]);
  shiftOut(data595Pin, clockPin, MSBFIRST, ledLista[1]);
  shiftOut(data595Pin, clockPin, MSBFIRST, ledLista[0]);
  digitalWrite(load595Pin, HIGH);
  //kraj ledica
  //Serial.println("--------");
  //delay(300);
}

int firstTime=0;

void loop() {
	//idemo 164 pin po pin od 1-8
	for(int j = 0; j < 8; ++j) //for 0 - 7 do
	{
		shiftOut(data164Pin, clock164Pin, MSBFIRST, 1 << j); // bit shift a logic high (1) value by i

		//shiftIn
		digitalWrite(load165Pin, 0); // read into register (tells the 165 to take a snapshot of its input pins)
		digitalWrite(load165Pin, 1); // done reading into register, ready for us to read    
		//Serial.print(j);
		//Serial.print(":");

		//za svaki pin od 164 citamo 32 pina sa 165(1-4)
		for(int i=0; i<32; i++){ // read each of the 165's 8 inputs (or its snapshot of it rather)
			// tell the 165 to send the inputs pin state
			digitalWrite(clockPin, 0);
			//tu je broj i-1
			readPin[(31-i)] = digitalRead(data165Pin); // read the state
			//Serial.print(readPin[(31-i)]);
			digitalWrite(clockPin, 1);
			//Serial.print (readPin[i]);
		}

		//---====ovde krece konvertiranje readPinova u klavijature jos nema sviranja----====//
		//klavijatura 1
		for (int i=0; i<8; i++){
			//this is my logic of Select and Data order -> C1=S1D1, C#1=S1D2
			//button[(j*8+i)] = readPin[i];
			//this if FATAR logic of Select and Data order C1=S1D1, C#1=S2D1
			buttonOne[(j+i*8)] = readPin[i];
		}
//		//klavijatura 2
		for (int i=8; i<16; i++){
			//this is my logic of Select and Data order -> C1=S1D1, C#1=S1D2
			//button[(j*8+i)] = readPin[i];
			//this if FATAR logic of Select and Data order C1=S1D1, C#1=S2D1
			//pazi na formulu
			buttonTwo[(j+(i-8)*8)] = readPin[i];
		}
		//klavijatura 3
		for (int i=16; i<24; i++){
			//this is my logic of Select and Data order -> C1=S1D1, C#1=S1D2
			//button[(j*8+i)] = readPin[i];
			//this if FATAR logic of Select and Data order C1=S1D1, C#1=S2D1
			buttonThree[(j*8+(i-16))] = readPin[i];
		}
		//klavijatura 4
		for (int i=24; i<32; i++){
			//this is my logic of Select and Data order -> C1=S1D1, C#1=S1D2
			//button[(j*8+i)] = readPin[i];
			//this if FATAR logic of Select and Data order C1=S1D1, C#1=S2D1
			buttonFour[(j+(i-24)*8)] = readPin[i];
		}


		//ovde se citaju liste klavijatura pa se svira
		for (int i = 0; i < 64; i++){
			//klavijatura 1
			if (buttonOne[i] == 1){
				if (buttonOne[i] != oldButtonOne[i]){
                                        MIDI.sendNoteOn(i+36,100,1);
					//serialPrint(1, i, 1);
					//    noteOn(0x90, note, 0x45);
					oldButtonOne[i] = buttonOne[i];
				}
			}
			else {
				if (buttonOne[i] != oldButtonOne[i]){
                                        MIDI.sendNoteOff(i+36,0,1);
					//serialPrint(1, i, 0);
					//    noteOn(0x90, note, 0x00);
					oldButtonOne[i] = buttonOne[i];
				}

			}
			//klavijatura 2
			if (buttonTwo[i] == 1){
				if (buttonTwo[i] != oldButtonTwo[i]){
					//serialPrint(2, i, 1);
                                        MIDI.sendNoteOn(i+36,100,2);
					//    noteOn(0x90, note, 0x45);
					oldButtonTwo[i] = buttonTwo[i];
				}
			}
			else {
				if (buttonTwo[i] != oldButtonTwo[i]){
                                        MIDI.sendNoteOff(i+36,0,2);
					//serialPrint(2, i, 0);
					//    noteOn(0x90, note, 0x00);
					oldButtonTwo[i] = buttonTwo[i];
				}

			}
			//klavijatura 3
			if (buttonThree[i] == 1){
				if (buttonThree[i] != oldButtonThree[i]){
                                        MIDI.sendNoteOn(i+36,100,3);
					//serialPrint(3, i, 1);
					//    noteOn(0x90, note, 0x45);
					oldButtonThree[i] = buttonThree[i];
				}
			}
			else {
				if (buttonThree[i] != oldButtonThree[i]){
                                        MIDI.sendNoteOff(i+36,0,3);
					//serialPrint(3, i, 0);
					//    noteOn(0x90, note, 0x00);
					oldButtonThree[i] = buttonThree[i];
				}

			}
			//klavijatura 4
			if (buttonFour[i] == 1){
				if (buttonFour[i] != oldButtonFour[i]){
                                        MIDI.sendNoteOn(i+36,100,4);
					//serialPrint(4, i, 1);
					//    noteOn(0x90, note, 0x45);
					oldButtonFour[i] = buttonFour[i];
				}
			}
			else {
				if (buttonFour[i] != oldButtonFour[i]){
                                        MIDI.sendNoteOff(i+36,0,4);
					//serialPrint(4, i, 0);
					//    noteOn(0x90, note, 0x00);
					oldButtonFour[i] = buttonFour[i];
				}

			}
		}


		//potenciometar za zelozinjei (swell)
		potVal = analogRead(potPin);
		if (potVal != potOldVal){
		if((potVal - potOldVal) > 5 || (potVal - potOldVal) < -5){
			cc = potVal/8;
			MIDI.sendControlChange(16,cc,1);
			potOldVal = potVal;
		}
		}

		//tu pocinje citanje midi informacija za ledice
		//u ovom slucaju pretpostavimo da koristimo buttonOne umjesto midiListe

		//tu se konvertira midi ulazni pa se smjesta u listu i odma shifta
		//pass


	}
  if (MIDI.read())                // If we have received a message
  {
    //digitalWrite(LED,HIGH);
    //MIDI.sendNoteOn(42,127,1);  // Send a Note (pitch 42, velo 127 on channel 1)
    //delay(1000);		        // Wait for a second
    //MIDI.sendNoteOff(42,0,1);   // Stop the note
    //digitalWrite(LED,LOW);
    MIDI.setHandleNoteOn(noteon);                             // call noteon when a note on message is received
    MIDI.setHandleNoteOff(noteoff);                            // call noteoff when a note off message is received
  }
	//kraj petlje 164
}
