// #include <SoftwareSerial.h>
// #include <Wire.h>
// #include <LM35.h>
// #include <Ultrasonic.h>

// SoftwareSerial vSerial(12, 13);
// // SoftwareSerial mainSerial(5, 6);
// Ultrasonic ultrasonic(10, 9);
// // LM35 temp(A0);

// void setup() {
//     vSerial.begin(9600);
//     // mainSerial.begin(9600);
// }

// void loop() {
//     delay(200);
//     int distance = ultrasonic.read(CM);
//     // float temperature = temp.cel();
//     // mainSerial.print("S");
//     vSerial.println(distance);
//     // vSerial.println(temperature);
//     vSerial.println("sensor_board");
// }

#include <Arduino.h>
#include <Ultrasonic.h>

Ultrasonic ultrasonic1(7, 6);	// An ultrasonic sensor HC-04
// Ultrasonic ultrasonic2(10);		// An ultrasonic sensor PING)))
// Ultrasonic ultrasonic3(8);		// An Seeed Studio ultrasonic sensor


void setup() {
  Serial.begin(9600);
}

void loop() {
    int distance = ultrasonic1.read(CM);
    byte buf[2];
    buf[0] = distance & 255;   // >>>> >>>> 0001 0110
    buf[1] = (distance >> 8) & 255; 
    // Serial.print("salam");
    Serial.write(distance % 256);
    Serial.write(distance / 256);

    delay(500);
}