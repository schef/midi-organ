int inByte; // Stores incoming command

void setup() {
	Serial.begin(9600);
	pinMode(13, OUTPUT); // Led pin
	Serial.println("Ready"); // Ready to receive commands
}

void loop() {
	if(Serial.available() > 0) { // A byte is ready to receive

		inByte = Serial.read();
		if(inByte == 'a') { // byte is 'a'
			digitalWrite(13, HIGH);
			Serial.println("LED - On");
		}
		else { // byte isn't 'a'
			digitalWrite(13, LOW);
			Serial.println("LED - off");
		}
	}
}
