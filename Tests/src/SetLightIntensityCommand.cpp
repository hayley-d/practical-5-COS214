#include "SetLightIntensityCommand.h"

SetLightIntensityCommand::SetLightIntensityCommand(SmartRoom& room, int intensity)
    : room(room), intensity(intensity) {}

void SetLightIntensityCommand::execute() {
    room.setRoomLightIntensity(intensity);
}
