
#include "reality/spacemanager.cpp"
#include <iostream>

int main(){
    reality::SpaceManager spaceManager(1, 2, 3);
    std::cout << spaceManager.removeItem(reality::Item("ID", reality::Location(0,0,0), 1, 'C'));
    std::cout << spaceManager.putItem(reality::Item("ID", reality::Location(0,0,0), 1, 'C'));
    std::cout << spaceManager.removeItem(reality::Item("ID", reality::Location(0,0,0), 1, 'C'));
    std::cout << spaceManager.putItem(reality::Item("ID", reality::Location(0,0,0), 1, 'C'));
    std::cout << spaceManager.putItem(reality::Item("ID", reality::Location(0,0,0), 1, 'C'));

}
