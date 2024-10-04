#ifndef SETLIGHTINTENSITYCOMMAND_H
#define SETLIGHTINTENSITYCOMMAND_H

#include "Command.h"
#include "SmartRoom.h"

class SetLightIntensityCommand : public Command {
    SmartRoom& room;
    int intensity;

public:
    SetLightIntensityCommand(SmartRoom& room, int intensity);
    void execute() override;
};

#endif // SETLIGHTINTENSITYCOMMAND_H
