
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

int readPin[8];
int button[64];
int oldButton[64];

int ledStatus;
int oldLedStatus;

void loop() {
	for(int j = 0; j < 8; ++j) //for 0 - 7 do
	{
		shiftOut(data164Pin, clock164Pin, MSBFIRST, 1 << j); // bit shift a logic high (1) value by i

		//shiftIn
		digitalWrite(load165Pin, 0); // read into register (tells the 165 to take a snapshot of its input pins)
		digitalWrite(load165Pin, 1); // done reading into register, ready for us to read    
		//Serial.print(j);
		//Serial.print(":");
		for(int i=0; i<8; i++){ // read each of the 165's 8 inputs (or its snapshot of it rather)
			// tell the 165 to send the inputs pin state
			digitalWrite(clockPin, 0);
			readPin[(7-i)] = digitalRead(data165Pin); // read the state
			digitalWrite(clockPin, 1);
			//Serial.print (readPin[i]);
		}

		for (int i=0; i<8; i++){
			//this is my logic of Select and Data order -> C1=S1D1, C#1=S1D2
			//button[(j*8+i)] = readPin[i];
			//this if FATAR logic of Select and Data order C1=S1D1, C#1=S2D1
			button[(j+i*8)] = readPin[i];
		}

		for (int i = 0; i < 64; i++){
			if (button[i] == 1){
				if (button[i] != oldButton[i]){
					Serial.print(i);
					Serial.print(":1");
					Serial.println(""); 
					oldButton[i] = button[i];
				}
			}
			else {
				if (button[i] != oldButton[i]){
					Serial.print(i);
					Serial.print(":0");
					Serial.println(""); 
					oldButton[i] = button[i];
				}

			}
		}

		ledStatus = 0;
		for(int i=8; i>=0; i--){
				//light up on select pins
				//ledStatus |= (button[i] << i);
				//light up on data pins
				ledStatus |= (readPin[i] << i);
		}

		//595
		//ledStatus = 1;
		if (ledStatus != oldLedStatus){
			digitalWrite(load595Pin, LOW);
			//shiftOut(dataPin, clockPin, MSBFIRST, oneByOne[numberToDisplay]);  
			//Serial.println(inByte);
			shiftOut(data595Pin, clockPin, MSBFIRST, 0);
			shiftOut(data595Pin, clockPin, MSBFIRST, ledStatus);
			//return the latch pin high to signal chip that it
			//no longer needs to listen for information
			digitalWrite(load595Pin, HIGH);
			//Serial.println(oneByOne[numberToDisplay]);
			oldLedStatus = ledStatus;

			//delay(2000);
		}

	}
}
