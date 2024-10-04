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
int main() {
    // Test SmartLight
    std::shared_ptr<SmartLight> device1 = std::make_shared<SmartLight>(1,100); 
    std::shared_ptr<SmartLight> device2 = std::make_shared<SmartLight>(2); 
    
    if(device1->getId() == 1 && device2->getId() == 2) {
        std::cout << "Test 0 Passed" << std::endl;
    }

    //Test light functions
    if(device1->getIntensity() == 100 && device2->getIntensity() == 0) {
        std::cout << "Test 1 Passed" << std::endl;
    }

    device1->toggle();
    device2->toggle();
    if(device1->getIntensity() == 0 && device2->getIntensity() == 100) {
        std::cout << "Test 2 Passed" << std::endl;
    }

    device1->toggleOn();
    device2->toggleOn();
    if(device1->getIntensity() == 100 && device2->getIntensity() == 100) {
        std::cout << "Test 3 Passed" << std::endl;
    }

    device1->toggleOn();
    device2->toggleOn();
    if(device1->getIntensity() == 100 && device2->getIntensity() == 100) {
        std::cout << "Test 4 Passed" << std::endl;
    }

    device1->toggleOff();
    device2->toggleOff();
    if(device1->getIntensity() == 0 && device2->getIntensity() == 0) {
        std::cout << "Test 5 Passed" << std::endl;
    }

    device1->toggleOff();
    device2->toggleOff();
    if(device1->getIntensity() == 0 && device2->getIntensity() == 0) {
        std::cout << "Test 6 Passed" << std::endl;
    }

    device1->setIntensity(50);
    device2->setIntensity(20);
    if(device1->getIntensity() == 50 && device2->getIntensity() == 20) {
        std::cout << "Test 7 Passed" << std::endl;
    }

    device2->toggle();
    if(device1->getStatus() == "Light is on" && device2->getStatus() == "Light is off") {
        std::cout << "Test 8 Passed" << std::endl;
    }

    if(device1->getDeviceType() == DeviceType::Light && device2->getDeviceType() == DeviceType::Light) {
        std::cout << "Test 9 Passed" << std::endl;
    }

    //Test the DeviceType enum
    std::cout << DeviceType::Light << std::endl;
    std::cout << DeviceType::Thermostat << std::endl;
    std::cout << DeviceType::Door << std::endl;
    
    std::shared_ptr<SmartDoor> device3 = std::make_shared<SmartDoor>(3); 
    std::shared_ptr<SmartDoor> device4 = std::make_shared<SmartDoor>(4); 

    if(device3->getId() == 3 && device4->getId() == 4) {
        std::cout << "Test 1 Passed" << std::endl;
    }

    device4->toggle();
    if(device3->getStatus() == "Door is unlocked" && device4->getStatus() == "Door is locked") {
        std::cout << "Test 2 Passed" << std::endl;
    }

    device3->toggle();
    device4->toggle();
    if(device3->isLocked() && !device4->isLocked()) {
        std::cout << "Test 3 Passed" << std::endl;
    }

    device3->toggleOn();
    device4->toggleOn();
    if(device3->isLocked() && device4->isLocked()) {
        std::cout << "Test 4 Passed" << std::endl;
    }

    device3->toggleOn();
    device4->toggleOn();
    if(device3->isLocked() && device4->isLocked()) {
        std::cout << "Test 5 Passed" << std::endl;
    }

    device3->toggleOff();
    device4->toggleOff();
    if(!device3->isLocked() && !device4->isLocked()) {
        std::cout << "Test 6 Passed" << std::endl;
    }

    device3->toggleOff();
    device4->toggleOff();
    if(!device3->isLocked() && !device4->isLocked()) {
        std::cout << "Test 7 Passed" << std::endl;
    }

    if(device3->getDeviceType() == DeviceType::Door && device4->getDeviceType() == DeviceType::Door) {
        std::cout << "Test 8 Passed" << std::endl;
    }
 
    std::shared_ptr<SmartThermostat> device5 = std::make_shared<SmartThermostat>(5); 
    std::shared_ptr<SmartThermostat> device6 = std::make_shared<SmartThermostat>(6,15); 

    if(device5->getId() == 5 && device6->getId() == 6) {
        std::cout << "Test 1 Passed" << std::endl;
    }

    if(device5->getTemperature() == 0 && device6->getTemperature() == 15) {
        std::cout << "Test 2 Passed" << std::endl;
    }

    device5->setTemperature(20);
    device6->setTemperature(20);
    if(device5->getTemperature() == 20 && device6->getTemperature() == 20) {
        std::cout << "Test 3 Passed" << std::endl;
    }

    if(device5->getDeviceType() == DeviceType::Thermostat && device6->getDeviceType() == DeviceType::Thermostat) {
        std::cout << "Test 4 Passed" << std::endl;
    }

    if(device5->getStatus() == "Thermostat is off" && device6->getStatus() == "Thermostat is off") {
        std::cout << "Test 5 passed" <<std::endl;
    }

    device5->toggle();
    device6->toggle();
    if(device5->getStatus() == "Thermostat is on" && device6->getStatus() == "Thermostat is on") {
        std::cout << "Test 6 passed" <<std::endl;
    }

    device5->toggle();
    device6->toggle();
    if(!device5->isOn() && !device6->isOn()) {
        std::cout << "Test 7 Passed" <<std::endl;
    }

    device5->toggleOn();
    device6->toggleOn();
    if(device5->isOn() && device6->isOn()) {
        std::cout << "Test 8 Passed" <<std::endl;
    }

    device5->toggleOff();
    device6->toggleOff();
    if(!device5->isOn() && !device6->isOn()) {
        std::cout << "Test 9 Passed" <<std::endl;
    }

    std::shared_ptr<LegacyThermostat> legacyDevice = std::make_shared<LegacyThermostat>();
    std::shared_ptr<SmartThermostat> device7 = std::make_shared<SmartThermostatIntegrator>(legacyDevice,7);

    if(device7->getId() == 7) {
        std::cout << "Test 1 Passed" << std::endl;
    }

    if(device7->getTemperature() == 0) {
        std::cout << "Test 2 Passed" << std::endl;
    }

    device7->setTemperature(45);
    if(device7->getTemperature() == 45) {
        std::cout << "Test 3 Passed" << std::endl;
    }

    device7->setTemperature(0);
    if(device7->getTemperature() == 0.0) {
        std::cout << "Test 4 Passed" << std::endl;
    }

    device7->toggleOn();
    if(device7->isOn()) {
        std::cout << "Test 5 Passed" << std::endl;
    }

    device7->toggleOff();
    if(!device7->isOn()) {
        std::cout << "Test 6 Passed" << std::endl;
    }

    device7->toggle();
    if(device7->isOn()) {
        std::cout << "Test 7 Passed" << std::endl;
    }

    if(device7->getStatus() == "Thermostat is on") {
        std::cout << "Test 8 Passed" << std::endl;
    }

    device7->toggle();
    if(!device7->isOn()) {
        std::cout << "Test 9 Passed" << std::endl;
    }

    if(device7->getStatus() == "Thermostat is off") {
        std::cout << "Test 10 Passed" << std::endl;
    }

    if(device7->getDeviceType() == DeviceType::Thermostat) {
        std::cout << "Test 11 Passed" << std::endl;
    }

    std::shared_ptr<SmartRoom> room1 = std::make_shared<SmartRoom>();

    room1->addSmartDevice(device1);
    room1->addSmartDevice(device2);
    room1->addSmartDevice(device3);
    room1->addSmartDevice(device4);
    room1->addSmartDevice(device5);

    room1->setRoomLightIntensity(50);
    room1->setRoomTemperature(19.5);

    room1->lockRoomDoors();
    room1->unlockRoomDoors();
    room1->turnOnLights();
    room1->turnOffLights();

    room1->addSensor(Event::Movement); 
    room1->addSensor(Event::Temperature);

    room1->notify(Event::Movement);
    room1->notify(Event::Temperature);

    room1->removeSensor(1);
    room1->removeSmartDevice(1, DeviceType::Light);
    room1->removeSmartDevice(2, DeviceType::Door);
    room1->removeSmartDevice(4, DeviceType::Thermostat);


    // Create the SmartRoom as a shared_ptr
    std::shared_ptr<SmartRoom> room = std::make_shared<SmartRoom>();

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
    std::shared_ptr<Command> morningTemp = std::make_shared<SetTemperatureCommand>(*room,16);
    std::shared_ptr<Command> nightTemp = std::make_shared<SetTemperatureCommand>(*room,25);

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

    std::cout << "Executing nightRoutine MacroCommand:" << std::endl;
    nightRoutine.execute();

    // Execute the macro command (which will execute all added commands)
    std::cout << "Executing morningRoutine MacroCommand:" << std::endl;
    morningRoutine.execute();

    // Create the SmartHomeApplication instance
    SmartHomeApplication app;

    // Test adding rooms
    app.addRoom("Living Room");
    app.addRoom("Kitchen");

    // Test adding devices to the rooms
    SmartLight* light1 = new SmartLight(1, 100);
    SmartLight* light2 = new SmartLight(2, 50);
    SmartThermostat* thermostat1 = new SmartThermostat(3, 22);
    SmartDoor* door1 = new SmartDoor(4);

    // Add devices to Living Room
    app.addDevice("Living Room", light1);
    app.addDevice("Living Room", thermostat1);
    app.addDevice("Living Room", door1);

    // Add devices to Kitchen
    app.addDevice("Kitchen", light2);

    // Test removing devices
    app.removeDevice("Living Room", DeviceType::Light, 1);  // Remove light1
    app.removeDevice("Living Room", DeviceType::Thermostat, 3);  // Remove thermostat1

    // Test removing a room
    app.removeRoom("Kitchen");

    // Test selecting a target room
    app.selectTargetRoom("Living Room");

    // Test setting up the UI for the selected room (Living Room)
    app.setUpUI();

    // Test executing buttons (turn on/off lights)
    app.executeButton(0);  // Turn on lights
    app.executeButton(1);  // Turn off lights

    // Test selecting a non-existent room (should fail)
    app.selectTargetRoom("Bathroom");  // Room does not exist

    // Test adding a room that already exists (should warn)
    app.addRoom("Living Room");

    // Clean up dynamic memory
    delete light1;
    delete light2;
    delete thermostat1;
    delete door1;

    return 0;
}
