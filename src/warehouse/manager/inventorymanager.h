#ifndef AMAZOOM_WAREHOUSE_SIMULATION_INVENTORYMANAGER_H
#define AMAZOOM_WAREHOUSE_SIMULATION_INVENTORYMANAGER_H

#include <map>
#include <vector>
#include <mutex>

namespace warehouse {
    class InventoryManager {
    private:
        const std::map<int, warehouse::Merchandise> merchandiseCatalog; //<merchId, Merchandise>
        const std::map<int, int> targetMerchandiseQuantity; //<merchId, quantity>
        std::map<const int, std::vector<warehouse::ShelfSpace>> availableMerchandiseShelfSpaceMap; //<merchId, shelfSpaces

        std::mutex inventoryMangerMutex;

    public:
        InventoryManager(std::vector<warehouse::ShelfSpace> shelfSpaces, std::string catalogFileName, std::string carryMerchandiseFileName);

        /**
         * return if a merchandise has a minimum of quantity
         * @param merchandiseId
         * @param quantity
         * @return
         */
        bool available(const int merchandiseId, const int quantity);

        /**
         * Push the shelfspace for an available merchandise
         * @param merchandiseId
         * @param shelfSpace
         * @return
         */
        bool pushAvailableMerchandise(const int merchandiseId, const warehouse::ShelfSpace shelfSpace);

        /**
         * Pop the shelfspace for an available merchandise
         * @post the shelfspace will be removed from the manager. (erased)
         * @param merchandiseId
         * @return
         */
        warehouse::ShelfSpace popAvailableMerchandise(const int merchandiseId);

        /**
         * Get a map of low stocks items
         * @return <warehouse::Merchandise, int> = <Merchandise, quantity to restock>
         */
        std::map<warehouse::Merchandise, int> getLowStockItems();

        /**
         * get merchandise by id
         * @param id
         * @return
         */
        warehouse::Merchandise getMerchandiseById(const int id);

    };
}


#endif //AMAZOOM_WAREHOUSE_SIMULATION_INVENTORYMANAGER_H
