#include "SmartHomeApplication.h"
#include "TurnOnLightsCommand.h"
#include "TurnOffLightsCommand.h"
#include "Button.h"
#include <iostream>

SmartHomeApplication::SmartHomeApplication() : targetRoom(nullptr) {
    // Constructor
}

SmartHomeApplication::~SmartHomeApplication() {
    // Clean up rooms and buttons
    for (auto& roomPair : rooms) {
        delete roomPair.second;
    }

    for (Button* button : buttons) {
        delete button;
    }
}

void SmartHomeApplication::addRoom(const std::string& roomName) {
    if (rooms.find(roomName) == rooms.end()) {
        rooms[roomName] = new SmartRoom();
        std::cout << "Room " << roomName << " added." << std::endl;
    } else {
        std::cout << "Room " << roomName << " already exists." << std::endl;
    }
}

bool SmartHomeApplication::removeRoom(const std::string& roomName) {
    auto it = rooms.find(roomName);
    if (it != rooms.end()) {
        delete it->second;
        rooms.erase(it);
        std::cout << "Room " << roomName << " removed." << std::endl;
        return true;
    } else {
        std::cout << "Room " << roomName << " not found." << std::endl;
        return false;
    }
}

bool SmartHomeApplication::addDevice(const std::string& roomName, SmartDevice* device) {
    SmartRoom* room = getRoom(roomName);
    if (!room) {
        std::cout << "Room not found." << std::endl;
        return false;
    }

    // Determine device type and add it accordingly
    if (auto light = dynamic_cast<SmartLight*>(device)) {
        room->addSmartDevice(std::make_shared<SmartLight>(*light));
    } else if (auto thermostat = dynamic_cast<SmartThermostat*>(device)) {
        room->addSmartDevice(std::make_shared<SmartThermostat>(*thermostat));
    } else if (auto door = dynamic_cast<SmartDoor*>(device)) {
        room->addSmartDevice(std::make_shared<SmartDoor>(*door));
    } else {
        std::cout << "Unsupported device type." << std::endl;
        return false;
    }

    std::cout << "Device added to room " << roomName << "." << std::endl;
    return true;
}


bool SmartHomeApplication::removeDevice(const std::string& roomName, DeviceType deviceType, int deviceId) {
    // Find the room by its name
    SmartRoom* room = getRoom(roomName);
    if (!room) {
        std::cout << "Room not found: " << roomName << std::endl;
        return false;
    }

    // Call the removeSmartDevice function in the SmartRoom class
    bool removed = room->removeSmartDevice(deviceId, deviceType);
    if (removed) {
        std::cout << "Device removed from room: " << roomName << std::endl;
    } else {
        std::cout << "Failed to remove device from room: " << roomName << std::endl;
    }

    return removed;
}

bool SmartHomeApplication::selectTargetRoom(const std::string& roomName) {
    SmartRoom* room = getRoom(roomName);
    if (room) {
        targetRoom = room;
        std::cout << "Target room set to " << roomName << "." << std::endl;
        return true;
    }
    std::cout << "Room " << roomName << " not found." << std::endl;
    return false;
}

void SmartHomeApplication::setUpUI() {
    // Check if a target room has been selected
    if (!targetRoom) {
        std::cout << "No target room selected for UI setup." << std::endl;
        return;
    }

    // Create commands for turning lights on and off
    Command* turnOnLightsCommand = new TurnOnLightsCommand(*targetRoom);
    Command* turnOffLightsCommand = new TurnOffLightsCommand(*targetRoom);

    // Create buttons for the commands
    Button* turnOnButton = new Button(turnOnLightsCommand);
    Button* turnOffButton = new Button(turnOffLightsCommand);

    // Store the buttons in the buttons vector
    buttons.push_back(turnOnButton);
    buttons.push_back(turnOffButton);

    std::cout << "UI set up with buttons for room." << std::endl;
}

void SmartHomeApplication::executeButton(int buttonId) {
    if (buttonId >= 0 && buttonId < (int)buttons.size()) {
        buttons[buttonId]->execute();
        std::cout << "Button " << buttonId << " pressed." << std::endl;
    } else {
        std::cout << "Invalid button ID." << std::endl;
    }
}

SmartRoom* SmartHomeApplication::getRoom(const std::string& roomName) {
    auto it = rooms.find(roomName);
    if (it != rooms.end()) {
        return it->second;
    }
    return nullptr;
}
