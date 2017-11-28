#include "itemspace.h"
#include "item.cpp"

namespace reality{
    bool ItemSpace::emptyAll(){
        for (int i = 0; i < MAX_SPACE_CAPACITY; ++i) {
            items[i] = EMPTY_ITEM;
        }
        return true;
    }

    bool ItemSpace::putItem(Item item) {
        for (int i = 0; i < MAX_SPACE_CAPACITY; ++i) {
            if (item.equal(items[i])) {
                return false;
            } else if (EMPTY_ITEM.equal(items[i])) {
                items[i] = item;
                return true;
            }
        }
        return false;
    }

    bool ItemSpace::removeItem(Item item){
        for (int i = 0; i < MAX_SPACE_CAPACITY; ++i) {
            if (item.equal(items[i])) {
                items[i] = EMPTY_ITEM;
                return true;
            }
        }

        return false;
    };

    bool ItemSpace::updateItemLocation(Item& item, Location newLocation) {
        for (int i = 0; i < MAX_SPACE_CAPACITY; ++i) {
            if (item.equal(items[i])) {
                item.setCurrentLocation(newLocation);
                items[i] = item;
                return true;
            }
        }

        return false;
    }

    bool ItemSpace::setId(std::string id) {
        this->id = id;
        return true;
    }

    std::string ItemSpace::getId(){
        return this->id;
    }

    Item* ItemSpace::getItemsSnapShot(){
        Item* temp = {this->items};
        return temp;
    };
}