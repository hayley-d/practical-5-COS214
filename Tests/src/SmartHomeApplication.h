#ifndef SMARTHOMEAPPLICATION_H
#define SMARTHOMEAPPLICATION_H
#include "SmartRoom.h"
#include "Button.h"
#include <map>
#include <vector>
#include <string>

class SmartHomeApplication {

    std::map<std::string, SmartRoom*> rooms;
    SmartRoom* targetRoom;
    std::vector<Button*> buttons;

public:
    SmartHomeApplication();
    ~SmartHomeApplication();

    void addRoom(const std::string& roomName);
    bool removeRoom(const std::string& roomName);
    bool addDevice(const std::string& roomName, SmartDevice* device);
    bool removeDevice(const std::string& roomName, DeviceType deviceType, int deviceId);
    bool selectTargetRoom(const std::string& roomName);
    void setUpUI();
    void executeButton(int buttonId);
    SmartRoom* getRoom(const std::string& roomName);
};

#endif // SMARTHOMEAPPLICATION_H
