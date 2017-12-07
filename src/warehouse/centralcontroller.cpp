#include <iostream>
#include "centralcontroller.h"
#include "manager/layoutmanager.cpp"
#include "manager/inventorymanager.cpp"

namespace warehouse {
    std::string getInput(std::string question){
        std::cout << question << ": ";
        std::string response;
        std::cin >> response;
        return response;
    }

    CentralController::CentralController() :
    layoutManager("./../../data/layout/layout1.json"),
    inventoryManager(layoutManager.getShelfSpaces(), "./../../data/merchandisecatalog.json", "./../../data/carrymerchandise/carrymerchandise1.json"){//getInput("Layout file name for layout")){
    }
}