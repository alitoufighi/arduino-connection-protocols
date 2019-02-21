#include <SoftwareSerial.h>
#include <Wire.h>
#include <AltSoftSerial.h>

SoftwareSerial vSerial(12, 13);
// AltSoftSerial bluetooth;

void setup() {
    vSerial.begin(9600);
    // bluetooth.begin(9600);
    Serial.begin(9600);
}

void loop() {
    delay(200);
    vSerial.println("main_board");
    
    int i = 0;
    char s[3];
    unsigned int distance;

    if (Serial.available() > 1) {
        // vSerial.println("sensor data");
        // char s = Serial.read();
        // vSerial.print(s);
        byte lowByte = Serial.read();
        byte highByte = Serial.read();
        distance = lowByte + 256* highByte;
        vSerial.println(distance, DEC);
    }

    // vSerial.print("sensor ");
    // vSerial.println(distance, DEC);
    
    // i = 0;
    // while(bluetooth.available() > 0) {
    //     vSerial.print("bluetooth ");
    //     char c = bluetooth.read();
    //     vSerial.println(c, DEC);
    // }
}