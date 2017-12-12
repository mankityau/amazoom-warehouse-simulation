#ifndef AMAZOOM_WAREHOUSE_SIMULATION_SHELFSPACEMANAGER_H
#define AMAZOOM_WAREHOUSE_SIMULATION_SHELFSPACEMANAGER_H

#include <map>
#include <vector>
namespace warehouse {
    class ShelfSpaceManager {
    private:
        std::map<const warehouse::ShelfSpace, int> shelfSpaceRemainCapacityMap; //<ShelfSpace, remainCapacity>
        void log(std::string msg);
    public:
        ShelfSpaceManager(const std::vector<warehouse::ShelfSpace> shelfSpaces);

        /**
         * Fill the shelfspace with certain capacity, deducing it
         * @param shelfSpace
         * @param capacity
         * @return
         */
        bool fill(const warehouse::ShelfSpace shelfSpace, int capacity);

        /**
         * Free the shelfspace with certain capacity, deducing it
         * @param shelfSpace
         * @param capacity
         * @return
         */
        bool free(const warehouse::ShelfSpace shelfSpace, int capacity);

        warehouse::ShelfSpace findAvailable(int capacity);
    };
}


#endif //AMAZOOM_WAREHOUSE_SIMULATION_SHELFSPACEMANAGER_H
