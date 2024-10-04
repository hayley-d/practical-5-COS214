#include "UnlockDoorsCommand.h"

UnlockDoorsCommand::UnlockDoorsCommand(SmartRoom& room) : room(room) {}

void UnlockDoorsCommand::execute() {
    room.unlockRoomDoors();
}
