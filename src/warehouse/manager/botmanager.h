#ifndef AMAZOOM_WAREHOUSE_SIMULATION_BOTMANAGER_H
#define AMAZOOM_WAREHOUSE_SIMULATION_BOTMANAGER_H

#include "common.h"

namespace warehouse {
    class BotManager {
    public:
        bool startDeliveryOrder(int orderId, Merchandise merchandise, ShelfSpace shelfSpace, LoadingBay loadingBay);
    };
}


#endif //AMAZOOM_WAREHOUSE_SIMULATION_BOTMANAGER_H
