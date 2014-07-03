#include <Arduino.h>

void setup();
void loop();
#line 1 "src/sketch.ino"

#define LED_PIN 13

void setup()
{
    Serial.begin(9600);
    pinMode(LED_PIN, OUTPUT);
}

void loop()
{
    digitalWrite(LED_PIN, HIGH);
    Serial.write("1");
    delay(100);
    digitalWrite(LED_PIN, LOW);
    Serial.write("0");
    delay(900);
}
