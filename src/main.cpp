/*
Developed by Ghana Nazala, Athina Maria, Achmad Kripton, Muhammad Fadli
*/

#include <Arduino.h>

void setup() {
    pinMode(13, OUTPUT);
}

void loop() {
    digitalWrite(13, HIGH);
    delay(1000);
    digitalWrite(13, LOW);
    delay(500);
}
