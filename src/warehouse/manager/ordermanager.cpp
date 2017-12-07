#include "ordermanager.h"

namespace warehouse{
    OrderManager::OrderManager() {
    }

    int OrderManager::newOrder() {
        {
            std::lock_guard<std::mutex> lock(orderManagerMutex);
            int orderId = nextOrderId;
            orderStatusMap.insert({nextOrderId, PENDING});
            ++nextOrderId;
            return orderId;
        }
    }

    bool OrderManager::updateOrderStatus(int orderId, OrderStatus orderStatus) {
        {
            std::lock_guard<std::mutex> lock(orderManagerMutex);
            orderStatusMap[orderId] = orderStatus;
        }
    }

    bool OrderManager::removeOrder(int orderId) {
        {
            std::lock_guard<std::mutex> lock(orderManagerMutex);
            orderStatusMap.erase(orderId);
        }
    }
}
