#ifndef AMAZOOM_WAREHOUSE_SIMULATION_CENTRALCONTROLLER_H
#define AMAZOOM_WAREHOUSE_SIMULATION_CENTRALCONTROLLER_H

#include "../common/CreateOrderResponse.h"

namespace centralcontroller{
    class CentralController {
    public:
        virtual common::CreateOrderResponse createOrder(int itemId) = 0;
    };
}

#endif //AMAZOOM_WAREHOUSE_SIMULATION_CENTRALCONTROLLER_H
