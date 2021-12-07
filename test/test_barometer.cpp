#include <virtualbarometer.h>
#include <unity.h>
#include <Arduino.h>

VirtualBarometer barometer;

void test_barometer_connected(void)
{
    TEST_ASSERT_TRUE(barometer.isConnected);
}

void test_barometer_temperature_range(void)
{
    float temperature = barometer.getTemperature();
    bool condition = temperature > -40 && temperature < 85;
    TEST_ASSERT_TRUE(condition);
}

void test_barometer_pressure_range(void)
{
    float pressure = barometer.getPressure();
    bool condition = pressure > 30000 && pressure < 110000;
    TEST_ASSERT_TRUE(condition);
}

void test_barometer_humidity_range(void)
{
    float humidity = barometer.getHumidity();
    bool condition = humidity > 0 && humidity < 100;
    TEST_ASSERT_TRUE(condition);
}

void setup()
{
    // Wait for 2 seconds for Arduino
    delay(2000);
    Serial.begin(9600);
    Wire.begin();

    UNITY_BEGIN(); // start unit testing

    barometer.connect();

    RUN_TEST(test_barometer_connected);
    RUN_TEST(test_barometer_temperature_range);
    RUN_TEST(test_barometer_pressure_range);
    RUN_TEST(test_barometer_humidity_range);

    UNITY_END(); // stop unit testing
}

void loop()
{
    ;
}