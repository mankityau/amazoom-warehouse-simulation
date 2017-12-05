#ifndef AMAZOOM_WAREHOUSE_SIMULATION_COMMON_H
#define AMAZOOM_WAREHOUSE_SIMULATION_COMMON_H

namespace warehouse {
    struct Dimension{
        const int x;
        const int y;
        const int z;
    };

    struct ShelfSpace{
        const int shelfId;
        const int maxWeightCapacity;
        const int row;
        const int col;
    };
}
#endif //AMAZOOM_WAREHOUSE_SIMULATION_COMMON_H
