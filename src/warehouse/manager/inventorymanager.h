#ifndef AMAZOOM_WAREHOUSE_SIMULATION_INVENTORYMANAGER_H
#define AMAZOOM_WAREHOUSE_SIMULATION_INVENTORYMANAGER_H

#include <map>
#include <mutex>

namespace warehouse {
    class InventoryManager {
    private:
        const std::map<int, warehouse::Merchandise> merchandiseCatalog;
        const std::map<int, int> targetMerchandiseQuantity;
        const std::vector<warehouse::ShelfSpace> shelfSpaces;
        std::mutex inventoryMangerMutex;
        std::map<int, int> availableMerchandiseQuantity;
        std::map<int, int> inStockMerchandiseQuantity;
    public:
        InventoryManager(std::vector<warehouse::ShelfSpace> shelfSpaces, std::string catalogFileName, std::string carryMerchandiseFileName);

        /**
         * check if new order is possible
         * @param merchandiseIds
         * @return
         */
        bool newOrder(const int orderId, const std::vector<int> merchandiseIds);
    };
}


#endif //AMAZOOM_WAREHOUSE_SIMULATION_INVENTORYMANAGER_H
