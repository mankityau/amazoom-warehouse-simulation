#include <map>

#include "spacemanager.h"
#include "space.cpp"
#include "itemspace.cpp"
#include "realityexception.h"

//TODO: Unit test this module
namespace reality{
    SpaceManager::SpaceManager(std::string id, Location dimension){
        if (dimension.equal({0,0,0})){
            throw reality::ZeroDimensionException();
        } else if (dimension.getX() * dimension.getY() * dimension.getZ() > MAX_SPACE_CAPACITY) {
            throw reality::TooBigDimensionException();
        }
        initSpace(id, dimension);
        initItemSpace(id);
    }

    Item* SpaceManager::getItemsSnapShot(){
        return itemSpace->get()->getItemsSnapShot();
    };

    bool SpaceManager::putItem(Item item) {
        bool put = this->itemSpace->get()->putItem(item);
        if (put && item.isOccupySpace()) {
            this->space->get()->updateOccupyStatus(item.getCurrentLocation(), item.getDeltaLocation(), true);
        }
        return put;
    }

    bool SpaceManager::removeItem(Item item) {
        bool removed = this->itemSpace->get()->removeItem(item);
        if (removed && item.isOccupySpace()) {
            this->space->get()->updateOccupyStatus(item.getCurrentLocation(), item.getDeltaLocation(), false);
        }
        return removed;
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

    Location SpaceManager::getSpaceDimension(){
        return this->space->get()->getDimension();
    }
}