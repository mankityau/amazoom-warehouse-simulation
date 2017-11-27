#ifndef AMAZOOM_WAREHOUSE_SIMULATION_SPACE_H
#define AMAZOOM_WAREHOUSE_SIMULATION_SPACE_H

#include <string>

#define MAX_SPACE_CAPACITY 100

namespace reality{
    class Space {
    private:
        std::string id;
        Location locations[MAX_SPACE_CAPACITY];
        Location dimension;
    public:
        bool isOccupied(Location location);
        bool setId(std::string id);
        bool setDimension(Location dimension);
        std::string getId();
    };
}


#endif //AMAZOOM_WAREHOUSE_SIMULATION_SPACE_H
