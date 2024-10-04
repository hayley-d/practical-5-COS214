#include "../src/SmartThermostat.h"
#include <gtest/gtest.h>

// Test fixture for SmartThermostat
class SmartThermostatTest : public ::testing::Test {
protected:
    SmartThermostat* thermostat;

    void SetUp() override {
        thermostat = new SmartThermostat(1, 22.5);
    }

    void TearDown() override {
        delete thermostat;
    }
};

// Test constructor
TEST_F(SmartThermostatTest, ConstructorSetsCorrectValues) {
    EXPECT_EQ(thermostat->getId(), 1);
    EXPECT_EQ(thermostat->getTemperature(), 22.5);
    EXPECT_FALSE(thermostat->isOn());
}

// Test setTemperature
TEST_F(SmartThermostatTest, SetTemperatureChangesValue) {
    thermostat->setTemperature(25.0);
    EXPECT_EQ(thermostat->getTemperature(), 25.0);
}

// Test toggle method
TEST_F(SmartThermostatTest, ToggleSwitchesOnAndOff) {
    thermostat->toggle();
    EXPECT_TRUE(thermostat->isOn());

    thermostat->toggle();
    EXPECT_FALSE(thermostat->isOn());
}

// Test toggleOn and toggleOff
TEST_F(SmartThermostatTest, ToggleOnOffWorksCorrectly) {
    thermostat->toggleOn();
    EXPECT_TRUE(thermostat->isOn());

    thermostat->toggleOff();
    EXPECT_FALSE(thermostat->isOn());
}

// Test getStatus
TEST_F(SmartThermostatTest, GetStatusReturnsCorrectMessage) {
    thermostat->toggleOn();
    EXPECT_EQ(thermostat->getStatus(), "Thermostat is on");

    thermostat->toggleOff();
    EXPECT_EQ(thermostat->getStatus(), "Thermostat is off");
}
