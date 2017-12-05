#include "inventorymanager.h"

#define ID "id"
#define NAME "name"
#define WEIGHT "weight"
#define QUANTITY "quantity"

namespace warehouse {
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

    InventoryManager::InventoryManager(std::string catalogFileName, std::string carryMerchandiseFileName) :
            merchandiseCatalog(loadMerchandiseCatalog(catalogFileName)) ,
            targetMerchandiseQuantity(loadTargetMerchandiseQuantity(carryMerchandiseFileName)){

    }
}