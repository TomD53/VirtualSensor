#include <Arduino.h>

class VirtualSensor {
    public:
        String name;
        String manufacturer;
        void println(String s);
};