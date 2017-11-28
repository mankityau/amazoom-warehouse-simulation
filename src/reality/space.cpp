#include "space.h"
#include "realityexception.h"

namespace reality{
    int getArrayIndex(Location location, Location dimension){
        return location.getZ() * dimension.getX() * dimension.getY() +
                location.getY() * dimension.getX() +
                location.getX();
    }

    bool validOccupySpace(Location location, Location dimension, Location maxDimension){
        return ((location.getX() + dimension.getX() <= maxDimension.getX()) &&
                (location.getY() + dimension.getY() <= maxDimension.getY()) &&
                (location.getZ() + dimension.getZ() <= maxDimension.getZ()));
    }

    bool Space::initSpace(std::string id, Location dimension) {
        this->id = id;
        this->dimension = dimension;
        for (int z = 0; z < dimension.getZ(); ++z) {
            for (int y = 0; y < dimension.getY(); ++y) {
                for (int x = 0; x < dimension.getX(); ++x){
                    this->locations[getArrayIndex({x, y, z}, this->dimension)] = {x,y,z};
                }
            }
        }
    }

    bool Space::updateOccupyStatus(Location location, Location dimension, bool occupyStatus){
        if (validOccupySpace(location, dimension, this->dimension)) {
            for (int z = location.getZ(); z < dimension.getZ(); ++ z) {
                for (int y = location.getY(); y < dimension.getY(); ++ y) {
                    for (int x = location.getX(); x < dimension.getX(); ++ x){
                        int arrayIndex = getArrayIndex({x, y, z}, this->dimension);
                        if (this->locations[arrayIndex].isOccupied() && occupyStatus) {
                            throw reality::SpaceOccupiedException();
                        } else {
                            this->locations[arrayIndex].setOccupy(occupyStatus);
                        }
                    }
                }
            }
        }
        return false;
    }

    bool Space::isOccupied(Location location){
        return this->locations[getArrayIndex(location, this->dimension)].isOccupied();
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

    Location Space::getDimension(){
        return this->dimension;
    };
}