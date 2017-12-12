#ifndef AMAZOOM_WAREHOUSE_SIMULATION_CENTRALCONTROLLER_H
#define AMAZOOM_WAREHOUSE_SIMULATION_CENTRALCONTROLLER_H

#include "warehouse/manager/common.h"
#include "warehouse/manager/botmanager.h"
#include "warehouse/manager/deliverymanager.h"
#include "warehouse/manager/layoutmanager.h"
#include "warehouse/manager/inventorymanager.h"
#include "warehouse/manager/ordermanager.h"
#include "manager/shelfspacemanager.h"
#include <vector>

namespace warehouse {
    struct NewOrderResponse{
        const bool success;
        const int orderId;
    };
    class CentralController {
    private:
        LayoutManager layoutManager;
        InventoryManager inventoryManager;
        OrderManager orderManager;
        ShelfSpaceManager shelfSpaceManager;
        DeliveryManager deliveryManager;
        BotManager botManager;
        void log(std::string msg);

    public:
        CentralController();
        NewOrderResponse newOrder(std::vector<int> merchandiseIds);

        /**
         * Called when delivery truck arrive, return a loadingBay when a bay ready.
         * @return
         */
        LoadingBay deliveryArrive();

        /**
         * Start delivering
         * @param truckId
         * @param truckCapacity
         * @param loadingBay
         * @return true, when it is complete.
         */
        bool startDelivery(int truckId, int truckCapacity, LoadingBay loadingBay);

        /**
         * Poll the next instruction to the bot.
         * @param botLocation
         * @return
         */
        BotInstruction botPollInstruction(Location botLocation);

    };
}


#endif //AMAZOOM_WAREHOUSE_SIMULATION_CENTRALCONTROLLER_H
