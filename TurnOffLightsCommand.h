#ifndef TURNOFFLIGHTSCOMMAND_H
#define TURNOFFLIGHTSCOMMAND_H

#include "Command.h"
#include "SmartRoom.h"

class TurnOffLightsCommand : public Command {
    SmartRoom& room;

public:
    TurnOffLightsCommand(SmartRoom& room);
    void execute() override;
};

#endif // TURNOFFLIGHTSCOMMAND_H
