#include "item.h"
#include "location.cpp"

namespace reality{
    Item::Item(std::string id, Location initLocation, int deltaZ, char symbol) : currentLocation(initLocation){
        this->id = id;
        this->deltaZ = deltaZ;
        this->symbol = symbol;
    }

    std::string Item::getId(){
        return id;
    }
}