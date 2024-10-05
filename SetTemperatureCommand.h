#ifndef SETTEMPERATURECOMMAND_H
#define SETTEMPERATURECOMMAND_H

#include "Command.h"
#include "SmartRoom.h"

/**
 * @class SetTemperatureCommand
 * @brief A command that sets the temperature in a specified smart room.
 */
class SetTemperatureCommand : public Command {
private:
    SmartRoom& room;       ///< Reference to the SmartRoom where the temperature will be set.
    double temperature;     ///< The desired temperature to set in the room.

public:
    /**
     * @brief Constructor for SetTemperatureCommand.
     * @param room The SmartRoom reference to which this command will apply.
     * @param temperature The temperature value to set in the room.
     */
    SetTemperatureCommand(SmartRoom& room, double temperature);

    /**
     * @brief Executes the command to set the temperature in the specified room.
     * This method overrides the execute method from the Command base class.
     */
    void execute() override;
};

#endif // SETTEMPERATURECOMMAND_H
