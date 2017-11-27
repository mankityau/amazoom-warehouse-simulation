#include "space.h"

namespace reality{
    int getArrayIndex(int x, int y, int z){
        return z * ( x * y) + y * x + x;
    }

    bool validOccupySpace(Location location, Location dimension, Location maxDimension){
        return ((location.getX() + dimension.getX() <= maxDimension.getX()) &&
                (location.getY() + dimension.getY() <= maxDimension.getY()) &&
                (location.getZ() + dimension.getZ() <= maxDimension.getZ()));
    }

    bool Space::initSpace(std::string id, Location dimension) {
        this->id = id;
        this->dimension = dimension;
        for (int x = 0; x < dimension.getX(); ++x) {
            for (int y = 0; y < dimension.getY(); ++y) {
                for (int z = 0; z < dimension.getZ(); ++z){
                    this->locations[getArrayIndex(x, y, z)] = {x,y,z};
                }
            }
        }
    }

    bool Space::occupySpace(Location location, Location dimension){
        if (validOccupySpace(location, dimension, this->dimension)) {
            for (int x = location.getX(); x < dimension.getX(); ++ x) {
                for (int y = location.getY(); y < dimension.getY(); ++ y) {
                    for (int z = location.getZ(); z < dimension.getZ(); ++ z){
                        int arrayIndex = getArrayIndex(x, y, z);
                        if (this->locations[arrayIndex].isOccupied()) {
                            std::cout << "THIS SPACE IS OCCUPIED"; //TODO throw exception here
                        } else {
                            this->locations[getArrayIndex(x, y, z)].setOccupy(true);
                        }
                    }
                }
            }
        }
        return false;
    }

    bool Space::isOccupied(Location location){
        return this->locations[getArrayIndex(location.getX(), location.getZ(), location.getZ())].isOccupied();
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