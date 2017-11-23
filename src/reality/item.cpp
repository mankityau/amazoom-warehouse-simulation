#include "item.h"
#include "location.cpp"

namespace reality{
    Item::Item(std::string id, Location initLocation, Location deltaLocation, char symbol) : currentLocation(initLocation) , deltaLocation(deltaLocation){
        this->id = id;
        this->symbol = symbol;
    }

    Item::Item(std::string id, Location initLocation, char symbol) : Item(id, initLocation, {0,0,0}, symbol){};

    std::string Item::getId(){
        return id;
    }
}