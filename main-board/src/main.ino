#include <SoftwareSerial.h>
#include <Wire.h>
#include <AltSoftSerial.h>

SoftwareSerial vSerial(12, 13);
AltSoftSerial bluetooth;

void setup() {
    vSerial.begin(9600);
    bluetooth.begin(9600);
    Serial.begin(9600);
}

void loop() {
    delay(200);
    vSerial.println("main_board");
    
    unsigned int distance;

    if (Serial.available() > 5) {
        byte lowByte = Serial.read();
        byte highByte = Serial.read();
        distance = lowByte + 256* highByte;

        byte flaotNum[4];
        flaotNum[0] = Serial.read();
        flaotNum[1] = Serial.read();
        flaotNum[2] = Serial.read();
        flaotNum[3] = Serial.read();

        float temprature = *(float*)flaotNum;
        vSerial.println(distance, DEC);
        vSerial.println(temprature, DEC);
    }

    if (bluetooth.available() > 3) {
        vSerial.print("bluetooth ");
        char c[4];
        c[0] = bluetooth.read();
        c[1] = bluetooth.read();
        c[2] = bluetooth.read();
        c[3] = bluetooth.read();
        
        float utNum = *(float*)c;
        vSerial.println(utNum, DEC);
    }
}