#include <Arduino.h>

class VirtualSensor {
    public:
        String name;
        String manufacturer;
        bool isConnected = false;
        void println(String s);
};