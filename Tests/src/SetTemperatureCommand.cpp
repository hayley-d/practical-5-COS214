#include "SetTemperatureCommand.h"

SetTemperatureCommand::SetTemperatureCommand(SmartRoom& room, double temperature)
    : room(room), temperature(temperature) {}

void SetTemperatureCommand::execute() {
    room.setRoomTemperature(temperature);
}
