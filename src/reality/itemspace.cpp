#include "itemspace.h"
#include "item.cpp"

namespace reality{
    bool ItemSpace::emptyAll(){
        for (auto it = items.begin(); it != items.end(); ++it){
            *it = EMPTY_ITEM;
        }
        return true;
    }

    bool ItemSpace::putItem(Item item) {
        for (int i = 0; i < items.size(); ++i) {
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
        for (int i = 0; i < items.size(); ++i) {
            if (item.equal(items[i])) {
                items[i] = EMPTY_ITEM;
                return true;
            }
        }

        return false;
    };

    bool ItemSpace::setId(std::string id) {
        this->id = id;
        return true;
    }

    std::string ItemSpace::getId(){
        return this->id;
    }
}