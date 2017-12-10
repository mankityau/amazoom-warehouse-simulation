#include "ordermanager.h"

namespace warehouse{
    OrderManager::OrderManager() {
    }

    int OrderManager::newOrder() {
        {
            std::lock_guard<std::mutex> lock(orderManagerMutex);
            int orderId = nextOrderId;
            orderStatusMap.insert({orderId, PENDING});
            orderIdCapacityMap.insert({orderId, 0});
            orderIdShelfSpaceMap.insert({orderId,{}});
            orderIdMerchandisesMap.insert({orderId,{}});
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
            orderIdCapacityMap.erase(orderId);
            orderIdShelfSpaceMap.erase(orderId);
            orderIdMerchandisesMap.erase(orderId);
        }
    }

    bool OrderManager::addMerchandise(int orderId, warehouse::Merchandise merchandise, warehouse::ShelfSpace shelfSpace) {
        {
            std::lock_guard<std::mutex> lock(orderManagerMutex);
            orderIdCapacityMap.at(orderId) += merchandise.weight;
            orderIdShelfSpaceMap.at(orderId).push_back(shelfSpace);
            orderIdMerchandisesMap.at(orderId).push_back(merchandise);
        }
    }
}
