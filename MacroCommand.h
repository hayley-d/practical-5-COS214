#ifndef MACROCOMMAND_H
#define MACROCOMMAND_H

#include "Command.h"
#include <vector>
#include <memory>

/**
 * @class MacroCommand
 * @brief A command that encapsulates a sequence of other commands, allowing them to be executed as a group.
 */
class MacroCommand : public Command {
private:
    std::vector<std::shared_ptr<Command>> commands; ///< List of commands to be executed.

public:
    /**
     * @brief Constructor for MacroCommand.
     * Initializes an empty macro command.
     */
    MacroCommand() = default;

    /**
     * @brief Adds a command to the macro command sequence.
     * @param command A shared pointer to a command that will be added to the macro.
     */
    void addCommand(std::shared_ptr<Command> command) {
        commands.push_back(command);
    }

    /**
     * @brief Executes all the commands in the macro command sequence.
     * Each command is executed in the order in which it was added.
     */
    void execute() override {
        for (const auto& command : commands) {
            command->execute();
        }
    }
};

#endif // MACROCOMMAND_H
