#ifndef SETLIGHTINTENSITYCOMMAND_H
#define SETLIGHTINTENSITYCOMMAND_H

#include "Command.h"
#include "SmartRoom.h"

/**
 * @class SetLightIntensityCommand
 * @brief A command that sets the light intensity in a specified smart room.
 */
class SetLightIntensityCommand : public Command {
private:
    SmartRoom& room;  ///< Reference to the SmartRoom where the light intensity will be set.
    int intensity;    ///< The desired light intensity level.

public:
    /**
     * @brief Constructor for SetLightIntensityCommand.
     * @param room The SmartRoom reference to which this command will apply.
     * @param intensity The light intensity level to set in the room.
     */
    SetLightIntensityCommand(SmartRoom& room, int intensity);

    /**
     * @brief Executes the command to set the light intensity in the specified room.
     * This method overrides the execute method from the Command base class.
     */
    void execute() override;
};

#endif // SETLIGHTINTENSITYCOMMAND_H
