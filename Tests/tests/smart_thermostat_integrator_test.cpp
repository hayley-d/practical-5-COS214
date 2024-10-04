#include "../src/SmartThermostatIntegrator.h"
#include <gtest/gtest.h>
#include <memory>

TEST(SmartThermostatIntegratorTest, GetTemperatureReturnsLegacyDeviceTemperature) {
    auto legacyDevice = std::make_shared<LegacyThermostat>();
    SmartThermostatIntegrator integrator(legacyDevice, 1);
    integrator.setTemperature(21.0);
    ASSERT_EQ(integrator.getTemperature(), 21.0);
}

TEST(SmartThermostatIntegratorTest, SetTemperatureIncreasesTemperatureWhenHigher) {
    auto legacyDevice = std::make_shared<LegacyThermostat>();
    SmartThermostatIntegrator integrator(legacyDevice, 1);
    integrator.setTemperature(25.0);
    ASSERT_EQ(legacyDevice->getTemperature(), 25.0);
}

TEST(SmartThermostatIntegratorTest, SetTemperatureDecreasesTemperatureWhenLower) {
    auto legacyDevice = std::make_shared<LegacyThermostat>();
    SmartThermostatIntegrator integrator(legacyDevice, 1);
    integrator.setTemperature(20.0);
    ASSERT_EQ(legacyDevice->getTemperature(), 20.0);
}

TEST(SmartThermostatIntegratorTest, ToggleSwitchesOnAndOff) {
    auto legacyDevice = std::make_shared<LegacyThermostat>();
    SmartThermostatIntegrator integrator(legacyDevice, 1);
    integrator.toggle();
    ASSERT_FALSE(legacyDevice->isOn());
    integrator.toggle();
    ASSERT_TRUE(legacyDevice->isOn());
}

TEST(SmartThermostatIntegratorTest, GetStatusReturnsCorrectMessage) {
    auto legacyDevice = std::make_shared<LegacyThermostat>();
    SmartThermostatIntegrator integrator(legacyDevice, 1);
    integrator.toggleOn();
    ASSERT_EQ(integrator.getStatus(), "Thermostat is on");
    integrator.toggleOff();
    ASSERT_EQ(integrator.getStatus(), "Thermostat is off");
}
