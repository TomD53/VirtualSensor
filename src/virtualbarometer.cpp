#include <Arduino.h>
#include "virtualbarometer.h"
#include "SparkFunBME280.h"

VirtualBarometer::VirtualBarometer()
{
    name = "BME280";
    manufacturer = "Sparkfun";
    println("Starting I2C communication.");
    sensor.setI2CAddress(0x76);
    if (sensor.beginI2C() == false) // Begin communication over I2C
    {
        println("The sensor did not respond. Please check wiring.");
    }
}

float VirtualBarometer::getTemperature(){
    return sensor.readTempC();
};

float VirtualBarometer::getPressure(){
    return sensor.readFloatPressure();
};

float VirtualBarometer::getHumidity(){
    return sensor.readFloatHumidity();
};