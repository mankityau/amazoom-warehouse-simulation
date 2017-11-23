#ifndef AMAZOOM_WAREHOUSE_SIMULATION_SPACEMANAGER_H
#define AMAZOOM_WAREHOUSE_SIMULATION_SPACEMANAGER_H

#include <string>
#include <map>
#include "item.h"
#include "space.h"

namespace reality{
    class SpaceManager {
    private:
        Space *space;
        std::map<std::string, Item> items;

    public:
        SpaceManager(int x, int y, int z);
        bool putItem(Item item);
        bool removeItem(Item item);
        bool attemptMove(Item item, Location location);
    };
}


#endif //AMAZOOM_WAREHOUSE_SIMULATION_SPACEMANAGER_H
