#ifndef AMAZOOM_WAREHOUSE_SIMULATION_SPACEMANAGER_H
#define AMAZOOM_WAREHOUSE_SIMULATION_SPACEMANAGER_H

#include <string>
#include <map>
#include <cpen333/process/shared_memory.h>
#include "item.h"
#include "space.h"
#include "itemspace.h"

namespace reality{
    class SpaceManager {
    private:
        std::string id;
        cpen333::process::shared_object<Space> *space;
        cpen333::process::shared_object<ItemSpace> *itemSpace;

        bool initSpace(std::string spaceId, Location dimension);
        bool initItemSpace(std::string spaceId);

    public:
        SpaceManager(std::string id, Location dimension);
        bool putItem(Item item);
        bool removeItem(Item item);
        bool updateLocation(Item& item, Location location);
    };
}


#endif //AMAZOOM_WAREHOUSE_SIMULATION_SPACEMANAGER_H
