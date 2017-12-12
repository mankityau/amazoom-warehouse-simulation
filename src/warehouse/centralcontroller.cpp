#include <iostream>
#include "centralcontroller.h"
#include "manager/botmanager.cpp"
#include "manager/deliverymanager.cpp"
#include "manager/layoutmanager.cpp"
#include "manager/inventorymanager.cpp"
#include "manager/ordermanager.cpp"
#include "manager/shelfspacemanager.cpp"

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
    orderManager(),
    shelfSpaceManager(layoutManager.getShelfSpaces()),
    deliveryManager(),
    botManager(){//getInput("Layout file name for layout")){

        // populate the inventory and shelfspace.
        std::map<warehouse::Merchandise, int> lowStockItem = inventoryManager.getLowStockItems();
        for (std::map<warehouse::Merchandise, int>::iterator it = lowStockItem.begin(); it != lowStockItem.end(); ++it){
            for (int count = 0; count < it->second; ++count){
                warehouse::ShelfSpace freeSpace = shelfSpaceManager.findAvailable(it->first.weight);
                inventoryManager.pushAvailableMerchandise(it->first.id, freeSpace);
                shelfSpaceManager.fill(freeSpace, it->first.weight);
            }
        }
    }

    //TODO fix this mock
    NewOrderResponse CentralController::newOrder(std::vector<int> merchandiseIds) {
        int orderId = orderManager.newOrder();

        std::map<int, int> orderMerchandiseQuantity;
        for (std::vector<int>::const_iterator it = merchandiseIds.begin(); it != merchandiseIds.end(); ++it){
            if (orderMerchandiseQuantity.count(*it) == 0){
                orderMerchandiseQuantity[*it] = 1;
            } else {
                orderMerchandiseQuantity[*it] = orderMerchandiseQuantity[*it] + 1;
            }
        }

        for (std::map<int, int>::iterator it = orderMerchandiseQuantity.begin(); it != orderMerchandiseQuantity.end(); ++ it){
            if (!inventoryManager.available(it->first, it->second)) {
                orderManager.removeOrder(orderId);
                return {false, orderId};
            }
        }

        for (std::vector<int>::iterator it = merchandiseIds.begin(); it != merchandiseIds.end(); ++ it) {
            warehouse::ShelfSpace shelfSpace = inventoryManager.popAvailableMerchandise(*it);
            orderManager.addMerchandise(orderId, inventoryManager.getMerchandiseById(*it), shelfSpace);
        }

        return {true, orderId};
    }

    LoadingBay CentralController::deliveryArrive(){
        LoadingBay loadingBay = layoutManager.truckArrive();
        return loadingBay;
    }

    bool CentralController::startDelivery(int truckId, int truckCapacity, LoadingBay loadingBay) {
        int remainCapacity = truckCapacity;
        int orderId = orderManager.findToDeliver(remainCapacity);
        deliveryManager.startDelivery(truckId);
        while (orderId != orderManager.POISON_ORDER_ID) {
            remainCapacity -= orderManager.orderCapacity(orderId);
            deliveryManager.pushOrderId(truckId, orderId);
            int numOfMerchandise = orderManager.numOfMerchandise(orderId);
            for (int i = 0; i < numOfMerchandise; ++i) {
                Merchandise merchandise = orderManager.merchandiseAt(orderId, i);
                ShelfSpace shelfSpace = orderManager.shelfSpaceAt(orderId, i);
                botManager.startDeliveryOrder(orderId, merchandise, shelfSpace,loadingBay);
            }
        }
        return true;
    }

    BotInstruction CentralController::botPollInstruction(Location botLocation) {
        BotInstructionBase botInstructionBase = botManager.nextInstructionBase(botLocation);
        if (botInstructionBase.botInstructionType == deliver) {
            Path pathToShelf = layoutManager.pathToShelf(botLocation, botInstructionBase.targetShelfSpace);
            Path pathToLoadingBay = layoutManager.pathToLoadingBay(pathToShelf.end, botInstructionBase.loadingBay);
            BotInstruction instruction = {
                    deliver,
                    pathToShelf,
                    pathToLoadingBay,
                    botInstructionBase.targetShelfSpace,
                    botInstructionBase.merchandise
            };
            shelfSpaceManager.free(instruction.shelfSpace, instruction.merchandise.weight);
            return instruction;
        }
    }


}