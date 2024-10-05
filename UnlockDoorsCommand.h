#ifndef UNLOCKDOORSCOMMAND_H
#define UNLOCKDOORSCOMMAND_H

#include "Command.h"
#include "SmartRoom.h"

/**
 * @class UnlockDoorsCommand
 * @brief A command that unlocks all doors in a specified smart room.
 */
class UnlockDoorsCommand : public Command {
private:
    SmartRoom& room; ///< Reference to the SmartRoom where the doors will be unlocked.

public:
    /**
     * @brief Constructor for UnlockDoorsCommand.
     * @param room The SmartRoom reference to which this command will apply.
     */
    UnlockDoorsCommand(SmartRoom& room);

    /**
     * @brief Executes the command to unlock all doors in the specified room.
     * This method overrides the execute method from the Command base class.
     */
    void execute() override;
};

#endif // UNLOCKDOORSCOMMAND_H
