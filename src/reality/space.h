#ifndef AMAZOOM_WAREHOUSE_SIMULATION_SPACE_H
#define AMAZOOM_WAREHOUSE_SIMULATION_SPACE_H

#include <string>

#define MAX_SPACE_CAPACITY 200

namespace reality{
    class Space {
    private:
        std::string id;
        Location locations[MAX_SPACE_CAPACITY];
        Location dimension;
    public:
        bool initSpace(std::string id, Location dimension);

        bool occupySpace(Location location, Location dimension);

        bool isOccupied(Location location);
        std::string getId();

        bool setId(std::string id);
        bool setDimension(Location dimension);

    };
}


#endif //AMAZOOM_WAREHOUSE_SIMULATION_SPACE_H
