#include <SoftwareSerial.h>
#include <Wire.h>
#include <AltSoftSerial.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(13, 12, 11, 10, 9, 7);

AltSoftSerial bluetooth;

unsigned int distance = 0;
float temprature = 0;
float utNum = 0;

void setup() {
    lcd.begin(20, 4);
    bluetooth.begin(9600);
    Serial.begin(9600);
    distance = 0;
    temprature = 0;
    utNum = 0;
}

void loop() {
    delay(200);

    if (Serial.available() > 5) {
        byte lowByte = Serial.read();
        byte highByte = Serial.read();
        distance = lowByte + 256* highByte;
        // lcd.setCursor(0, 1);
        // lcd.print("dist: ");
        // lcd.print(distance);

        byte flaotNum[4];
        flaotNum[0] = Serial.read();
        flaotNum[1] = Serial.read();
        flaotNum[2] = Serial.read();
        flaotNum[3] = Serial.read();

        temprature = *(float*)flaotNum;
        // lcd.setCursor(0, 2);
        // lcd.print("temp: ");
        // lcd.print(temprature);
    }

    if (bluetooth.available() > 3) {
        char c[4];
        c[0] = bluetooth.read();
        c[1] = bluetooth.read();
        c[2] = bluetooth.read();
        c[3] = bluetooth.read();
        utNum = *(float*)c;
        // lcd.setCursor(0, 3);
        // lcd.print("UT: ");
        // lcd.print(utNum);
    }

    lcd.setCursor(0, 0);
    lcd.print("UT: ");
    lcd.print(utNum);
    lcd.setCursor(0, 1);
    lcd.print("temp: ");
    lcd.print(temprature);
    lcd.setCursor(-4, 2);
    lcd.print("dist: ");
    if (distance != 0)
        distance--;
    lcd.print(distance);
    // lcd.setCursor(0, 2);
}