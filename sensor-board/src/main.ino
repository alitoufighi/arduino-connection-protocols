#define TempPin 0

#include <Arduino.h>
#include <Ultrasonic.h>
#include <LM35.h>
#include <SoftwareSerial.h>

Ultrasonic ultrasonic1(7, 6);	// An ultrasonic sensor HC-04
SoftwareSerial vSerial(8, 9);
float referenceVoltage;

void setup() {
  Serial.begin(9600);
  analogReference(INTERNAL);
  referenceVoltage = 1.1;
  pinMode(0, INPUT);
  vSerial.begin(9600);
}

void loop() {
    int distance = ultrasonic1.read(CM);
    int val = analogRead(TempPin);
    float temperature = (val * referenceVoltage * 100 / 1024.0); 
    vSerial.println(temperature);

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