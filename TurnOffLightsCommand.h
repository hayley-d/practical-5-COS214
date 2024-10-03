#ifndef TURNOFFLIGHTSCOMMAND_H
#define TURNOFFLIGHTSCOMMAND_H

#include "Command.h"
#include "SmartRoom.h"
#include <iostream>

class TurnOffLightsCommand : public Command {
    SmartRoom& room;

public:
    TurnOffLightsCommand(SmartRoom& room);
    void execute() override;
};

#endif // TURNOFFLIGHTSCOMMAND_H
