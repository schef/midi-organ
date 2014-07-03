#include <Arduino.h>

void setup();
#line 1 "src/sketch.ino"
//http://debiaonoldcomputers.blogspot.it/2012/05/fotoaccoppiatore-4n35.html
int ledPin = 12;                 

void setup()
{
  pinMode(ledPin, OUTPUT);      

void loop()
{
  digitalWrite(ledPin, HIGH);   
  delay(3000);                  
  digitalWrite(ledPin, LOW);    
  delay(3000);                  
}

