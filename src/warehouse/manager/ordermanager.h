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
        std::map<int, int> orderIdCapacityMap;
        std::map<int, std::vector<warehouse::ShelfSpace>> orderIdShelfSpaceMap;
        std::map<int, std::vector<warehouse::Merchandise>> orderIdMerchandisesMap;
        int nextOrderId = 0;
    public:
        const int POISON_ORDER_ID = -1;

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

        /**
         * add a pending delivery merchandise, and shelfSpace to a orderId
         * @param orderId
         * @param merchandise
         * @param shelfSpace
         * @return
         */
        bool addMerchandise(int orderId, warehouse::Merchandise merchandise, warehouse::ShelfSpace shelfSpace);

        /**
         * find an order to delivery base on the max capacity the deliver can handle
         * @param capacity
         * @return order id to deliver, POISON_ORDER_ID if nothing to deliver
         */
        int findToDeliver(int capacity);

        /**
         * return the capacity of an order
         * @param orderId
         * @return
         */
        int orderCapacity(int orderId);

        /**
         * return the number of merchandise in an order
         * @param orderId
         * @return
         */
        int numOfMerchandise(int orderId);

        /**
         * return the merchandise of an orderId, and index
         * @param orderId
         * @param index
         * @return
         */
        warehouse::Merchandise merchandiseAt(int orderId, int index);

        /**
         * return the shelfspace of an orderId, and index
         * @param orderId
         * @param index
         * @return
         */
        warehouse::ShelfSpace shelfSpaceAt(int orderId, int index);
    };
}


#endif //AMAZOOM_WAREHOUSE_SIMULATION_ORDERMANAGER_H
