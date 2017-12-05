#include <iostream>
#include "centralcontroller.h"
#include "manager/layoutmanager.cpp"

namespace warehouse {
    std::string getInput(std::string question){
        std::cout << question << ": ";
        std::string response;
        std::cin >> response;
        return response;
    }

    CentralController::CentralController() :
    layoutManager("./../../data/layout/layout1.json"){//getInput("Layout file name for layout")){
    }
}

int main(){
    warehouse::CentralController centralController;
}