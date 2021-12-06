#include <Arduino.h>
#include "SparkFunBME280.h"
#include "VirtualSensor.h"


class VirtualBarometer : public VirtualSensor {
    public:
        float getTemperature();
        float getPressure();
        float getHumidity();
        VirtualBarometer();
    private:
        BME280 sensor;
};