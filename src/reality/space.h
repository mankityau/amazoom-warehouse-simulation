#ifndef AMAZOOM_WAREHOUSE_SIMULATION_SPACE_H
#define AMAZOOM_WAREHOUSE_SIMULATION_SPACE_H

#define MAX_SPACE_CAPACITY 100

namespace reality{
    class Space {
    private:
        Location locations[MAX_SPACE_CAPACITY];
    public:
        Space(Location deltaLocation);
        bool isOccupied(Location location);
    };
}


#endif //AMAZOOM_WAREHOUSE_SIMULATION_SPACE_H
