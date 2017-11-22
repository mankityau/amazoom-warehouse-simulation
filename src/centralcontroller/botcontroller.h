#ifndef AMAZOOM_WAREHOUSE_SIMULATION_BOTCONTROLLER_H
#define AMAZOOM_WAREHOUSE_SIMULATION_BOTCONTROLLER_H

#include "../common/location.h"


namespace centralcontroller{
    class Botcontroller {
        virtual void pickUpOrder(int orderIt, int itemId, Location location) = 0;
    };
}
#endif //AMAZOOM_WAREHOUSE_SIMULATION_BOTCONTROLLER_H
