#include <SoftwareSerial.h>
#include <Wire.h>

SoftwareSerial vSerial(12, 13);

void setup() {
    vSerial.begin(9600);
    Wire.begin();
}

void loop() {
    delay(200);

    Wire.requestFrom(110, 4);
    int i = 0;
    char X[4];
    while (Wire.available()) {
        X[3 - i] = Wire.read();
        i++;
    }
    
    char Y[4];
    Wire.requestFrom(110, 4);
    i = 0;
    while (Wire.available()) {
        Y[3 - i] = Wire.read();
        i++;
    }

    float x = *reinterpret_cast<float*>(X);
    float y = *reinterpret_cast<float*>(Y);

    vSerial.println("XY");
    vSerial.println(x);
    vSerial.println(y);
    vSerial.println("ut_board");
}