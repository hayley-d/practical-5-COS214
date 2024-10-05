#ifndef TURNOFFLIGHTSCOMMAND_H
#define TURNOFFLIGHTSCOMMAND_H

#include "Command.h"
#include "SmartRoom.h"
#include <iostream>

/**
 * @class TurnOffLightsCommand
 * @brief A command that turns off all lights in a specified smart room.
 */
class TurnOffLightsCommand : public Command {
private:
    SmartRoom& room; ///< Reference to the SmartRoom where the lights will be turned off.

public:
    /**
     * @brief Constructor for TurnOffLightsCommand.
     * @param room The SmartRoom reference to which this command will apply.
     */
    TurnOffLightsCommand(SmartRoom& room);

    /**
     * @brief Executes the command to turn off all lights in the specified room.
     * This method overrides the execute method from the Command base class.
     */
    void execute() override;
};

#endif // TURNOFFLIGHTSCOMMAND_H
