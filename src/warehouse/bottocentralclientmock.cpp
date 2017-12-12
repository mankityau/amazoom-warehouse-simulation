#include "bottocentralclientmock.h"
namespace warehouse{
    BotToCentralClientMock::BotToCentralClientMock(warehouse::CentralController* centralController) {
        this->centralController = centralController;
    }

    BotInstruction BotToCentralClientMock::pollInstruction(Location location) {
        return centralController->botPollInstruction(location);
    }
}