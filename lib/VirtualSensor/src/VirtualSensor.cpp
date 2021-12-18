#include <Arduino.h>
#include "VirtualSensor.h"

void VirtualSensor::println(String s) {
    Serial.println(String("[") + manufacturer + String(" ") + name + String("] ") + s);
};

void VirtualSensor::enableTestMode() {
    println("Enabling test mode");
    testMode = true;
}

void VirtualSensor::disableTestMode() {
    println("Disabling test mode");
    testMode = false;
}

String VirtualSensor::getResponse(String stringToSend) {
    Serial.println(stringToSend);
    Serial.flush(); // wait for data to be sent

    String response = Serial.readStringUntil('\n');
    return response;
}

float VirtualSensor::getFloatSimulated(String columnName) {
    String value = getSimulatedValue(columnName);
    return value.toFloat();
}

String VirtualSensor::getSimulatedValue(String columnName) {
    String response = getResponse(prefix + "REQ" + sep + name + sep + columnName);
    return response;
}

void VirtualSensor::allowTesting() {
    String response = getResponse(prefix + "ISTEST" + sep + name);
    if (response == "true") {
        enableTestMode();
    } else {
        disableTestMode();
    }
}