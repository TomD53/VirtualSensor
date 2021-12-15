#include <Arduino.h>
#include <VirtualBarometer.h>
#include <Wire.h>

const unsigned long SERIAL_BAUD_RATE = 115200;

VirtualBarometer barometer = VirtualBarometer();

void setup() {
    Serial.begin(SERIAL_BAUD_RATE);

    Wire.begin();

    barometer.connect();

    barometer.println(String("Pressure: ") + barometer.getPressure());
    barometer.println(String("Temperature: ") + barometer.getTemperature());
    barometer.println(String("Humidity: ") + barometer.getHumidity());

    barometer.enableTestMode();

    barometer.println(String("Simulated temperature: ") + barometer.getTemperature());
    barometer.println(String("Simulated pressure: ") + barometer.getPressure());
    barometer.println(String("Simulated humidity: ") + barometer.getHumidity());
}

void loop() {
    ;
}