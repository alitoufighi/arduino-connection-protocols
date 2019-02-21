#include <SoftwareSerial.h>
#include <Wire.h>

SoftwareSerial vSerial(12, 13);

float distance;

char readByte(int device, int address) {
    Wire.beginTransmission(device);
    Wire.write(address);
    Wire.endTransmission();
    Wire.requestFrom(device, 1);
    return Wire.read();
}

void writeByte(int device, int address, int data) {
    Wire.beginTransmission(device);
    Wire.write(address);
    Wire.write(data);
    Wire.endTransmission();
}

void setup() {
    vSerial.begin(9600);
    Serial.begin(9600);
    writeByte(110, 0, 1);
    distance = 0;
}

void loop() {
    delay(100);
    
    int i = 0;
    char X[4];

    int startAddress = 10;
    while (i < 4) {
        X[i] = readByte(110, startAddress + i);
        i++;
    }
    float x = *reinterpret_cast<float*>(X);

    i = 0;
    char Y[4];
    startAddress = 40;

    while (i < 4) {
        Y[i] = readByte(110, startAddress + i);
        i++;
    }
    float y = *reinterpret_cast<float*>(Y);

    distance += x * x + y * y;

    vSerial.println("XY");
    vSerial.println(x);
    vSerial.println(y);
    vSerial.println(distance);
    vSerial.println("ut_board");

    char* distSerial = reinterpret_cast<char*>(&distance);
    Serial.write(distSerial, 4);
}