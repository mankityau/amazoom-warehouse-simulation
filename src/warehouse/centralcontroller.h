#ifndef AMAZOOM_WAREHOUSE_SIMULATION_CENTRALCONTROLLER_H
#define AMAZOOM_WAREHOUSE_SIMULATION_CENTRALCONTROLLER_H

#include <warehouse/manager/layoutmanager.h>
#include "warehouse/manager/inventorymanager.h"

namespace warehouse {
    class CentralController {
    private:
        LayoutManager layoutManager;
        InventoryManager inventoryManager;

    public:
        CentralController();

    };
}


#endif //AMAZOOM_WAREHOUSE_SIMULATION_CENTRALCONTROLLER_H
