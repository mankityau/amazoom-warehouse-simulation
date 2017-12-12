#include "shelfspacemanager.h"

namespace warehouse {
    std::map<const warehouse::ShelfSpace, int> initShelfSpaceRemainCapacityMap(const std::vector<warehouse::ShelfSpace> shelfSpaces) {
        std::map<const warehouse::ShelfSpace, int> map;
        for (std::vector<warehouse::ShelfSpace>::const_iterator it = shelfSpaces.begin(); it != shelfSpaces.end(); ++it){
            map.insert({{*it}, it->maxWeightCapacity});
        }
        return map;
    }

    ShelfSpaceManager::ShelfSpaceManager(const std::vector<warehouse::ShelfSpace> shelfSpaces) :
            shelfSpaceRemainCapacityMap(initShelfSpaceRemainCapacityMap(shelfSpaces)){
    }

    void ShelfSpaceManager::log(std::string msg){
        std::cout << "ShelfSpaceManager: " << msg << std::endl;
    }

    bool ShelfSpaceManager::fill(const warehouse::ShelfSpace shelfSpace, int capacity) {
        shelfSpaceRemainCapacityMap.at(shelfSpace) -= capacity;
    }

    bool ShelfSpaceManager::free(const warehouse::ShelfSpace shelfSpace, int capacity) {
        shelfSpaceRemainCapacityMap.at(shelfSpace) += capacity;
        log("Freed " + toString(shelfSpace) + "Capacity: " + std::to_string(capacity));
    }

    warehouse::ShelfSpace ShelfSpaceManager::findAvailable(int capacity) {
        for (std::map<const warehouse::ShelfSpace, int>::iterator it = shelfSpaceRemainCapacityMap.begin();
                it != shelfSpaceRemainCapacityMap.end();
                ++it){
            if (it->second >= capacity){
                return it->first;
            }
        }
    }
}