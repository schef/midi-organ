#include <Arduino.h>

void setup();
void loop();
#line 1 "src/sketch.ino"
#define data 2
#define clock 3

// use binary notation to discribe our number layouts
byte zero  = B00000000;
byte one   = B00000001;
byte two   = B00000010;
byte three = B00000100;
byte four  = B00001000;
byte five  = B00010000;
byte six   = B00100000;
byte seven = B01000000;
byte eight = B10000000;

void setup()
{
  pinMode(clock, OUTPUT); // make the clock pin an output
  pinMode(data , OUTPUT); // make the data pin an output3
}

void loop()
{
    shiftOut(data, clock, LSBFIRST, zero);
    delay(500);
    shiftOut(data, clock, LSBFIRST, one);
    delay(500);
    shiftOut(data, clock, LSBFIRST, two);
    delay(500);
    shiftOut(data, clock, LSBFIRST, three);
    delay(500);
    shiftOut(data, clock, LSBFIRST, four);
    delay(500);
    shiftOut(data, clock, LSBFIRST, five);
    delay(500);
    shiftOut(data, clock, LSBFIRST, six);
    delay(500);
    shiftOut(data, clock, LSBFIRST, seven);
    delay(500);
    shiftOut(data, clock, LSBFIRST, eight);
    delay(500);
}
