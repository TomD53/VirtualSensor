#include <Arduino.h>
#include "virtualbarometer.h"
#include <Wire.h>

void setup() {
    Serial.begin(9600);

    Wire.begin();

    VirtualBarometer barometer = VirtualBarometer();

    barometer.println(String("Pressure: ") + barometer.getPressure());
    barometer.println(String("Temperature: ") + barometer.getTemperature());
    barometer.println(String("Humidity: ") + barometer.getHumidity());
}

void loop() {
    ;
}