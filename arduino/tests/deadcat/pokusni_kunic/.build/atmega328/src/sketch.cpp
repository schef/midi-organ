#include <Arduino.h>

void setup();
void serialPrint(int key, int i, int stanje);
void loop();
#line 1 "src/sketch.ino"
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

//inicializacija programa

void setup() {

	//start serial
	Serial.begin(9600);

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

int ledLista[6];
int bitToByte[8] = {1, 2, 4, 8, 16, 32, 64, 128};

int myByte = 0;
//definicija funkcija

//void noteOn(int cmd, int pitch, int velocity) {
//	//    //Note on channel 1 (0x90), some note value (note), middle velocity (0x45):
//	//    noteOn(0x90, note, 0x45);
//	//    delay(100);
//	//    //Note on channel 1 (0x90), some note value (note), silent velocity (0x00):
//	//    noteOn(0x90, note, 0x00); 
//	Serial.write(cmd);
//	Serial.write(pitch);
//	Serial.write(velocity);
//}

void serialPrint(int key, int i, int stanje){ 
	Serial.print("k");
	Serial.print(key);
	Serial.print("-");
	Serial.print(i);
	Serial.print(":");
	Serial.print(stanje);
	Serial.println(""); 
}

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
			buttonThree[(j+(i-16)*8)] = readPin[i];
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
					serialPrint(1, i, 1);
					//    noteOn(0x90, note, 0x45);
					oldButtonOne[i] = buttonOne[i];
				}
			}
			else {
				if (buttonOne[i] != oldButtonOne[i]){
					serialPrint(1, i, 0);
					//    noteOn(0x90, note, 0x00);
					oldButtonOne[i] = buttonOne[i];
				}

			}
			//klavijatura 2
			if (buttonTwo[i] == 1){
				if (buttonTwo[i] != oldButtonTwo[i]){
					serialPrint(2, i, 1);
					//    noteOn(0x90, note, 0x45);
					oldButtonTwo[i] = buttonTwo[i];
				}
			}
			else {
				if (buttonTwo[i] != oldButtonTwo[i]){
					serialPrint(2, i, 0);
					//    noteOn(0x90, note, 0x00);
					oldButtonTwo[i] = buttonTwo[i];
				}

			}
			//klavijatura 3
			if (buttonThree[i] == 1){
				if (buttonThree[i] != oldButtonThree[i]){
					serialPrint(3, i, 1);
					//    noteOn(0x90, note, 0x45);
					oldButtonThree[i] = buttonThree[i];
				}
			}
			else {
				if (buttonThree[i] != oldButtonThree[i]){
					serialPrint(3, i, 0);
					//    noteOn(0x90, note, 0x00);
					oldButtonThree[i] = buttonThree[i];
				}

			}
			//klavijatura 4
			if (buttonFour[i] == 1){
				if (buttonFour[i] != oldButtonFour[i]){
					serialPrint(4, i, 1);
					//    noteOn(0x90, note, 0x45);
					oldButtonFour[i] = buttonFour[i];
				}
			}
			else {
				if (buttonFour[i] != oldButtonFour[i]){
					serialPrint(4, i, 0);
					//    noteOn(0x90, note, 0x00);
					oldButtonFour[i] = buttonFour[i];
				}

			}
		}


		//tu pocinje citanje midi informacija za ledice
		//u ovom slucaju pretpostavimo da koristimo buttonOne umjesto midiListe

		//tu se konvertira midi ulazni pa se smjesta u listu i odma shifta
		//pass

		//595
		//for (int i = 0; i < 32; i++){
			//ledLista[0] += readPin[i] * 2^i;
			//Serial.print("1");
		//	Serial.print(readPin[(31-i)]);
		//}
		//Serial.println("");
		//bajt 1
		myByte = 0;
		for (int i = 0; i < 8; i++){
			myByte += (buttonOne[(i)] * bitToByte[i]);
		}
		ledLista[0] = myByte;
		//Serial.println(ledLista[0]);

		//bajt 2
		myByte = 0;
		for (int i = 0; i < 8; i++){
			myByte += (buttonOne[(i+8)] * bitToByte[i]);
		}
		ledLista[1] = myByte;
		//Serial.println(ledLista[1]);
		//bajt 3
		myByte = 0;
		for (int i = 0; i < 8; i++){
			myByte += (buttonOne[(i+16)] * bitToByte[i]);
		}
		ledLista[2] = myByte;
		//Serial.println(ledLista[2]);
		//bajt 4
		myByte = 0;
		for (int i = 0; i < 8; i++){
			myByte += (buttonOne[(i+24)] * bitToByte[i]);
		}
		ledLista[3] = myByte;
		//Serial.println(ledLista[3]);
		//bajt 5
		myByte = 0;
		for (int i = 0; i < 8; i++){
			myByte += (buttonOne[(i+32)] * bitToByte[i]);
		}
		ledLista[4] = myByte;
		//Serial.println(ledLista[4]);
		//bajt 6
		myByte = 0;
		for (int i = 0; i < 8; i++){
			myByte += (buttonOne[(i+40)] * bitToByte[i]);
		}
		ledLista[5] = myByte;
		//Serial.println(ledLista[5]);

		//Serial.println("");
		//Serial.print(myByte);
		//Serial.println("");
		//Serial.println(ledLista[0]);
		//ledLista[0] = ;
			digitalWrite(load595Pin, LOW);
			shiftOut(data595Pin, clockPin, MSBFIRST, 0);
			shiftOut(data595Pin, clockPin, MSBFIRST, 0);
			shiftOut(data595Pin, clockPin, MSBFIRST, 0);
			shiftOut(data595Pin, clockPin, MSBFIRST, 0);
			shiftOut(data595Pin, clockPin, MSBFIRST, 0);
			shiftOut(data595Pin, clockPin, MSBFIRST, 0);
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
	//kraj petlje 164
}
