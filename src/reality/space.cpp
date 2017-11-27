#include "space.h"

namespace reality{
    Space::Space(Location deltaLocation){

    }

    bool Space::isOccupied(Location location){
        return this->locations[1].isOccupied();
    }

    bool Space::setId(std::string id){
        this->id = id;
        return true;
    }

    std::string Space::getId(){
        return this->id;
    }
}