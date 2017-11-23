#include <map>

#include "spacemanager.h"
#include "space.cpp"
#include "item.cpp"

//TODO: Unit test this module
namespace reality{
    SpaceManager::SpaceManager(int x, int y, int z) {
        this->space = new Space(x, y, z);
    }

    bool SpaceManager::putItem(Item item) {
        if (this->items.count(item.getId()) >= 1){
            return false;
        }
        this->items.insert({item.getId(), item});
        return true;
    }

    bool SpaceManager::removeItem(Item item) {
        if (this->items.count(item.getId()) == 0){
            return false;
        }
        this->items.erase(item.getId());
        return true;
    }

    bool SpaceManager::attemptMove(Item item, Location location) {
        //TODO : finish implementation.
        return false;
    }
}