#define TempPin A0

#include <Arduino.h>
#include <Ultrasonic.h>

Ultrasonic ultrasonic1(7, 6);	// An ultrasonic sensor HC-04

void setup() {
  Serial.begin(9600);
  pinMode(A0, INPUT);
}

void loop() {
    int distance = ultrasonic1.read(CM);
    int val = analogRead(TempPin);
    float mv = (val/1024.0)*5000; 
    float temperature = mv/10;
    byte buf[2];
    byte* floatBuf;
    buf[0] = distance & 255;
    buf[1] = (distance >> 8) & 255;
    floatBuf = (byte*)(&temperature);

    Serial.write(buf[0]);
    Serial.write(buf[1]);
    Serial.write(floatBuf[0]);
    Serial.write(floatBuf[1]);
    Serial.write(floatBuf[2]);
    Serial.write(floatBuf[3]);
    
    delay(500);
}