#ifndef AMAZOOM_WAREHOUSE_SIMULATION_LAYOUTMANAGER_H
#define AMAZOOM_WAREHOUSE_SIMULATION_LAYOUTMANAGER_H

#include <iostream>
#include <vector>
#include "common.h"

namespace warehouse {
    class LayoutManager {
    private:
        const warehouse::Dimension dimension;
        const std::vector<warehouse::ShelfSpace> shelfSpaces;
    public:
        LayoutManager(std::string fileName);
        std::vector<warehouse::ShelfSpace> getShelfSpaces();
    };
}


#endif //AMAZOOM_WAREHOUSE_SIMULATION_LAYOUTMANAGER_H
