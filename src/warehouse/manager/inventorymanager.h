#ifndef AMAZOOM_WAREHOUSE_SIMULATION_INVENTORYMANAGER_H
#define AMAZOOM_WAREHOUSE_SIMULATION_INVENTORYMANAGER_H

#include <map>

namespace warehouse {
    class InventoryManager {
    private:
        const std::map<int, warehouse::Merchandise> merchandiseCatalog;
        const std::map<int, int> targetMerchandiseQuantity;
        const std::vector<warehouse::ShelfSpace> shelfSpaces;
    public:
        InventoryManager(std::vector<warehouse::ShelfSpace> shelfSpaces, std::string catalogFileName, std::string carryMerchandiseFileName);
    };
}


#endif //AMAZOOM_WAREHOUSE_SIMULATION_INVENTORYMANAGER_H
