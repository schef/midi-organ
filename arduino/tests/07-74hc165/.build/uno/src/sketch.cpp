#include <Arduino.h>
#include <SPI.h>
void setup ();
void loop ();
#line 1 "src/sketch.ino"
// Demo sketch to read from a 74HC165 input shift register
// Author: Nick Gammon
// Date:   23 March 2013

// Pin connections for Uno and similar:

// Chip pin 1 (/PL)  goes to LATCH/SS (D10)
// Chip pin 2 (CP)   goes to SCK   (D13)
// Chip pin 9 (Q7)   goes to MISO  (D12)


//#include <SPI.h>

const byte LATCH = 10;

void setup ()
{
	SPI.begin ();
	Serial.begin (9600);
	Serial.println ("Begin switch test.");
	pinMode (LATCH, OUTPUT);
	digitalWrite (LATCH, HIGH);
}  // end of setup

byte optionSwitch[4];
byte oldOptionSwitch[4]; // previous state

void loop ()
{
	digitalWrite (LATCH, LOW);    // pulse the parallel load latch
	digitalWrite (LATCH, HIGH);
	for (int chipNumber = 0; chipNumber < 4; chipNumber++){
		optionSwitch[chipNumber] = SPI.transfer (0);


		byte mask = 1;
		for (int i = 1; i <= 8; i++)
		{
			if ((optionSwitch[chipNumber] & mask) != (oldOptionSwitch[chipNumber] & mask))
			{
				Serial.print ("Switch");
				Serial.print (chipNumber);
				Serial.print (" ");
				Serial.print (i);
				Serial.print (" now ");
				Serial.println ((optionSwitch[chipNumber] & mask) ? "closed" : "open");
			}  // end of bit has changed
			mask <<= 1;  
		}  // end of for each bit

		oldOptionSwitch[chipNumber] = optionSwitch[chipNumber];
	}
		delay (10);   // debounce
	}  // end of loop

