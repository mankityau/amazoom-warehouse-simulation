#ifndef AMAZOOM_WAREHOUSE_SIMULATION_ITEM_H
#define AMAZOOM_WAREHOUSE_SIMULATION_ITEM_H

#include <string>
#include "location.h"

namespace reality{
    class Item {
    private:
        std::string id;
        Location currentLocation;
        Location deltaLocation;
        char symbol;
    public:
        Item(std::string id, Location initLocation, char symbol);
        Item(std::string id, Location initLocation, Location deltaLocation, char symbol);
        std::string getId();
    };
}


#endif //AMAZOOM_WAREHOUSE_SIMULATION_ITEM_H
