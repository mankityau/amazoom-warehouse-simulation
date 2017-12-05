#include "layoutmanager.h"
#include "managerexception.h"
#include <fstream>
#include <json.hpp>

#define DIMENSION "dimension"
#define X "x"
#define Y "y"
#define Z "z"

#define SHELF_PROPERTY "shelfProperty"
#define MAX_CAP_PER_SHELF "maxCapacityPerShelf"

using JSON = nlohmann::json;

namespace warehouse{
    warehouse::Dimension loadDimension(std::string fileName) {
        std::ifstream fin(fileName);
        if (fin.is_open()){
            JSON layoutJson;
            fin >> layoutJson;
            warehouse::Dimension d = {layoutJson[DIMENSION][X],
                                      layoutJson[DIMENSION][Y],
                                      layoutJson[DIMENSION][Z]};
            return d;
        }
        throw warehouse::InitManagerException();
    }

    //TODO test for boundary cases
    //TODO remove magic numbers
    std::vector<warehouse::ShelfSpace> loadShelfSpaces(std::string fileName, warehouse::Dimension dimension) {
        std::ifstream fin(fileName);
        if (fin.is_open()){
            JSON layoutJson;
            fin >> layoutJson;
            const int maxCapacityPerShelf = layoutJson[SHELF_PROPERTY][MAX_CAP_PER_SHELF];
            std::vector<warehouse::ShelfSpace> shelfSpaces;
            for (int id = 2; id < dimension.x; ++id) {
                if (id % 3 != 1) {
                    for (int row = 0; row < dimension.y - 3; ++row){
                        for (int col =0; col < dimension.z - 1; ++col){
                            shelfSpaces.push_back({id, maxCapacityPerShelf, row, col});
                        }
                    }
                }
            }
            return shelfSpaces;
        }
        throw warehouse::InitManagerException();
    }

    LayoutManager::LayoutManager(std::string fileName) :
            dimension(loadDimension(fileName)),
            shelfSpaces(loadShelfSpaces(fileName, this->dimension)){

    }

    std::vector<warehouse::ShelfSpace> LayoutManager::getShelfSpaces(){
        return this->shelfSpaces;
    }
}