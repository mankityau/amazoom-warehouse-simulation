#ifndef AMAZOOM_WAREHOUSE_SIMULATION_LOCATION_H
#define AMAZOOM_WAREHOUSE_SIMULATION_LOCATION_H

namespace reality{
    class Location {
    private:
        int x;
        int y;
        int z;
        bool occupied;
    public:
        Location();
        Location(int x, int y, int z);
        bool equal(Location other);
        bool isOccupied();
        int getX();
        int getY();
        int getZ();
    };
}


#endif //AMAZOOM_WAREHOUSE_SIMULATION_LOCATION_H
