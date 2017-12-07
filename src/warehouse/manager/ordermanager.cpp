#include "ordermanager.h"

namespace warehouse{
    OrderManager::OrderManager() {
    }

    int OrderManager::newOrder() {
        {
            std::unique_lock<std::mutex>(orderManagerMutex);
            int orderId = nextOrderId;
            orderStatusMap.insert({nextOrderId, PENDING});
            ++nextOrderId;
            return orderId;
        }
    }

    bool OrderManager::updateOrderStatus(int orderId, OrderStatus orderStatus) {
        {
            std::unique_lock<std::mutex>(orderManagerMutex);
            orderStatusMap[orderId] = orderStatus;
        }
    }

    bool OrderManager::removeOrder(int orderId) {
        {
            std::unique_lock<std::mutex>(orderManagerMutex);
            orderStatusMap.erase(orderId);
        }
    }
}
