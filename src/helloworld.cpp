
#include "reality/spacemanager.cpp"
#include <iostream>

int main(){
    reality::SpaceManager spaceManager("FOO", {0,0,0});
    reality::SpaceManager spaceManagerFoo("FOO", {0,0,0});
    std::cout << spaceManager.removeItem(reality::Item("ID", reality::Location(0,0,0), 'C')) << std::endl;
    std::cout << spaceManagerFoo.putItem(reality::Item("ID", reality::Location(0,0,0), 'C')) << std::endl;
    std::cout << spaceManager.removeItem(reality::Item("ID", reality::Location(0,0,0), 'C')) << std::endl;
    std::cout << spaceManagerFoo.putItem(reality::Item("ID", reality::Location(0,0,0), 'C')) << std::endl;
    std::cout << spaceManager.putItem(reality::Item("ID", reality::Location(0,0,0), 'C')) << std::endl;

}
