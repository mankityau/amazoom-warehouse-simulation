#ifndef AMAZOOM_WAREHOUSE_SIMULATION_SPACEMANAGER_H
#define AMAZOOM_WAREHOUSE_SIMULATION_SPACEMANAGER_H

#include <string>
#include <map>
#include <cpen333/process/shared_memory.h>
#include "item.h"
#include "space.h"

namespace reality{
    class SpaceManager {
    private:
        std::string spaceId;
        cpen333::process::shared_object<Space> *space;
        std::map<std::string, Item> items;

    public:
        SpaceManager(std::string spaceId);
        bool putItem(Item item);
        bool removeItem(Item item);
        bool attemptMove(Item item, Location location);
    };
}


#endif //AMAZOOM_WAREHOUSE_SIMULATION_SPACEMANAGER_H
