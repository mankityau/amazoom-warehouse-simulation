#ifndef AMAZOOM_WAREHOUSE_SIMULATION_ITEMSPACE_H
#define AMAZOOM_WAREHOUSE_SIMULATION_ITEMSPACE_H

#include <array>
#include "item.h"

namespace reality{
    class ItemSpace {
    private:
        std::string id;
        std::array<Item, MAX_SPACE_CAPACITY> items;
    public:
        bool emptyAll();
        bool putItem(Item item);
        bool removeItem(Item item);
        bool setId(std::string id);
        bool updateItemLocation(Item& item, Location newLocation);
        std::string getId();
    };
}


#endif //AMAZOOM_WAREHOUSE_SIMULATION_ITEMSPACE_H
