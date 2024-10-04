#include "../src/SmartRoom.h"
#include "../src/SmartLight.h"
#include "../src/SmartThermostat.h"
#include "../src/SmartDoor.h"
#include <gtest/gtest.h>
#include <memory>

// Test fixture for SmartRoom
class SmartRoomTest : public ::testing::Test {
protected:
    SmartRoom *room;

    void SetUp() override {
        room = new SmartRoom();
    }

    void TearDown() override {
        delete room;
    }
};

// Test adding a SmartLight
TEST_F(SmartRoomTest, AddSmartLight) {
    auto light = std::make_shared<SmartLight>(1, 50);
    room->addSmartDevice(light);

    // Validate that the light has been added
    EXPECT_EQ(room->lights.size(), 1);
}

// Test adding a SmartThermostat
TEST_F(SmartRoomTest, AddSmartThermostat) {
    auto thermostat = std::make_shared<SmartThermostat>(1, 22.0);
    room->addSmartDevice(thermostat);

    // Validate that the thermostat has been added
    EXPECT_EQ(room->thermostats.size(), 1);
}

// Test adding a SmartDoor
TEST_F(SmartRoomTest, AddSmartDoor) {
    auto door = std::make_shared<SmartDoor>(1);
    room->addSmartDevice(door);

    // Validate that the door has been added
    EXPECT_EQ(room->doors.size(), 1);
}

// Test removing a SmartLight
TEST_F(SmartRoomTest, RemoveSmartLight) {
    auto light = std::make_shared<SmartLight>(1, 50);
    room->addSmartDevice(light);

    // Remove the light
    EXPECT_TRUE(room->removeSmartDevice(1, DeviceType::Light));

    // Validate that the light has been removed
    EXPECT_EQ(room->lights.size(), 0);
}

// Test setting room light intensity
TEST_F(SmartRoomTest, SetRoomLightIntensity) {
    auto light1 = std::make_shared<SmartLight>(1, 50);
    auto light2 = std::make_shared<SmartLight>(2, 75);
    room->addSmartDevice(light1);
    room->addSmartDevice(light2);

    room->setRoomLightIntensity(100);

    EXPECT_EQ(light1->getIntensity(), 100);
    EXPECT_EQ(light2->getIntensity(), 100);
}

// Test turning on lights
TEST_F(SmartRoomTest, TurnOnLights) {
    auto light1 = std::make_shared<SmartLight>(1, 0);
    auto light2 = std::make_shared<SmartLight>(2, 0);
    room->addSmartDevice(light1);
    room->addSmartDevice(light2);

    room->turnOnLights();

    EXPECT_EQ(light1->getIntensity(), 100);
    EXPECT_EQ(light2->getIntensity(), 100);
}

// Test turning off lights
TEST_F(SmartRoomTest, TurnOffLights) {
    auto light1 = std::make_shared<SmartLight>(1, 100);
    auto light2 = std::make_shared<SmartLight>(2, 100);
    room->addSmartDevice(light1);
    room->addSmartDevice(light2);

    room->turnOffLights();

    EXPECT_EQ(light1->getIntensity(), 0);
    EXPECT_EQ(light2->getIntensity(), 0);
}

// Test locking and unlocking doors
TEST_F(SmartRoomTest, LockUnlockDoors) {
    auto door1 = std::make_shared<SmartDoor>(1);
    auto door2 = std::make_shared<SmartDoor>(2);
    room->addSmartDevice(door1);
    room->addSmartDevice(door2);

    room->lockRoomDoors();
    // Assuming SmartDoor::toggleOn sets the locked state
    EXPECT_TRUE(door1->isLocked());
    EXPECT_TRUE(door2->isLocked());

    room->unlockRoomDoors();
    // Assuming SmartDoor::toggleOff sets the unlocked state
    EXPECT_FALSE(door1->isLocked());
    EXPECT_FALSE(door2->isLocked());
}
