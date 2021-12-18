#include <Arduino.h>

class VirtualSensor {
    public:
        // Unique name for this sensor
        String name;

        String manufacturer = "UNKNOWN";
        bool isConnected = false;
        
        void println(String s);
        void allowTesting();
    protected:
        float getFloatSimulated(String columnName);
        String getSimulatedValue(String columnName);
        bool testMode;
    private:
        String prefix = "@VS:";
        String sep = ":";
        String getResponse(String stringToSend);
        
        void enableTestMode();
        void disableTestMode();
};