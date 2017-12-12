#ifndef AMAZOOM_WAREHOUSE_SIMULATION_DELIVERYMANAGER_H
#define AMAZOOM_WAREHOUSE_SIMULATION_DELIVERYMANAGER_H

#include <map>
#include <vector>

namespace warehouse {
    class DeliveryManager {
    private:
        std::map<int,std::vector<int>> truckIdOrderIdsMap;
    public:
        /**
         * start delivery
         * @param truckId
         * @return
         */
        bool startDelivery(int truckId);

        /**
         *
         * @param truckId
         * @param orderId
         * @return
         */
        bool pushOrderId(int truckId, int orderId);
    };
}


#endif //AMAZOOM_WAREHOUSE_SIMULATION_DELIVERYMANAGER_H
