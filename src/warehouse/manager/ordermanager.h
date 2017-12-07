#ifndef AMAZOOM_WAREHOUSE_SIMULATION_ORDERMANAGER_H
#define AMAZOOM_WAREHOUSE_SIMULATION_ORDERMANAGER_H

#include <mutex>
#include <map>

namespace warehouse {
    enum OrderStatus {
        PENDING,
        PACKAGING,
        DELIVERING
    };

    class OrderManager {
    private:
        std::mutex orderManagerMutex;
        std::map<int, OrderStatus> orderStatusMap;
        int nextOrderId = 0;
    public:
        /**
         * Constructor
         */
        OrderManager();

        /**
         * Create new order, order status will be set to pending
         * @return orderId
         */
        int newOrder();

        /**
         * Update the order status
         * @param orderId
         * @return
         */
        bool updateOrderStatus(int orderId, OrderStatus orderStatus);

        /**
         * remove the order
         * @param orderId
         * @return
         */
        bool removeOrder(int orderId);
    };
}


#endif //AMAZOOM_WAREHOUSE_SIMULATION_ORDERMANAGER_H
