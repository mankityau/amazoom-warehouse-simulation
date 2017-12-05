#ifndef AMAZOOM_WAREHOUSE_SIMULATION_COMMON_H
#define AMAZOOM_WAREHOUSE_SIMULATION_COMMON_H

#include <string>

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

    struct Merchandise{
        const int id;
        const std::string name;
        const int weight;
    };
}
#endif //AMAZOOM_WAREHOUSE_SIMULATION_COMMON_H
