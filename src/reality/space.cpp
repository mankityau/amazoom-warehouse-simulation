#include "space.h"

namespace reality{
    Space::Space(Location deltaLocation){

    }

    bool Space::isOccupied(Location location){
        return this->locations[1].isOccupied();
    }
}