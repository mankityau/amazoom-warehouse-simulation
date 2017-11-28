#ifndef AMAZOOM_WAREHOUSE_SIMULATION_SPACE_H
#define AMAZOOM_WAREHOUSE_SIMULATION_SPACE_H

#include <string>

#define MAX_SPACE_CAPACITY 500

namespace reality{
    class Space {
    private:
        std::string id;
        Location locations[MAX_SPACE_CAPACITY];
        Location dimension;
    public:
        bool initSpace(std::string id, Location dimension);

        bool updateOccupyStatus(Location location, Location dimension, bool occupyStatus);

        bool isOccupied(Location location);
        std::string getId();
        Location getDimension();

        bool setId(std::string id);
        bool setDimension(Location dimension);

    };
}


#endif //AMAZOOM_WAREHOUSE_SIMULATION_SPACE_H
