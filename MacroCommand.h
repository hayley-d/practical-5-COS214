#ifndef MACROCOMMAND_H
#define MACROCOMMAND_H

#include "Command.h"
#include <vector>
#include <memory>

class MacroCommand : public Command {
private:
    std::vector<std::shared_ptr<Command>> commands;

public:
    MacroCommand() = default;

    // Add a command to the macro
    void addCommand(std::shared_ptr<Command> command) {
        commands.push_back(command);
    }

    // Execute all the commands in the macro
    void execute() override {
        for (const auto& command : commands) {
            command->execute();
        }
    }
};

#endif // MACROCOMMAND_H
