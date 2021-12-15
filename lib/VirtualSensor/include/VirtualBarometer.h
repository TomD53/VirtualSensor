#include <Arduino.h>
#include "SparkFunBME280.h"
#include "VirtualSensor.h"


class VirtualBarometer : public VirtualSensor {
    public:
        float getTemperature();
        float getPressure();
        float getHumidity();
        bool connect();
        VirtualBarometer();
    private:
        BME280 sensor;
        int connectionAttempts = 0;
        int totalReconnectAttempts = 3;
};