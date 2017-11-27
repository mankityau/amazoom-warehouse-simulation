#include <map>

#include "spacemanager.h"
#include "space.cpp"
#include "item.cpp"

//TODO: Unit test this module
namespace reality{
    SpaceManager::SpaceManager(std::string spaceId){
        this->space = new cpen333::process::shared_object<Space>(spaceId);
        if(this->space->get()->getId() == spaceId){
            std::cout << "SPACE ALREADY EXIST";
        } else {
            this->space->get()->setId(spaceId);
        }
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