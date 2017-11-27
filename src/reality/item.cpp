#include "item.h"
#include "location.cpp"

namespace reality{
    Item::Item(std::string id, Location initLocation, Location deltaLocation, char symbol, bool occupySpace)
            : currentLocation(initLocation) , deltaLocation(deltaLocation), symbol(symbol), occupySpace(occupySpace){
        this->id = id;
    }

    Item::Item(std::string id, Location initLocation, char symbol)
            : Item(id, initLocation, {1,1,1}, symbol, true){};

    Item::Item(std::string id, Location initLocation, char symbol, bool occupySpace)
            : Item(id, initLocation, {1,1,1}, symbol, occupySpace){};

    bool Item::equal(Item &other) {
        return ((id == other.getId()) &&
                currentLocation.equal(other.getCurrentLocation()) &&
                deltaLocation.equal(other.getDeltaLocation()) &&
                (symbol == other.getSymbol()) &&
                (occupySpace == other.occupySpace));
    }

    std::string Item::getId(){
        return id;
    }
    Location Item::getCurrentLocation() {
        return currentLocation;
    };
    Location Item::getDeltaLocation(){
        return deltaLocation;
    };
    char Item::getSymbol() {
        return symbol;
    };
    bool Item::getOccupySpace() {
        return occupySpace;
    };
}