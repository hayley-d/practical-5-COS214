#ifndef BUTTON_H
#define BUTTON_H

#include "Command.h"

/**
 * @brief Represents a Button that triggers commands in the Smart Home System.
 */
class Button {
private:
    Command* command;  ///< The command associated with the button

public:
    /**
     * @brief Constructor for the Button class.
     * @param command A pointer to a command that the button will trigger.
     */
    Button(Command* command);

    /**
     * @brief Sets a new command to the button.
     * @param newCommand A pointer to the new command to be assigned.
     */
    void setCommand(Command* newCommand);

    /**
     * @brief Executes the command assigned to the button.
     */
    void execute();

    /**
     * @brief Destructor for the Button class.
     */
    ~Button();
};

#endif // BUTTON_H
