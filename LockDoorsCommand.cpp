#include "LockDoorsCommand.h"

LockDoorsCommand::LockDoorsCommand(SmartRoom& room) : room(room) {}

void LockDoorsCommand::execute() {
    room.lockRoomDoors();
}
