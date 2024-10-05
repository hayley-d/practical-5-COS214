#ifndef TURNONLIGHTSCOMMAND_H
#define TURNONLIGHTSCOMMAND_H

#include "Command.h"
#include "SmartRoom.h"

/**
 * @class TurnOnLightsCommand
 * @brief A command that turns on all lights in a specified smart room.
 */
class TurnOnLightsCommand : public Command {
private:
    SmartRoom& room; ///< Reference to the SmartRoom where the lights will be turned on.

public:
    /**
     * @brief Constructor for TurnOnLightsCommand.
     * @param room The SmartRoom reference to which this command will apply.
     */
    TurnOnLightsCommand(SmartRoom& room);

    /**
     * @brief Executes the command to turn on all lights in the specified room.
     * This method overrides the execute method from the Command base class.
     */
    void execute() override;
};

#endif // TURNONLIGHTSCOMMAND_H
