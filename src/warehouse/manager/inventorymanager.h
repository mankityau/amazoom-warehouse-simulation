#ifndef AMAZOOM_WAREHOUSE_SIMULATION_INVENTORYMANAGER_H
#define AMAZOOM_WAREHOUSE_SIMULATION_INVENTORYMANAGER_H

#include <map>

namespace warehouse {
    class InventoryManager {
    private:
        std::map<int, warehouse::Merchandise> merchandiseCatalog;
        std::map<int, int> targetMerchandiseQuantity;
    public:
        InventoryManager(std::string catalogFileName, std::string carryMerchandiseFileName);
    };
}


#endif //AMAZOOM_WAREHOUSE_SIMULATION_INVENTORYMANAGER_H
