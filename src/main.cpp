#include <Arduino.h>
#include <VirtualBarometer.h>
#include <Wire.h>

const unsigned long SERIAL_BAUD_RATE = 2000000;

VirtualBarometer barometer = VirtualBarometer();

float lowest_pressure;
bool apogee_detected;
uint32_t counter = 0;
int counter2 = 0;

void(* resetFunc) (void) = 0;

void VirtualSensor::setup() {
    barometer.allowTesting();

    lowest_pressure = barometer.getPressure();

    apogee_detected = false;

    counter = 0;
}

void setup() {
    Serial.begin(SERIAL_BAUD_RATE);

    Wire.begin();

    Serial.println("Connecting to barometer");

    barometer.connect();
}

// TODO: have better way of handling commands sent from PC to arduino
// TODO: have better way of handling commands sent from PC to arduino
// TODO: have better way of handling commands sent from PC to arduino
// TODO: have better way of handling commands sent from PC to arduino
// TODO: have better way of handling commands sent from PC to arduino

void loop() {
    #ifdef VIRTUALSENSOR
    Serial.println("IS VIRTUALSENSOR");
    if (!Serial) {
        while (!Serial) { ; }
        VirtualSensor::setup();
        counter2++;
    }
    #endif
    float pressure = barometer.getPressure();
    // barometer.println(String("Simulated pressure: ") + pressure);

    if (pressure <= lowest_pressure) {
        lowest_pressure = pressure;
    } else if (!apogee_detected) {
        VirtualSensor::broadcastEvent("APOGEE");
        apogee_detected = true;
    }
    Serial.println("Overall counter: " + String(counter));
    Serial.println("Times restarted: " + String(counter2));
    counter++;
}