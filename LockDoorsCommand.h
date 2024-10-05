#ifndef LOCKDOORSCOMMAND_H
#define LOCKDOORSCOMMAND_H

#include "Command.h"
#include "SmartRoom.h"

/**
 * @class LockDoorsCommand
 * @brief A command that locks all doors in a specified smart room.
 */
class LockDoorsCommand : public Command {
private:
    SmartRoom& room; ///< Reference to the SmartRoom where doors will be locked.

public:
    /**
     * @brief Constructor for LockDoorsCommand.
     * @param room The SmartRoom reference to which this command will apply.
     */
    LockDoorsCommand(SmartRoom& room);

    /**
     * @brief Executes the command to lock all doors in the specified room.
     * This method overrides the execute method from the Command base class.
     */
    void execute() override;
};

#endif // LOCKDOORSCOMMAND_H
