#include <Arduino.h>

class VirtualSensor {
    public:
        // Unique name for this sensor
        String name;

        String manufacturer = "UNKNOWN";
        bool isConnected = false;
        bool testMode;

        void enableTestMode();
        void disableTestMode();
        void println(String s);
    protected:
        String prefix = "@VS:";
        float getFloatSimulated(String columnName);
        String getSimulatedValue(String columnName);
};