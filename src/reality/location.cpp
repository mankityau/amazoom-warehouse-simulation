#include "location.h"

namespace reality{
    Location::Location(int x, int y, int z) : Location(x, y, z, false) {};

    Location::Location(int x, int y, int z, bool occupied) {
        this->x = x;
        this->y = y;
        this->z = z;
        this->occupied = occupied;
    }

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

    bool Location::setOccupy(bool occupy) {
        this->occupied = occupy;
        return true;
    };
}