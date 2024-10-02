#ifndef COMMAND_H
#define COMMAND_H

/**
 * @brief Abstract command interface for the Command Pattern.
 */
class Command {
public:
    /**
     * @brief Executes the command.
     */
    virtual void execute() = 0;

    /**
     * @brief Virtual destructor for Command interface.
     */
    virtual ~Command() = default;
};

#endif // COMMAND_H
