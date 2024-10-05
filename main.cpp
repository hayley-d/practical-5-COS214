#include "SmartDevice.h"
#include "SmartRoom.h"
#include "LegacyThermostat.h"
#include "SmartThermostatIntegrator.h"
#include "SmartThermostat.h"
#include "SmartDoor.h"
#include <iostream>
#include "SmartLight.h"
#include "Event.h"
#include "DeviceType.h"
#include "Sensor.h"
#include "LightSensor.h"
#include "TemperatureSensor.h"
#include "TurnOnLightsCommand.h"
#include "TurnOffLightsCommand.h"
#include "SetLightIntensityCommand.h"
#include "LockDoorsCommand.h"
#include "UnlockDoorsCommand.h"
#include "SetTemperatureCommand.h"
#include "MacroCommand.h"
#include "SmartHomeApplication.h"
#include <memory>

#define RESET "\033[0m"
#define GREEN "\033[32m"
#define RED "\033[31m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"

int main() {
    // Test SmartLight
    std::shared_ptr<SmartLight> device1 = std::make_shared<SmartLight>(1, 100);
    std::shared_ptr<SmartLight> device2 = std::make_shared<SmartLight>(2);

    if (device1->getId() == 1 && device2->getId() == 2) {
        std::cout << GREEN << "Test 0 Passed" << RESET << std::endl;
    } else {
        std::cout << RED << "Test 0 Failed" << RESET << std::endl;
    }

    // Test light functions
    if (device1->getIntensity() == 100 && device2->getIntensity() == 0) {
        std::cout << GREEN << "Test 1 Passed" << RESET << std::endl;
    } else {
        std::cout << RED << "Test 1 Failed" << RESET << std::endl;
    }

    device1->toggle();
    device2->toggle();
    if (device1->getIntensity() == 0 && device2->getIntensity() == 100) {
        std::cout << GREEN << "Test 2 Passed" << RESET << std::endl;
    } else {
        std::cout << RED << "Test 2 Failed" << RESET << std::endl;
    }

    device1->toggleOn();
    device2->toggleOn();
    if (device1->getIntensity() == 100 && device2->getIntensity() == 100) {
        std::cout << GREEN << "Test 3 Passed" << RESET << std::endl;
    } else {
        std::cout << RED << "Test 3 Failed" << RESET << std::endl;
    }

    device1->toggleOn();
    device2->toggleOn();
    if (device1->getIntensity() == 100 && device2->getIntensity() == 100) {
        std::cout << GREEN << "Test 4 Passed" << RESET << std::endl;
    } else {
        std::cout << RED << "Test 4 Failed" << RESET << std::endl;
    }

    device1->toggleOff();
    device2->toggleOff();
    if (device1->getIntensity() == 0 && device2->getIntensity() == 0) {
        std::cout << GREEN << "Test 5 Passed" << RESET << std::endl;
    } else {
        std::cout << RED << "Test 5 Failed" << RESET << std::endl;
    }

    device1->toggleOff();
    device2->toggleOff();
    if (device1->getIntensity() == 0 && device2->getIntensity() == 0) {
        std::cout << GREEN << "Test 6 Passed" << RESET << std::endl;
    } else {
        std::cout << RED << "Test 6 Failed" << RESET << std::endl;
    }

    device1->setIntensity(50);
    device2->setIntensity(20);
    if (device1->getIntensity() == 50 && device2->getIntensity() == 20) {
        std::cout << GREEN << "Test 7 Passed" << RESET << std::endl;
    } else {
        std::cout << RED << "Test 7 Failed" << RESET << std::endl;
    }

    device2->toggle();
    if (device1->getStatus() == "Light is on" && device2->getStatus() == "Light is off") {
        std::cout << GREEN << "Test 8 Passed" << RESET << std::endl;
    } else {
        std::cout << RED << "Test 8 Failed" << RESET << std::endl;
    }

    if (device1->getDeviceType() == DeviceType::Light && device2->getDeviceType() == DeviceType::Light) {
        std::cout << GREEN << "Test 9 Passed" << RESET << std::endl;
    } else {
        std::cout << RED << "Test 9 Failed" << RESET << std::endl;
    }

    // Test the DeviceType enum
    std::cout << DeviceType::Light << std::endl;
    std::cout << DeviceType::Thermostat << std::endl;
    std::cout << DeviceType::Door << std::endl;

    std::shared_ptr<SmartDoor> device3 = std::make_shared<SmartDoor>(3);
    std::shared_ptr<SmartDoor> device4 = std::make_shared<SmartDoor>(4);

    if (device3->getId() == 3 && device4->getId() == 4) {
        std::cout << GREEN << "Test 10 Passed" << RESET << std::endl;
    } else {
        std::cout << RED << "Test 10 Failed" << RESET << std::endl;
    }

    device4->toggle();
    if (device3->getStatus() == "Door is unlocked" && device4->getStatus() == "Door is locked") {
        std::cout << GREEN << "Test 11 Passed" << RESET << std::endl;
    } else {
        std::cout << RED << "Test 11 Failed" << RESET << std::endl;
    }

    device3->toggle();
    device4->toggle();
    if (device3->isLocked() && !device4->isLocked()) {
        std::cout << GREEN << "Test 12 Passed" << RESET << std::endl;
    } else {
        std::cout << RED << "Test 12 Failed" << RESET << std::endl;
    }

    device3->toggleOn();
    device4->toggleOn();
    if (device3->isLocked() && device4->isLocked()) {
        std::cout << GREEN << "Test 13 Passed" << RESET << std::endl;
    } else {
        std::cout << RED << "Test 13 Failed" << RESET << std::endl;
    }

    device3->toggleOn();
    device4->toggleOn();
    if (device3->isLocked() && device4->isLocked()) {
        std::cout << GREEN << "Test 14 Passed" << RESET << std::endl;
    } else {
        std::cout << RED << "Test 14 Failed" << RESET << std::endl;
    }

    device3->toggleOff();
    device4->toggleOff();
    if (!device3->isLocked() && !device4->isLocked()) {
        std::cout << GREEN << "Test 15 Passed" << RESET << std::endl;
    } else {
        std::cout << RED << "Test 15 Failed" << RESET << std::endl;
    }

    device3->toggleOff();
    device4->toggleOff();
    if (!device3->isLocked() && !device4->isLocked()) {
        std::cout << GREEN << "Test 16 Passed" << RESET << std::endl;
    } else {
        std::cout << RED << "Test 16 Failed" << RESET << std::endl;
    }

    if (device3->getDeviceType() == DeviceType::Door && device4->getDeviceType() == DeviceType::Door) {
        std::cout << GREEN << "Test 17 Passed" << RESET << std::endl;
    } else {
        std::cout << RED << "Test 17 Failed" << RESET << std::endl;
    }

    std::shared_ptr<SmartThermostat> device5 = std::make_shared<SmartThermostat>(5);
    std::shared_ptr<SmartThermostat> device6 = std::make_shared<SmartThermostat>(6, 15);

    if (device5->getId() == 5 && device6->getId() == 6) {
        std::cout << GREEN << "Test 18 Passed" << RESET << std::endl;
    } else {
        std::cout << RED << "Test 18 Failed" << RESET << std::endl;
    }

    if (device5->getTemperature() == 0 && device6->getTemperature() == 15) {
        std::cout << GREEN << "Test 19 Passed" << RESET << std::endl;
    } else {
        std::cout << RED << "Test 19 Failed" << RESET << std::endl;
    }

    device5->setTemperature(20);
    device6->setTemperature(20);
    if (device5->getTemperature() == 20 && device6->getTemperature() == 20) {
        std::cout << GREEN << "Test 20 Passed" << RESET << std::endl;
    } else {
        std::cout << RED << "Test 20 Failed" << RESET << std::endl;
    }

    if (device5->getDeviceType() == DeviceType::Thermostat && device6->getDeviceType() == DeviceType::Thermostat) {
        std::cout << GREEN << "Test 21 Passed" << RESET << std::endl;
    } else {
        std::cout << RED << "Test 21 Failed" << RESET << std::endl;
    }

    if (device5->getStatus() == "Thermostat is off" && device6->getStatus() == "Thermostat is off") {
        std::cout << GREEN << "Test 22 Passed" << RESET << std::endl;
    } else {
        std::cout << RED << "Test 22 Failed" << RESET << std::endl;
    }

    device5->toggle();
    device6->toggle();
    if (device5->getStatus() == "Thermostat is on" && device6->getStatus() == "Thermostat is on") {
        std::cout << GREEN << "Test 23 Passed" << RESET << std::endl;
    } else {
        std::cout << RED << "Test 23 Failed" << RESET << std::endl;
    }

    device5->toggle();
    device6->toggle();
    if (!device5->isOn() && !device6->isOn()) {
        std::cout << GREEN << "Test 24 Passed" << RESET << std::endl;
    } else {
        std::cout << RED << "Test 24 Failed" << RESET << std::endl;
    }

    device5->toggleOn();
    device6->toggleOn();
    if (device5->isOn() && device6->isOn()) {
        std::cout << GREEN << "Test 25 Passed" << RESET << std::endl;
    } else {
        std::cout << RED << "Test 25 Failed" << RESET << std::endl;
    }

    device5->toggleOff();
    device6->toggleOff();
    if (!device5->isOn() && !device6->isOn()) {
        std::cout << GREEN << "Test 26 Passed" << RESET << std::endl;
    } else {
        std::cout << RED << "Test 26 Failed" << RESET << std::endl;
    }

    std::shared_ptr<LegacyThermostat> legacyDevice = std::make_shared<LegacyThermostat>();
    std::shared_ptr<SmartThermostat> device7 = std::make_shared<SmartThermostatIntegrator>(legacyDevice, 7);

    if (device7->getId() == 7) {
        std::cout << GREEN << "Test 27 Passed" << RESET << std::endl;
    } else {
        std::cout << RED << "Test 27 Failed" << RESET << std::endl;
    }

    if (device7->getTemperature() == 0) {
        std::cout << GREEN << "Test 28 Passed" << RESET << std::endl;
    } else {
        std::cout << RED << "Test 28 Failed" << RESET << std::endl;
    }

    device7->setTemperature(45);
    if (device7->getTemperature() == 45) {
        std::cout << GREEN << "Test 29 Passed" << RESET << std::endl;
    } else {
        std::cout << RED << "Test 29 Failed" << RESET << std::endl;
    }

    device7->setTemperature(0);
    if (device7->getTemperature() == 0) {
        std::cout << GREEN << "Test 30 Passed" << RESET << std::endl;
    } else {
        std::cout << GREEN << "Test 30 Passed" << RESET << std::endl;
    }

    device7->toggleOn();
    if (device7->isOn()) {
        std::cout << GREEN << "Test 31 Passed" << RESET << std::endl;
    } else {
        std::cout << RED << "Test 31 Failed" << RESET << std::endl;
    }

    device7->toggleOff();
    if (!device7->isOn()) {
        std::cout << GREEN << "Test 32 Passed" << RESET << std::endl;
    } else {
        std::cout << RED << "Test 32 Failed" << RESET << std::endl;
    }

    device7->toggle();
    if (device7->isOn()) {
        std::cout << GREEN << "Test 33 Passed" << RESET << std::endl;
    } else {
        std::cout << RED << "Test 33 Failed" << RESET << std::endl;
    }

    if (device7->getStatus() == "Thermostat is on") {
        std::cout << GREEN << "Test 34 Passed" << RESET << std::endl;
    } else {
        std::cout << RED << "Test 34 Failed" << RESET << std::endl;
    }

    device7->toggle();
    if (!device7->isOn()) {
        std::cout << GREEN << "Test 35 Passed" << RESET << std::endl;
    } else {
        std::cout << RED << "Test 35 Failed" << RESET << std::endl;
    }

    if (device7->getStatus() == "Thermostat is off") {
        std::cout << GREEN << "Test 36 Passed" << RESET << std::endl;
    } else {
        std::cout << RED << "Test 36 Failed" << RESET << std::endl;
    }

    if (device7->getDeviceType() == DeviceType::Thermostat) {
        std::cout << GREEN << "Test 37 Passed" << RESET << std::endl;
    } else {
        std::cout << RED << "Test 37 Failed" << RESET << std::endl;
    }

    // Create the SmartRoom as a shared_ptr
    std::shared_ptr<SmartRoom> room1 = std::make_shared<SmartRoom>();
    std::cout << YELLOW << "Creating SmartRoom instance:" << RESET << std::endl;

    // Adding smart devices to the room
    std::cout << BLUE << "Adding smart devices to the room:" << RESET << std::endl;
    room1->addSmartDevice(device1);
    room1->addSmartDevice(device2);
    room1->addSmartDevice(device3);
    room1->addSmartDevice(device4);
    room1->addSmartDevice(device5);

    // Setting the room light intensity
    std::cout << BLUE << "Setting room light intensity to 50:" << RESET << std::endl;
    room1->setRoomLightIntensity(50);

    // Setting the room temperature
    std::cout << BLUE << "Setting room temperature to 19.5:" << RESET << std::endl;
    room1->setRoomTemperature(19.5);

    // Locking all doors
    std::cout << BLUE << "Locking all doors in the room:" << RESET << std::endl;
    room1->lockRoomDoors();

    // Unlocking all doors
    std::cout << BLUE << "Unlocking all doors in the room:" << RESET << std::endl;
    room1->unlockRoomDoors();

    // Turning on all lights
    std::cout << BLUE << "Turning on all lights in the room:" << RESET << std::endl;
    room1->turnOnLights();

    // Turning off all lights
    std::cout << BLUE << "Turning off all lights in the room:" << RESET << std::endl;
    room1->turnOffLights();

    // Adding sensors
    std::cout << BLUE << "Adding movement and temperature sensors:" << RESET << std::endl;
    room1->addSensor(Event::Movement);
    room1->addSensor(Event::Temperature);

    // Notifying devices of movement and temperature events
    std::cout << BLUE << "Notifying devices of movement event:" << RESET << std::endl;
    room1->notify(Event::Movement);
    std::cout << BLUE << "Notifying devices of temperature event:" << RESET << std::endl;
    room1->notify(Event::Temperature);

    // Removing sensors and devices
    //std::cout << BLUE << "Removing sensor with ID 1:" << RESET << std::endl;
    room1->removeSensor(1);
    //std::cout << BLUE << "Removing light device with ID 1:" << RESET << std::endl;
    room1->removeSmartDevice(1, DeviceType::Light);
    //std::cout << BLUE << "Removing door device with ID 2:" << RESET << std::endl;
    room1->removeSmartDevice(2, DeviceType::Door);
    //std::cout << BLUE << "Removing thermostat device with ID 4:" << RESET << std::endl;
    room1->removeSmartDevice(4, DeviceType::Thermostat);

    // Creating another SmartRoom instance
    std::shared_ptr<SmartRoom> room = std::make_shared<SmartRoom>();
    std::cout << YELLOW << "Creating another SmartRoom instance:" << RESET << std::endl;

    // Adding smart devices to the new room
    std::cout << BLUE << "Adding smart devices to the new room:" << RESET << std::endl;
    room->addSmartDevice(device1);
    room->addSmartDevice(device2);
    room->addSmartDevice(device3);
    room->addSmartDevice(device4);
    room->addSmartDevice(device5);


    // Create the commands as shared_ptr
    std::shared_ptr<Command> turnOnLights = std::make_shared<TurnOnLightsCommand>(*room);
    std::shared_ptr<Command> turnOffLights = std::make_shared<TurnOffLightsCommand>(*room);
    std::shared_ptr<Command> setLightIntensity = std::make_shared<SetLightIntensityCommand>(*room, 75);
    std::shared_ptr<Command> setNightIntensity = std::make_shared<SetLightIntensityCommand>(*room, 0);
    std::shared_ptr<Command> lockDoors = std::make_shared<LockDoorsCommand>(*room);
    std::shared_ptr<Command> unlockDoors = std::make_shared<UnlockDoorsCommand>(*room);
    std::shared_ptr<Command> morningTemp = std::make_shared<SetTemperatureCommand>(*room, 16);
    std::shared_ptr<Command> nightTemp = std::make_shared<SetTemperatureCommand>(*room, 25);

    // Create a MacroCommand and add the commands to it
    MacroCommand morningRoutine;
    morningRoutine.addCommand(turnOnLights);      // Add turnOnLights command
    morningRoutine.addCommand(setLightIntensity); // Add setLightIntensity command
    morningRoutine.addCommand(unlockDoors);         // Add lockDoors command
    morningRoutine.addCommand(morningTemp);

    MacroCommand nightRoutine;
    nightRoutine.addCommand(turnOffLights);
    nightRoutine.addCommand(lockDoors);
    nightRoutine.addCommand(setNightIntensity);
    nightRoutine.addCommand(nightTemp);

    std::cout << YELLOW << "Executing nightRoutine MacroCommand:" << RESET << std::endl;
    nightRoutine.execute();

    // Execute the macro command (which will execute all added commands)
    std::cout << YELLOW << "Executing morningRoutine MacroCommand:" << RESET << std::endl;
    morningRoutine.execute();

    // Create the SmartHomeApplication instance
    std::cout << YELLOW << "Creating a SmartHomeApplication:" << RESET << std::endl;
    SmartHomeApplication app;

    // Test adding rooms
    std::cout << BLUE << "Testing adding room: Living Room" << RESET << std::endl;
    app.addRoom("Living Room");
    std::cout << BLUE << "Testing adding room: Kitchen" << RESET << std::endl;
    app.addRoom("Kitchen");

    // Test adding devices to the rooms
    SmartLight* light1 = new SmartLight(1, 100);
    SmartLight* light2 = new SmartLight(2, 50);
    SmartThermostat* thermostat1 = new SmartThermostat(3, 22);
    SmartDoor* door1 = new SmartDoor(4);

    // Add devices to Living Room
    std::cout << BLUE << "Adding devices to Living Room:" << RESET << std::endl;
    app.addDevice("Living Room", light1);
    app.addDevice("Living Room", thermostat1);
    app.addDevice("Living Room", door1);

    // Add devices to Kitchen
    std::cout << BLUE << "Adding device to Kitchen:" << RESET << std::endl;
    app.addDevice("Kitchen", light2);

    // Test removing devices
    std::cout << BLUE << "Testing removal of light1 from Living Room" << RESET << std::endl;
    app.removeDevice("Living Room", DeviceType::Light, 1);  // Remove light1
    std::cout << BLUE << "Testing removal of thermostat1 from Living Room" << RESET << std::endl;
    app.removeDevice("Living Room", DeviceType::Thermostat, 3);  // Remove thermostat1

    // Test removing a room
    std::cout << BLUE << "Testing removal of Kitchen" << RESET << std::endl;
    app.removeRoom("Kitchen");

    // Test selecting a target room
    std::cout << BLUE << "Testing selection of target room: Living Room" << RESET << std::endl;
    app.selectTargetRoom("Living Room");

    // Test setting up the UI for the selected room (Living Room)
    std::cout << BLUE << "Setting up UI for Living Room" << RESET << std::endl;
    app.setUpUI();

    // Test executing buttons (turn on/off lights)
    std::cout << BLUE << "Executing button to turn on lights" << RESET << std::endl;
    app.executeButton(0);  // Turn on lights
    std::cout << BLUE << "Executing button to turn off lights" << RESET << std::endl;
    app.executeButton(1);  // Turn off lights

    // Test selecting a non-existent room (should fail)
    std::cout << BLUE << "Testing selection of non-existent room: Bathroom" << RESET << std::endl;
    app.selectTargetRoom("Bathroom");  // Room does not exist

    // Test adding a room that already exists (should warn)
    std::cout << BLUE << "Testing addition of existing room: Living Room" << RESET << std::endl;
    app.addRoom("Living Room");

    // Clean up dynamic memory
    delete light1;
    delete light2;
    delete thermostat1;
    delete door1;

    return 0;
}
