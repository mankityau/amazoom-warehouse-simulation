#include "botmanager.h"

namespace warehouse {
    void BotManager::log(std::string msg){
        std::cout << "Bot Manager: " << msg << std::endl;
    }
    //fix this mock
    bool BotManager::startDeliveryOrder(int orderId, Merchandise merchandise, ShelfSpace shelfSpace, LoadingBay loadingBay) {
        log("Adding Delivery Order. OrderId: " + std::to_string(orderId) + toString(merchandise) + toString(shelfSpace) + toString(loadingBay));
        instructionQueue.add({deliver, shelfSpace, merchandise, loadingBay});
        return true;
    }

    BotInstructionBase BotManager::nextInstructionBase(Location botLocation) {
        log("Polling next instruction");
        BotInstructionBase botInstructionBase = instructionQueue.get();
        log("Get instruction");
        return botInstructionBase;
    };
}