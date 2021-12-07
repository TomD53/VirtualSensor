#include <Arduino.h>
#include "VirtualBarometer.h"
#include "SparkFunBME280.h"

VirtualBarometer::VirtualBarometer()
{
    manufacturer = "Sparkfun";
    name = "BME280";
}

bool VirtualBarometer::connect()
{
    println("Starting I2C communication.");
    sensor.setI2CAddress(0x76);
    if (sensor.beginI2C())
    { // Begin communication over I2C
        isConnected = true;
    }
    else
    {
        isConnected = false;
        println("The sensor did not respond. Please check wiring.");
        if (connectionAttempts < totalReconnectAttempts)
        {
            ++connectionAttempts;
            delay(1000);
            println(String("Attempting reconnect (") + connectionAttempts + String("/") + totalReconnectAttempts + String(")"));
            connect();
        }
    }
    return isConnected;
}

// Returns temperature in a range between -40 and 85°C
float VirtualBarometer::getTemperature()
{
    return sensor.readTempC();
};

// Returns pressure in Pascals between a range of 30000 and 110000
float VirtualBarometer::getPressure()
{
    return sensor.readFloatPressure();
};

// Returns relative humidity as a percentage between 0 and 100
float VirtualBarometer::getHumidity()
{
    return sensor.readFloatHumidity();
};