#ifndef AMAZOOM_WAREHOUSE_SIMULATION_COMMON_H
#define AMAZOOM_WAREHOUSE_SIMULATION_COMMON_H

#include <string>
#include <tuple>

namespace warehouse {
    struct LoadingBay{
        const int id;
    };

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

        bool operator<(const ShelfSpace& other) const {
            return std::tie(shelfId, row, col, maxWeightCapacity)
                   < std::tie(other.shelfId, other.row, other.col, other.maxWeightCapacity);
        }
    };

    struct Merchandise{
        const int id;
        const std::string name;
        const int weight;

        bool operator<(const Merchandise& other) const {
            return std::tie(id, name, weight)
                   < std::tie(other.id, other.name, other.weight);
        }
    };
}
#endif //AMAZOOM_WAREHOUSE_SIMULATION_COMMON_H
