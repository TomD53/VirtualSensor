#include <Arduino.h>
#include <VirtualBarometer.h>
#include <Wire.h>

const unsigned long SERIAL_BAUD_RATE = 115200;

VirtualBarometer barometer = VirtualBarometer();

void setup() {
    Serial.begin(SERIAL_BAUD_RATE);

    Wire.begin();

    Serial.println("Connecting to barometer");

    barometer.connect();

    barometer.allowTesting();

}

void loop() {
    barometer.println(String("Simulated temperature: ") + barometer.getTemperature());
}