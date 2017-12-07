#include <iostream>
#include "centralcontroller.h"
#include "manager/layoutmanager.cpp"
#include "manager/inventorymanager.cpp"
#include "manager/ordermanager.cpp"

namespace warehouse {
    std::string getInput(std::string question){
        std::cout << question << ": ";
        std::string response;
        std::cin >> response;
        return response;
    }

    CentralController::CentralController() :
    layoutManager("./../../data/layout/layout1.json"),
    inventoryManager(layoutManager.getShelfSpaces(), "./../../data/merchandisecatalog.json", "./../../data/carrymerchandise/carrymerchandise1.json"),
    orderManager(){//getInput("Layout file name for layout")){
    }

    //TODO fix this mock
    NewOrderResponse CentralController::newOrder(std::vector<int> merchandiseIds) {
        int orderId = orderManager.newOrder();
        if (inventoryManager.newOrder(orderId, merchandiseIds)){
            return {true, orderId};
        } else {
            return {false, orderId};
        }
    }
}