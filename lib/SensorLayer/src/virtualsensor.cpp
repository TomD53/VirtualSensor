#include <Arduino.h>
#include "virtualsensor.h"

void VirtualSensor::println(String s) {
    Serial.println(String("[") + manufacturer + String(" ") + name + String("] ") + s);
};