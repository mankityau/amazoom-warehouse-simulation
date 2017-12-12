#ifndef AMAZOOM_WAREHOUSE_SIMULATION_BOTTOCENTRALCLIENTMOCK_H
#define AMAZOOM_WAREHOUSE_SIMULATION_BOTTOCENTRALCLIENTMOCK_H

#include "centralcontroller.h"
#include "manager/common.h"

namespace warehouse {
    class BotToCentralClientMock {
    private:
        warehouse::CentralController* centralController;
    public:
        BotToCentralClientMock(warehouse::CentralController* centralController);
        BotInstruction pollInstruction(Location location);
    };
}


#endif //AMAZOOM_WAREHOUSE_SIMULATION_BOTTOCENTRALCLIENTMOCK_H
