#include "MacroCommand.h"

void MacroCommand::addCommand(std::shared_ptr<Command> command) {
    commands.push_back(command);
}

void MacroCommand::execute() {
    for (const auto& command : commands) {
        command->execute();
    }
}
