#ifndef AMAZOOM_WAREHOUSE_SIMULATION_BOTMANAGER_H
#define AMAZOOM_WAREHOUSE_SIMULATION_BOTMANAGER_H

#include "common.h"
#include "dynamicinstructionqueue.h"

namespace warehouse {
    class BotManager {
    private:
        DynamicInstructionQueue instructionQueue;
    public:
        bool startDeliveryOrder(int orderId, Merchandise merchandise, ShelfSpace shelfSpace, LoadingBay loadingBay);
        BotInstructionBase nextInstructionBase(Location botLocation);
    };
}


#endif //AMAZOOM_WAREHOUSE_SIMULATION_BOTMANAGER_H
