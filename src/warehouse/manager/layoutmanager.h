#ifndef AMAZOOM_WAREHOUSE_SIMULATION_LAYOUTMANAGER_H
#define AMAZOOM_WAREHOUSE_SIMULATION_LAYOUTMANAGER_H

#include <iostream>
#include <vector>
#include "common.h"
#include <cpen333/thread/semaphore.h>

namespace warehouse {
    class LayoutManager {
    private:
        const warehouse::Dimension dimension;
        const std::vector<warehouse::ShelfSpace> shelfSpaces;
        const std::vector<warehouse::LoadingBay> loadingBays;
        std::vector<warehouse::LoadingBay> freeLoadingBays;
        cpen333::thread::semaphore freeLoadingBaySemaphore;
    public:
        LayoutManager(std::string fileName);
        std::vector<warehouse::ShelfSpace> getShelfSpaces();

        /**
         * Return a loading bay once one is ready.
         * @return
         */
        LoadingBay truckArrive();

        /**
         * A truck is leaving a loadingBay
         * @param loadingBay
         * @return true if leave successfully.
         */
        bool truckLeave(warehouse::LoadingBay loadingBay);

        /**
         * Computer a path from location to shelf
         * @param location
         * @param shelfSpace
         * @return
         */
        Path pathToShelf(Location location, ShelfSpace shelfSpace);

        /**
         * Computer a path from a location to loadingBay
         * @param location
         * @param loadingBay
         * @return
         */
        Path pathToLoadingBay(Location location, LoadingBay loadingBay);
    };
}


#endif //AMAZOOM_WAREHOUSE_SIMULATION_LAYOUTMANAGER_H
