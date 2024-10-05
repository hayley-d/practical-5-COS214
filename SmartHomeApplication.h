#ifndef SMARTHOMEAPPLICATION_H
#define SMARTHOMEAPPLICATION_H

#include "SmartRoom.h"
#include "Button.h"
#include <map>
#include <vector>
#include <string>

/**
 * @class SmartHomeApplication
 * @brief Manages a smart home environment, including rooms and devices.
 * 
 * This class provides functionality to add/remove rooms and devices,
 * select a target room, and set up a user interface for controlling devices.
 */
class SmartHomeApplication {
private:
    std::map<std::string, SmartRoom*> rooms;  ///< Mapping of room names to SmartRoom pointers
    SmartRoom* targetRoom;                     ///< Currently selected target room
    std::vector<Button*> buttons;              ///< List of buttons for UI commands

public:
    /**
     * @brief Constructor for SmartHomeApplication.
     * Initializes an empty application with no rooms or target room.
     */
    SmartHomeApplication();

    /**
     * @brief Destructor for SmartHomeApplication.
     * Cleans up the allocated rooms and buttons.
     */
    ~SmartHomeApplication();

    /**
     * @brief Adds a new room to the application.
     * @param roomName The name of the room to be added.
     */
    void addRoom(const std::string& roomName);

    /**
     * @brief Removes a room from the application.
     * @param roomName The name of the room to be removed.
     * @return true if the room was removed successfully, false otherwise.
     */
    bool removeRoom(const std::string& roomName);

    /**
     * @brief Adds a device to a specified room.
     * @param roomName The name of the room where the device should be added.
     * @param device A pointer to the smart device to be added.
     * @return true if the device was added successfully, false otherwise.
     */
    bool addDevice(const std::string& roomName, SmartDevice* device);

    /**
     * @brief Removes a device from a specified room by its type and ID.
     * @param roomName The name of the room from which the device should be removed.
     * @param deviceType The type of the device to be removed.
     * @param deviceId The ID of the device to be removed.
     * @return true if the device was removed successfully, false otherwise.
     */
    bool removeDevice(const std::string& roomName, DeviceType deviceType, int deviceId);

    /**
     * @brief Selects a target room for operations.
     * @param roomName The name of the room to be set as the target.
     * @return true if the target room was set successfully, false otherwise.
     */
    bool selectTargetRoom(const std::string& roomName);

    /**
     * @brief Sets up the user interface with buttons for controlling devices.
     * This method prepares buttons associated with commands for the selected target room.
     */
    void setUpUI();

    /**
     * @brief Executes the command associated with a specified button.
     * @param buttonId The ID of the button to be executed.
     */
    void executeButton(int buttonId);

    /**
     * @brief Retrieves a room by its name.
     * @param roomName The name of the room to retrieve.
     * @return A pointer to the SmartRoom if found, nullptr otherwise.
     */
    SmartRoom* getRoom(const std::string& roomName);
};

#endif // SMARTHOMEAPPLICATION_H
