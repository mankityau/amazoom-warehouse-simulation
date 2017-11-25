#include "location.h"

namespace reality{
    Location::Location(int x, int y, int z) {
        this->x = x;
        this->y = y;
        this->z = z;
        this->occupied = false;
    };

    Location::Location(): Location(0,0,0){
    };

    bool Location::isOccupied() {
        return this->occupied;
    }
}