#include <Arduino.h>

class VirtualSensor {
    public:
        String name;
        String manufacturer;
    public:
        void println(String s);
};