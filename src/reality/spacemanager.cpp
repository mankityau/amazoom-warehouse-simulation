#include <map>

#include "spacemanager.h"
#include "space.cpp"
#include "itemspace.cpp"

//TODO: Unit test this module
namespace reality{
    SpaceManager::SpaceManager(std::string id, Location dimension){
        initSpace(id, dimension);
        initItemSpace(id);
    }

    bool SpaceManager::putItem(Item item) {
        bool put = this->itemSpace->get()->putItem(item);
        if (put && item.isOccupySpace()) {
            this->space->get()->occupySpace(item.getCurrentLocation(), item.getDeltaLocation());
        }
        return put;
    }

    bool SpaceManager::removeItem(Item item) {
        return this->itemSpace->get()->removeItem(item);
    }

    bool SpaceManager::updateLocation(Item& item, Location location) {
        return this->itemSpace->get()->updateItemLocation(item, location);
    }

    bool SpaceManager::initSpace(std::string id, Location dimension) {
        this->space = new cpen333::process::shared_object<Space>("SPACE_" +id); //TODO: refactor "SPACE_" out maybe?
        if(this->space->get()->getId() != id){
            this->space->get()->initSpace(id, dimension);
        }

        return true;
    }

    bool SpaceManager::initItemSpace(std::string id) {
        this->itemSpace = new cpen333::process::shared_object<ItemSpace>("ITEMSPACE_" + id); //TODO: refactor "ITEMSPACE_" out maybe?
        if (this->itemSpace->get()->getId() != id){
            this->itemSpace->get()->emptyAll();
        }

        return true;
    }
}