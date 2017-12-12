#include "deliverymanager.h"

namespace warehouse {
    bool DeliveryManager::startDelivery(int truckId) {
        truckIdOrderIdsMap.insert({truckId, {}});
    }


    bool DeliveryManager::pushOrderId(int truckId, int orderId){
        truckIdOrderIdsMap.at(truckId).push_back(orderId);
    };

}