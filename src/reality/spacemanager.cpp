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
        return this->itemSpace->get()->putItem(item);
    }

    bool SpaceManager::removeItem(Item item) {
        return this->itemSpace->get()->removeItem(item);
    }

    bool SpaceManager::attemptMove(Item item, Location location) {
        //TODO : finish implementation.
        return false;
    }

    bool SpaceManager::initSpace(std::string id, Location dimension) {
        this->space = new cpen333::process::shared_object<Space>("SPACE_" +id); //TODO: refactor "SPACE_" out maybe?
        if(this->space->get()->getId() != id){
            this->space->get()->setId(id);
            this->space->get()->setDimension(dimension);
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