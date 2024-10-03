#ifndef SMARTHOMEAPPLICATION_H
#define SMARTHOMEAPPLICATION_H

#include "SmartRoom.h"
#include "Button.h"
#include <map>
#include <vector>
#include <string>

class SmartHomeApplication {
private:
    std::map<std::string, SmartRoom*> rooms;  // Mapping room names to SmartRoom pointers
    SmartRoom* targetRoom;                    // Currently selected target room
    std::vector<Button*> buttons;             // List of buttons for UI commands

public:
    SmartHomeApplication();
    ~SmartHomeApplication();

    void addRoom(const std::string& roomName);                     // Add a new room
    bool removeRoom(const std::string& roomName);                  // Remove a room
    bool addDevice(const std::string& roomName, SmartDevice* device); // Add a device to a room
    bool removeDevice(const std::string& roomName, DeviceType deviceType, int deviceId); // Remove a device by type and ID
    bool selectTargetRoom(const std::string& roomName);            // Select a target room for operations
    void setUpUI();                                                // Set up the button UI for the home application
    void executeButton(int buttonId);                              // Execute the command associated with a button

    SmartRoom* getRoom(const std::string& roomName);               // Helper function to get a room by name
};

#endif // SMARTHOMEAPPLICATION_H
