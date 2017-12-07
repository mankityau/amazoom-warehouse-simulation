#ifndef AMAZOOM_WAREHOUSE_SIMULATION_CENTRALCONTROLLER_H
#define AMAZOOM_WAREHOUSE_SIMULATION_CENTRALCONTROLLER_H

#include <warehouse/manager/layoutmanager.h>
#include "warehouse/manager/inventorymanager.h"
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

    public:
        CentralController();
        NewOrderResponse newOrder(std::vector<int> merchandiseIds);

    };
}


#endif //AMAZOOM_WAREHOUSE_SIMULATION_CENTRALCONTROLLER_H
