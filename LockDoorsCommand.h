#ifndef LOCKDOORSCOMMAND_H
#define LOCKDOORSCOMMAND_H

#include "Command.h"
#include "SmartRoom.h"

class LockDoorsCommand : public Command {
    SmartRoom& room;

public:
    LockDoorsCommand(SmartRoom& room);
    void execute() override;
};

#endif // LOCKDOORSCOMMAND_H
