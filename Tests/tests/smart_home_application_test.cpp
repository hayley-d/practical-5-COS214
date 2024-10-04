#include "../src/SmartHomeApplication.h"
#include "../src/SmartRoom.h"
#include "../src/SmartLight.h"
#include "../src/SmartThermostat.h"
#include "../src/SmartDoor.h"
#include <gtest/gtest.h>

TEST(SmartHomeApplicationTest, AddRoomAddsRoomSuccessfully) {
    SmartHomeApplication app;
    app.addRoom("Living Room");

    ASSERT_NE(app.getRoom("Living Room"), nullptr);
}

TEST(SmartHomeApplicationTest, AddRoomPreventsDuplicateRooms) {
    SmartHomeApplication app;
    app.addRoom("Living Room");
    app.addRoom("Living Room");

    ASSERT_NE(app.getRoom("Living Room"), nullptr);
}

TEST(SmartHomeApplicationTest, RemoveRoomRemovesRoomSuccessfully) {
    SmartHomeApplication app;
    app.addRoom("Living Room");

    ASSERT_TRUE(app.removeRoom("Living Room"));
    ASSERT_EQ(app.getRoom("Living Room"), nullptr);
}

TEST(SmartHomeApplicationTest, RemoveRoomFailsIfRoomDoesNotExist) {
    SmartHomeApplication app;
    ASSERT_FALSE(app.removeRoom("NonExistentRoom"));
}

TEST(SmartHomeApplicationTest, AddDeviceAddsDeviceToRoom) {
    SmartHomeApplication app;
    app.addRoom("Bedroom");

    SmartLight* light = new SmartLight(1);
    ASSERT_TRUE(app.addDevice("Bedroom", light));
    SmartRoom* room = app.getRoom("Bedroom");
    ASSERT_EQ(room->lights.size(), 1);
}

TEST(SmartHomeApplicationTest, AddDeviceFailsIfRoomDoesNotExist) {
    SmartHomeApplication app;
    SmartLight* light = new SmartLight(1);
    ASSERT_FALSE(app.addDevice("NonExistentRoom", light));
}

TEST(SmartHomeApplicationTest, RemoveDeviceRemovesDeviceSuccessfully) {
    SmartHomeApplication app;
    app.addRoom("Living Room");

    SmartLight* light = new SmartLight(1);
    app.addDevice("Living Room", light);

    ASSERT_TRUE(app.removeDevice("Living Room", DeviceType::Light, 1));
    ASSERT_EQ(app.getRoom("Living Room")->lights.size(), 0);
}

TEST(SmartHomeApplicationTest, RemoveDeviceFailsIfDeviceNotFound) {
    SmartHomeApplication app;
    app.addRoom("Living Room");

    ASSERT_FALSE(app.removeDevice("Living Room", DeviceType::Light, 1));
}

TEST(SmartHomeApplicationTest, SelectTargetRoomWorks) {
    SmartHomeApplication app;
    app.addRoom("Kitchen");
    ASSERT_TRUE(app.selectTargetRoom("Kitchen"));
}

TEST(SmartHomeApplicationTest, SelectTargetRoomFailsIfRoomNotFound) {
    SmartHomeApplication app;
    ASSERT_FALSE(app.selectTargetRoom("NonExistentRoom"));
}

TEST(SmartHomeApplicationTest, ExecuteButtonWorks) {
    SmartHomeApplication app;
    app.addRoom("Bedroom");
    app.selectTargetRoom("Bedroom");
    app.setUpUI();
    app.executeButton(0);
    app.executeButton(1);
}

TEST(SmartHomeApplicationTest, ExecuteButtonFailsForInvalidButtonId) {
    SmartHomeApplication app;
    app.addRoom("Bedroom");
    app.selectTargetRoom("Bedroom");
    app.setUpUI();
    app.executeButton(5);
}
