#ifndef MACROCOMMAND_H
#define MACROCOMMAND_H

#include "Command.h"
#include <vector>
#include <memory>

class MacroCommand : public Command {
    std::vector<std::shared_ptr<Command>> commands;

public:
    MacroCommand() = default;
    void addCommand(std::shared_ptr<Command> command);
    void execute() override;
};

#endif // MACROCOMMAND_H
