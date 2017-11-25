#include "item.h"
#include "location.cpp"

namespace reality{
    Item::Item(std::string id, Location initLocation, Location deltaLocation, char symbol, bool occupySpace)
            : currentLocation(initLocation) , deltaLocation(deltaLocation){
        this->id = id;
        this->symbol = symbol;
        this->occupySpace = occupySpace;
    }

    Item::Item(std::string id, Location initLocation, char symbol)
            : Item(id, initLocation, {0,0,0}, symbol, true){};

    Item::Item(std::string id, Location initLocation, char symbol, bool occupySpace)
            : Item(id, initLocation, {0,0,0}, symbol, occupySpace){};

    std::string Item::getId(){
        return id;
    }
}