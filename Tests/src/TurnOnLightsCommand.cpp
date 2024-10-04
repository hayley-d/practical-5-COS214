#include "TurnOnLightsCommand.h"

TurnOnLightsCommand::TurnOnLightsCommand(SmartRoom& room) : room(room) {}

void TurnOnLightsCommand::execute() {
    room.turnOnLights();
}
