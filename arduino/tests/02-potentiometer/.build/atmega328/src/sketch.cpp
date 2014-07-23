#include <Arduino.h>

void setup();
void loop();
#line 1 "src/sketch.ino"

/* Analog Read to LED
 * ------------------ 
 *
 * turns on and off a light emitting diode(LED) connected to digital  
 * pin 13. The amount of time the LED will be on and off depends on
 * the value obtained by analogRead(). In the easiest case we connect
 * a potentiometer to analog pin 2.
 *
 * Created 1 December 2005
 * copyleft 2005 DojoDave <http://www.0j0.org>
 * http://arduino.berlios.de
 *
 */

int potPin = 1;    // select the input pin for the potentiometer
int ledPin = 13;   // select the pin for the LED
int val = 0;       // variable to store the value coming from the sensor
int oldVal = 0;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);  // declare the ledPin as an OUTPUT
}

void loop() {
  val = analogRead(potPin);    // read the value from the sensor
  if(val != oldVal){
  
  if(((val-oldVal) > 5)||((val-oldVal)<(-5))){
  //digitalWrite(ledPin, HIGH);  // turn the ledPin on
  //delay(val);                  // stop the program for some time
  Serial.println(val);
  //digitalWrite(ledPin, LOW);   // turn the ledPin off
  //delay(val);                  // stop the program for some time
  //Serial.println(val);
  delay(100);
  oldVal = val;
  }
  }
}
