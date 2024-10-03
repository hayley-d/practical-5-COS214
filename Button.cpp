#include "Button.h"
#include <iostream>

Button::Button(Command* command) : command(command) {}

void Button::setCommand(Command* newCommand) {
    if (command != nullptr) {
        delete command;  // Clean up the old command to avoid memory leaks
    }
    command = newCommand;
}

void Button::execute() {
    if (command != nullptr) {
        command->execute();
    } else {
        std::cout << "No command assigned to the button." << std::endl;
    }
}

Button::~Button() {
    // Ensure that the command is deleted when the button is destroyed
    if (command != nullptr) {
        delete command;
        command = nullptr;
    }
}
