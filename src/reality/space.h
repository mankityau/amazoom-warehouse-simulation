#ifndef AMAZOOM_WAREHOUSE_SIMULATION_SPACE_H
#define AMAZOOM_WAREHOUSE_SIMULATION_SPACE_H

#include <string>

#define MAX_SPACE_CAPACITY 100

namespace reality{
    class Space {
    private:
        std::string id;
        Location locations[MAX_SPACE_CAPACITY];
    public:
        Space(Location deltaLocation);
        bool isOccupied(Location location);
        std::string getId();
        bool setId(std::string id);
    };
}


#endif //AMAZOOM_WAREHOUSE_SIMULATION_SPACE_H
