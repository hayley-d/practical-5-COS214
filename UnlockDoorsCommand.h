#ifndef UNLOCKDOORSCOMMAND_H
#define UNLOCKDOORSCOMMAND_H

#include "Command.h"
#include "SmartRoom.h"

class UnlockDoorsCommand : public Command {
    SmartRoom& room;

public:
    UnlockDoorsCommand(SmartRoom& room);
    void execute() override;
};

#endif // UNLOCKDOORSCOMMAND_H
