#include <Arduino.h>
#include "VirtualSensor.h"

void VirtualSensor::println(String s) {
    Serial.println(String("[") + manufacturer + String(" ") + name + String("] ") + s);
};