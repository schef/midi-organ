#include <Arduino.h>

void setup();
void loop();
#line 1 "src/sketch.ino"

#define LED_PIN 7

void setup()
{
    pinMode(LED_PIN, OUTPUT);
}

void loop()
{
    digitalWrite(LED_PIN, HIGH);
    delay(1000);
    digitalWrite(LED_PIN, LOW);
    delay(1000);
}
