#include <Arduino.h>
#include <VirtualBarometer.h>
#include <Wire.h>

void setup() {
    Serial.begin(9600);

    Wire.begin();

    VirtualBarometer barometer;

    barometer.connect();

    barometer.println(String("Pressure: ") + barometer.getPressure());
    barometer.println(String("Temperature: ") + barometer.getTemperature());
    barometer.println(String("Humidity: ") + barometer.getHumidity());
}

void loop() {
    ;
}