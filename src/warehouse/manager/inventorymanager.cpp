#include "inventorymanager.h"

#define ID "id"
#define NAME "name"
#define WEIGHT "weight"
#define QUANTITY "quantity"

namespace warehouse {
    bool available(const std::map<int, int> *availableMerchandiseQuantity,
                   const std::map<int, int> *orderMerchandiseQuantity){
        for (std::map<int, int>::const_iterator it = orderMerchandiseQuantity->begin(); it != orderMerchandiseQuantity->end(); ++it){
            if (availableMerchandiseQuantity->at(it->first) < it->second) {
                return false;
            }
        }
        return true;
    }

    void reduceAvailable(std::map<int, int> *availableMerchandiseQuantity,
                         const std::map<int, int> *orderMerchandiseQuantity) {
        for (std::map<int, int>::const_iterator it = orderMerchandiseQuantity->begin(); it != orderMerchandiseQuantity->end(); ++it){
            availableMerchandiseQuantity->at(it->first) -= it->second;
        }
    }

    std::map<int, warehouse::Merchandise> loadMerchandiseCatalog(std::string catalogFileName) {
        std::map<int, warehouse::Merchandise> catalog;

        std::ifstream fin(catalogFileName);
        if (fin.is_open()) {
            JSON catalogJson;
            fin >> catalogJson;
            for (const auto &merchandiseJson : catalogJson) {
                warehouse::Merchandise merchandise = {merchandiseJson[ID], merchandiseJson[NAME], merchandiseJson[WEIGHT]};
                catalog.insert({merchandiseJson[ID], merchandise});
            }
            return catalog;
        }
        throw warehouse::InitManagerException();
    };

    std::map<int, int> loadTargetMerchandiseQuantity(std::string carryMerchandiseFileName) {
        std::map<int, int> targetMerchandiseQuantity;

        std::ifstream fin(carryMerchandiseFileName);
        if (fin.is_open()) {
            JSON carryMerchJson;
            fin >> carryMerchJson;
            for (const auto &merchandiseJson : carryMerchJson) {
                int id = merchandiseJson[ID];
                int quantity = merchandiseJson[QUANTITY];
                targetMerchandiseQuantity.insert({id, quantity});
            }
            return targetMerchandiseQuantity;
        }
        throw warehouse::InitManagerException();
    };

    InventoryManager::InventoryManager(std::vector<warehouse::ShelfSpace> shelfSpaces,
                                       std::string catalogFileName,
                                       std::string carryMerchandiseFileName) :
            shelfSpaces(shelfSpaces),
            merchandiseCatalog(loadMerchandiseCatalog(catalogFileName)) ,
            targetMerchandiseQuantity(loadTargetMerchandiseQuantity(carryMerchandiseFileName)),
            availableMerchandiseQuantity(targetMerchandiseQuantity),
            inStockMerchandiseQuantity(targetMerchandiseQuantity) {
    }

    bool InventoryManager::newOrder(const int orderId, const std::vector<int> merchandiseIds) {
        std::map<int, int> orderMerchandiseQuantity;
        for (std::vector<int>::const_iterator it = merchandiseIds.begin(); it != merchandiseIds.end(); ++it){
            if (orderMerchandiseQuantity.count(*it) == 0){
                orderMerchandiseQuantity[*it] = 1;
            } else {
                orderMerchandiseQuantity[*it] = orderMerchandiseQuantity[*it] + 1;
            }
        }
        {
            std::lock_guard<std::mutex> lock(inventoryMangerMutex);
            if (available(&availableMerchandiseQuantity, &orderMerchandiseQuantity)) {
                reduceAvailable(&availableMerchandiseQuantity, &orderMerchandiseQuantity);
                return true;
            } else {
                return false;
            }
        }

    }
}