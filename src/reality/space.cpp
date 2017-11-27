#include "space.h"

namespace reality{
    bool Space::isOccupied(Location location){
        return this->locations[1].isOccupied();
    }

    bool Space::setId(std::string id){
        this->id = id;
        return true;
    }

    bool Space::setDimension(Location dimension){
        this->dimension = dimension;
        return true;
    };

    std::string Space::getId(){
        return this->id;
    }
}