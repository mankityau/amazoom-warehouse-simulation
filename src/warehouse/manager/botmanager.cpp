#include "botmanager.h"

namespace warehouse {
    //fix this mock
    bool BotManager::startDeliveryOrder(int orderId, Merchandise merchandise, ShelfSpace shelfSpace, LoadingBay loadingBay) {
        instructionQueue.add({deliver, shelfSpace, merchandise, loadingBay});
        return true;
    }

    BotInstructionBase BotManager::nextInstructionBase(Location botLocation) {
        BotInstructionBase botInstructionBase = instructionQueue.get();
        return botInstructionBase;
    };
}