#include <SoftwareSerial.h>

SoftwareSerial vSerial(12, 13);

void setup() {
    vSerial.begin(9600);
}

void loop() {
    delay(200);
    vSerial.println("main_board");
}