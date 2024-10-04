#include "../src/SmartLight.h"
#include <gtest/gtest.h>

// Test fixture for SmartLight
class SmartLightTest : public ::testing::Test {
protected:
    SmartLight *light;

    void SetUp() override {
        light = new SmartLight(1, 50);
    }

    void TearDown() override {
        delete light;
    }
};

// Test constructor
TEST_F(SmartLightTest, ConstructorSetsCorrectValues) {
    EXPECT_EQ(light->getId(), 1);
    EXPECT_EQ(light->getIntensity(), 50);
}

// Test setIntensity
TEST_F(SmartLightTest, SetIntensityChangesValue) {
    light->setIntensity(80);
    EXPECT_EQ(light->getIntensity(), 80);
}

// Test toggle method
TEST_F(SmartLightTest, ToggleSwitchesIntensityBetweenOnAndOff) {
    light->toggle();
    EXPECT_EQ(light->getIntensity(), 0);

    light->toggle();
    EXPECT_EQ(light->getIntensity(), 100);
}

// Test toggleOn and toggleOff
TEST_F(SmartLightTest, ToggleOnOff) {
    light->toggleOff();
    EXPECT_EQ(light->getIntensity(), 0);

    light->toggleOn();
    EXPECT_EQ(light->getIntensity(), 100);
}

// Test getStatus
TEST_F(SmartLightTest, GetStatusReturnsCorrectString) {
    EXPECT_EQ(light->getStatus(), "Light is on");
    light->toggle();
    EXPECT_EQ(light->getStatus(), "Light is off");
}
