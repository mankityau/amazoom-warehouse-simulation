#include "layoutmanager.h"
#include "managerexception.h"
#include <fstream>
#include <json.hpp>

#define DIMENSION "dimension"
#define LENGTH "length"
#define WIDTH "width"
#define HEIGHT "height"

#define SHELF_PROPERTY "shelfProperty"
#define MAX_CAP_PER_SHELF "maxCapacityPerShelf"
#define LOADING_BAY_NUM "loadingBayNum"

using JSON = nlohmann::json;

namespace warehouse{
    warehouse::Dimension loadDimension(std::string fileName) {
        std::ifstream fin(fileName);
        if (fin.is_open()){
            JSON layoutJson;
            fin >> layoutJson;
            warehouse::Dimension d = {layoutJson[DIMENSION][LENGTH],
                                      layoutJson[DIMENSION][WIDTH],
                                      layoutJson[DIMENSION][HEIGHT]};
            return d;
        }
        throw warehouse::InitManagerException();
    }

    void LayoutManager::log(std::string msg){
        std::cout << "Layout Manager: " << msg << std::endl;
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

    std::vector<warehouse::LoadingBay> loadLoadingBays(std::string fileName, warehouse::Dimension dimension){
        std::vector<warehouse::LoadingBay> loadingBays;

        std::ifstream fin(fileName);
        if (fin.is_open()){
            JSON layoutJson;
            fin >> layoutJson;
            const int loadingBayNum = layoutJson[LOADING_BAY_NUM];
            for (int i = 0; i < loadingBayNum; ++i){
                loadingBays.push_back({i});
            }
        }
        return loadingBays;
    }

    LayoutManager::LayoutManager(std::string fileName) :
            dimension(loadDimension(fileName)),
            shelfSpaces(loadShelfSpaces(fileName, this->dimension)),
            loadingBays(loadLoadingBays(fileName, this->dimension)){
        for (int i = 0; i < loadingBays.size(); ++i) {
            freeLoadingBays.push_back(loadingBays.at(i));
            freeLoadingBaySemaphore.notify();
        }

    }

    std::vector<warehouse::ShelfSpace> LayoutManager::getShelfSpaces(){
        return this->shelfSpaces;
    }

    LoadingBay LayoutManager::truckArrive() {
        freeLoadingBaySemaphore.wait();
        warehouse::LoadingBay loadingBay = freeLoadingBays.back();
        freeLoadingBays.pop_back();
        return loadingBay;
    }

    bool LayoutManager::truckLeave(LoadingBay loadingBay) {
        freeLoadingBays.push_back(loadingBay);
        freeLoadingBaySemaphore.notify();
        return true;
    }

    // todo fix this mock
    Path LayoutManager::pathToShelf(Location location, ShelfSpace shelfSpace){
        Location l = {0, 0, 0};
        log("Computed path from location to shelf space." + toString(location) + toString(shelfSpace));
        return {l, l, l, l};
    };

    // todo fix this mock
    Path LayoutManager::pathToLoadingBay(Location location, LoadingBay loadingBay) {
        Location l = {0, 0, 0};
        log("Computed path from location to loading bay." + toString(location) + toString(loadingBay));
        return {l, l, l, l};
    }
}