#include "warehouse.h"
#include "reality/spacemanager.cpp"
#include "reality/spacemanagerui.cpp"


namespace warehouse{
    static const char WALL_SYMBOL = 219;
    static const char SHELVE_SYMBOL = 219;

    bool buildWall(reality::SpaceManager spaceManager, reality::Location dimension, int loadingBayCapacity){
        int height = dimension.getZ();
        spaceManager.putItem({"TOP-WALL",
                              {0, 0, 0},
                              {dimension.getX(), 1, height},
                              WALL_SYMBOL,
                              true});

        spaceManager.putItem({"LEFT-WALL",
                              {0, 1, 0},
                              {1, dimension.getY() - 2 - loadingBayCapacity, height},
                              WALL_SYMBOL,
                              true});

        spaceManager.putItem({"RIGHT-WALL",
                              {dimension.getX() - 1, 1, 0},
                              {1, dimension.getY() - 2, height},
                              WALL_SYMBOL,
                              true});

        spaceManager.putItem({"BOTTOM-WALL",
                              {0, dimension.getY() - 1, 0},
                              {dimension.getX(), 1, height},
                              WALL_SYMBOL,
                              true});
    }

    bool buildLoadingBay(reality::SpaceManager spaceManager, int loadingBayCapacity, reality::Location dimension){
        for (int i = 0; i < loadingBayCapacity; ++ i){
            spaceManager.putItem({"LOADINGBAY_" + i,
                                  {0, dimension.getY() - 2 - i, 0},
                                  {1, 1, dimension.getZ()},
                                  '0' + i,
                                  false
                                 });
        }
    }

    // TODO: Possible error when dimension.y is less than 4.
    // TODO: Possible error when dimension.x is less than 2.
    bool putShelves(reality::SpaceManager spaceManager, reality::Location dimension){
        reality::Location shelvesDimension = {1, dimension.getY()-4, 1};
        for (int x = 2; x < dimension.getX() - 1; ++x){
            if (x % 3 != 1){
                spaceManager.putItem({"SHELVE_" + x,
                                      {x, 2, 0},
                                      shelvesDimension,
                                      SHELVE_SYMBOL,
                                      true
                                     });
            }
        }
    };


    Warehouse::Warehouse() {
        std::string id = "FOO";
        reality::Location dimension = {10, 10, 5};
        int loadingBayCapacity = 2;
        reality::SpaceManager spaceManager(id, dimension);
        reality::Location d = spaceManager.getSpaceDimension();
        buildWall(spaceManager, dimension, loadingBayCapacity);
        buildLoadingBay(spaceManager, loadingBayCapacity, dimension);
        putShelves(spaceManager, dimension);

        reality::SpaceManagerUI spaceManagerUI(spaceManager);
        spaceManagerUI.display();

    }
}