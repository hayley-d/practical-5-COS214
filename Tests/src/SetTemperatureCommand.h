#ifndef SETTEMPERATURECOMMAND_H
#define SETTEMPERATURECOMMAND_H

#include "Command.h"
#include "SmartRoom.h"

class SetTemperatureCommand : public Command {
    SmartRoom& room;
    double temperature;

public:
    SetTemperatureCommand(SmartRoom& room, double temperature);
    void execute() override;
};

#endif // SETTEMPERATURECOMMAND_H
