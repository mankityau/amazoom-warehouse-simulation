#ifndef AMAZOOM_WAREHOUSE_SIMULATION_ITEM_H
#define AMAZOOM_WAREHOUSE_SIMULATION_ITEM_H

#include <string>
#include "location.h"


#define EMPTY_ITEM_ID "ITEM_SPACE_EMPTY_ITEM_IT"
#define EMPTY_ITEM_CHAR ' '


namespace reality{
    class Item {
    private:
        std::string id;
        Location currentLocation;
        Location deltaLocation;
        char symbol;
        bool occupySpace;
    public:
        Item operator=(Item& item){
            id = item.getId();
            currentLocation = item.getCurrentLocation();
            deltaLocation = item.getDeltaLocation();
            symbol = item.symbol;
            occupySpace = item.occupySpace;
            return *this;
        }

        Item(std::string id, Location initLocation, char symbol);
        Item(std::string id, Location initLocation, char symbol, bool occupySpace);
        Item(std::string id, Location initLocation, Location deltaLocation, char symbol, bool occupySpace);

        bool equal(Item& other);

        std::string getId();
        Location getCurrentLocation();
        Location getDeltaLocation();
        char getSymbol();
        bool isOccupySpace();

        bool setCurrentLocation(Location location);
    };

    Item EMPTY_ITEM = {EMPTY_ITEM_ID, {0,0,0}, EMPTY_ITEM_CHAR};
}


#endif //AMAZOOM_WAREHOUSE_SIMULATION_ITEM_H
