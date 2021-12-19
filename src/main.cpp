#include <Arduino.h>
#include <VirtualBarometer.h>
#include <Wire.h>

const unsigned long SERIAL_BAUD_RATE = 115200;

VirtualBarometer barometer = VirtualBarometer();

float lowest_pressure;
bool apogee_detected = false;

void setup() {
    Serial.begin(SERIAL_BAUD_RATE);

    Wire.begin();

    Serial.println("Connecting to barometer");

    barometer.connect();

    barometer.allowTesting();

    lowest_pressure = barometer.getPressure();

}

void loop() {
    float pressure = barometer.getPressure();
    barometer.println(String("Simulated pressure: ") + pressure);

    if (pressure <= lowest_pressure) {
        lowest_pressure = pressure;
    } else if (!apogee_detected) {
        VirtualSensor::broadcastEvent("APOGEE");
        apogee_detected = true;
    }
}