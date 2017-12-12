#include "inventorymanager.h"

#define ID "id"
#define NAME "name"
#define WEIGHT "weight"
#define QUANTITY "quantity"

namespace warehouse {
    void InventoryManager::log(std::string msg) {
        std::cout << "Inventory Manager: " << msg << std::endl;
    };

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

    std::map<const int, std::vector<warehouse::ShelfSpace>> initAvailableMerchandiseShelfSpaceMap(std::map<int, int> targetMerchandiseQuantity) {
        std::map<const int, std::vector<warehouse::ShelfSpace>> availableMerchandiseShelfSpaceMap;
        for (std::map<int, int>::iterator it = targetMerchandiseQuantity.begin(); it != targetMerchandiseQuantity.end(); ++it){
            availableMerchandiseShelfSpaceMap.insert({it->first, {}});
        }

        return availableMerchandiseShelfSpaceMap;
    };

    InventoryManager::InventoryManager(std::vector<warehouse::ShelfSpace> shelfSpaces,
                                       std::string catalogFileName,
                                       std::string carryMerchandiseFileName) :
            merchandiseCatalog(loadMerchandiseCatalog(catalogFileName)) ,
            targetMerchandiseQuantity(loadTargetMerchandiseQuantity(carryMerchandiseFileName)) ,
            availableMerchandiseShelfSpaceMap(initAvailableMerchandiseShelfSpaceMap(targetMerchandiseQuantity)){
    }

    bool InventoryManager::available(const int merchandiseId, const int quantity){
        {
            std::lock_guard<std::mutex> lock(inventoryMangerMutex);
            log("Checking availablity, merchandiseId; " + std::to_string(merchandiseId) + ", quantity:"  + std::to_string(quantity));
            return availableMerchandiseShelfSpaceMap.at(merchandiseId).size() > quantity;
        }
    }


    bool InventoryManager::pushAvailableMerchandise(const int merchandiseId, const warehouse::ShelfSpace shelfSpace){
        {
            std::lock_guard<std::mutex> lock(inventoryMangerMutex);
            availableMerchandiseShelfSpaceMap.at(merchandiseId).push_back(shelfSpace);
            return true;
        }
    }


    warehouse::ShelfSpace InventoryManager::popAvailableMerchandise(const int merchandiseId) {
        {
            std::lock_guard<std::mutex> lock(inventoryMangerMutex);
            warehouse::ShelfSpace shelfSpace = availableMerchandiseShelfSpaceMap.at(merchandiseId).back();
            availableMerchandiseShelfSpaceMap.at(merchandiseId).pop_back();
            log("Poping available merchandise shelfSpace. MerchandiseId: " + std::to_string(merchandiseId) + " " + toString(shelfSpace));
            return shelfSpace;
        }
    };

    std::map<warehouse::Merchandise, int> InventoryManager::getLowStockItems() {
        {
            std::lock_guard<std::mutex> lock(inventoryMangerMutex);
            std::map<warehouse::Merchandise, int> map;
            for (std::map<const int, std::vector<warehouse::ShelfSpace>>::iterator it = availableMerchandiseShelfSpaceMap.begin();
                    it != availableMerchandiseShelfSpaceMap.end();
                    ++ it){
                int currentQuantity = it->second.size();
                int desiredQuantity = targetMerchandiseQuantity.at(it->first);
                if ( currentQuantity < desiredQuantity){
                    map.insert({merchandiseCatalog.at(it->first), desiredQuantity - currentQuantity});
                }
            }
            return map;
        }
    };

    warehouse::Merchandise InventoryManager::getMerchandiseById(const int id){
        return merchandiseCatalog.at(id);

    }
}