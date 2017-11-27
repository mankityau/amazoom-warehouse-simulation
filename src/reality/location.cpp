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

    bool Location::equal(Location other) {
        return ((x == other.getX()) &&
                (y == other.getY()) &&
                (z == other.getZ()));
    };

    bool Location::isOccupied() {
        return this->occupied;
    }

    int Location::getX() {
        return this->x;
    };
    int Location::getY() {
        return this->y;
    };
    int Location::getZ() {
        return this->z;
    };
}