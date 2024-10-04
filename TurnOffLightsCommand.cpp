#include "TurnOffLightsCommand.h"

TurnOffLightsCommand::TurnOffLightsCommand(SmartRoom& room) : room(room) {}

void TurnOffLightsCommand::execute() {
    room.turnOffLights();
}
