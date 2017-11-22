#ifndef AMAZOOM_WAREHOUSE_SIMULATION_STOCKCONTROLLER_H
#define AMAZOOM_WAREHOUSE_SIMULATION_STOCKCONTROLLER_H

#include "../common/location.h"

namespace centralcontroller {
    class StockController {
    public:
        struct reserveResponse {
            Location location;
            bool success;
        };

        virtual reserveResponse tryReserve(int itemId, int orderId) = 0;
    };
}

#endif //AMAZOOM_WAREHOUSE_SIMULATION_STOCKCONTROLLER_H
