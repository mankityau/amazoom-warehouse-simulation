#include "warehouse.h"
#include "reality/spacemanager.cpp"
#include "reality/spacemanagerui.cpp"

namespace warehouse{
    bool buildWall(reality::SpaceManager spaceManager, reality::Location dimension){
        int height = dimension.getZ();
        spaceManager.putItem({"TOP-WALL",
                              {0, 0, 0},
                              {dimension.getX(), 1, height},
                              'W',
                              true});

        spaceManager.putItem({"LEFT-WALL",
                              {0, 1, 0},
                              {1, dimension.getY() - 2, height},
                              'W',
                              true});

        spaceManager.putItem({"RIGHT-WALL",
                              {dimension.getX() - 1, 1, 0},
                              {1, dimension.getY() - 2, height},
                              'W',
                              true});

        spaceManager.putItem({"BOTTOM-WALL",
                              {0, dimension.getY() - 1, 0},
                              {dimension.getX(), 1, height},
                              'W',
                              true});
    }

    Warehouse::Warehouse() {
        std::string id = "FOO";
        reality::Location dimension = {10, 10, 5};
        reality::SpaceManager spaceManager(id, dimension);
        reality::Location d = spaceManager.getSpaceDimension();
        buildWall(spaceManager, dimension);
        reality::SpaceManagerUI spaceManagerUI(spaceManager);
        spaceManagerUI.display();

    }
}