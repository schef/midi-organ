
//164 pins
//int clearPin = 2; // enablepin
int dataPin = 2;
int clockPin = 3;

//165 pins
//int inclearPin = 11; // enablepin
int indataPin = 12;
int inclockPin = 13;
int inloadPin = 10; // toggling this tells the 165 to read the value into its memory for reading

void setup() {

	//start serial
	Serial.begin(9600);

	//164
	pinMode(dataPin, OUTPUT);
	pinMode(clockPin, OUTPUT);  

	//165
	pinMode(indataPin, INPUT);
	pinMode(inclockPin, OUTPUT);  
	pinMode(inloadPin, OUTPUT);
}

int readPin[8];
int button[64];
int oldButton[64];

void loop() {
	for(int j = 0; j < 8; ++j) //for 0 - 7 do
	{
		shiftOut(dataPin, clockPin, MSBFIRST, 1 << j); // bit shift a logic high (1) value by i

		//shiftIn
		digitalWrite(inloadPin, 0); // read into register (tells the 165 to take a snapshot of its input pins)
		digitalWrite(inloadPin, 1); // done reading into register, ready for us to read    
		//Serial.print(j);
		//Serial.print(":");
		for(int i=0; i<8; i++){ // read each of the 165's 8 inputs (or its snapshot of it rather)
			// tell the 165 to send the inputs pin state
			digitalWrite(inclockPin, 0);
			readPin[(7-i)] = digitalRead(indataPin); // read the state
			digitalWrite(inclockPin, 1);
			//Serial.print (readPin[i]);
		}

		for (int i=0; i<8; i++){
			//this is my logic of Select and Data order -> C1=S1D1, C#1=S1D2
			//button[(j*8+i)] = readPin[i];
			//this if FATAR logic of Select and Data order C1=S1D1, C#1=S2D1
			button[(j*8+i)] = readPin[i];
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

		//delay(2000);
	}

}
