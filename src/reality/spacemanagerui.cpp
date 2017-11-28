#include "spacemanagerui.h"
#include <thread>

namespace reality{
    int screenRow(int x, int y, int z, Location spaceDimension) {
        return y + z * spaceDimension.getY();
    }

    int screenCol(int x, int y, int z, Location spaceDimension){
        return x;
    }

    void displayItem(cpen333::console* display_,Item item, Location spaceDimension){
        Location itemCurrentLocation = item.getCurrentLocation();
        Location itemDimension = item.getDeltaLocation();
        for (int z = itemCurrentLocation.getZ(); z < itemCurrentLocation.getZ() + itemDimension.getZ(); ++ z){
            for (int y = itemCurrentLocation.getY(); y < itemCurrentLocation.getY() + itemDimension.getY(); ++ y){
                for (int x = itemCurrentLocation.getX(); x < itemCurrentLocation.getX() + itemDimension.getX(); ++ x){
                    display_->set_cursor_position(screenRow(x, y, z, spaceDimension),
                        screenCol(x,y ,z, spaceDimension));
                    std::printf("%c", item.getSymbol());
                };
            };
        }
    }

    void displayItems(cpen333::console* display_,Item items[], Location spaceDimension){
        for (int i = 0; i < MAX_SPACE_CAPACITY; ++i){
            if (!items[i].equal(EMPTY_ITEM)){
                displayItem(display_, items[i], spaceDimension);
            }
        }
    }

    SpaceManagerUI::SpaceManagerUI(SpaceManager spaceManager): display_(), spaceManager(spaceManager){
    }

    void SpaceManagerUI::display(){
        display_.set_cursor_visible(false);
        Location spaceDimension = spaceManager.getSpaceDimension();
        while(true){
            display_.clear_all();
            Item* item = spaceManager.getItemsSnapShot();
            displayItems(&display_, item, spaceDimension);
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        }
    }
}