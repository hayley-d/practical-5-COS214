#ifndef TURNONLIGHTSCOMMAND_H
#define TURNONLIGHTSCOMMAND_H

#include "Command.h"
#include "SmartRoom.h"

class TurnOnLightsCommand : public Command {
    SmartRoom& room;

public:
    TurnOnLightsCommand(SmartRoom& room);
    void execute() override;
};

#endif // TURNONLIGHTSCOMMAND_H
