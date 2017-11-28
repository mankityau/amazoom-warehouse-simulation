#ifndef AMAZOOM_WAREHOUSE_SIMULATION_SPACEMANAGERUI_H
#define AMAZOOM_WAREHOUSE_SIMULATION_SPACEMANAGERUI_H

#include "spacemanager.h"
#include <cpen333/console.h>

namespace reality{
    class SpaceManagerUI {
        SpaceManager spaceManager;
        cpen333::console display_;

    public:
        SpaceManagerUI(SpaceManager spaceManager);
        void display();

    };
};


#endif //AMAZOOM_WAREHOUSE_SIMULATION_SPACEMANAGERUI_H
