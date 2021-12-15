#include <Arduino.h>
#include "VirtualSensor.h"

void VirtualSensor::println(String s) {
    Serial.println(String("[") + manufacturer + String(" ") + name + String("] ") + s);
};

void VirtualSensor::enableTestMode() {
    testMode = true;
}

void VirtualSensor::disableTestMode() {
    testMode = false;
}

float VirtualSensor::getFloatSimulated(String columnName) {
    String value = getSimulatedValue(columnName);
    return value.toFloat();
}

String VirtualSensor::getSimulatedValue(String columnName) {
    Serial.println(prefix + name + String(":") + columnName);
    Serial.flush(); // wait for data to be sent
    while (!Serial.available()) { // wait for response
        ;
    }

    String response = Serial.readStringUntil('\n');
    return response;
}