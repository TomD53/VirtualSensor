#include <Arduino.h>

const String prefix = "@VS:";
const String sep = ":";

class VirtualSensor {
    public:
        // Unique name for this sensor
        String name;

        String manufacturer = "UNKNOWN";
        bool isConnected = false;
        
        void println(String s);
        void allowTesting();

        static void broadcastEvent(String eventName);
        static void setup();
        bool isTesting();
    protected:
        float getFloatSimulated(String columnName);
        String getSimulatedValue(String columnName);
        VirtualSensor() {} // protected constructor so VirtualSensor cannot be used on its own
    private:
        String getResponse(String stringToSend);
        bool testMode;
        void enableTestMode();
        void disableTestMode();
};