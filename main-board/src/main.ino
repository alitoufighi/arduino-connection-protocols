#include <SoftwareSerial.h>
#include <AltSoftSerial.h>
#include <LiquidCrystal.h>
#include <Wire.h>

LiquidCrystal lcd(13, 12, 11, 10, 9, 7);

AltSoftSerial bluetooth;

unsigned int distance = 0;
float temperature = 0;
float ut_num = 0;

void setup() {
    lcd.begin(20, 4);
    bluetooth.begin(9600);
    Serial.begin(9600);
    distance = 0;
    temperature = 0;
    ut_num = 0;
}

void loop() {
    delay(200);

    if (Serial.available() > 5) {
        byte lowByte = Serial.read();
        byte highByte = Serial.read();
        distance = lowByte + 256 * highByte;

        byte flaotNum[4];
        flaotNum[0] = Serial.read();
        flaotNum[1] = Serial.read();
        flaotNum[2] = Serial.read();
        flaotNum[3] = Serial.read();
        temperature = *(float*)flaotNum;
    }

    if (bluetooth.available() > 3) {
        char c[4];
        c[0] = bluetooth.read();
        c[1] = bluetooth.read();
        c[2] = bluetooth.read();
        c[3] = bluetooth.read();
        ut_num = *(float*)c;
    }

    lcd.setCursor(0, 0);
    lcd.print("UT: ");
    lcd.print(ut_num);
    lcd.setCursor(0, 1);
    lcd.print("Temp: ");
    lcd.print(temperature);
    lcd.setCursor(-4, 2);
    lcd.print("Dist: ");
    if (distance != 0)
        distance--;
    lcd.print(distance);
}