
#include "reality/spacemanager.cpp"
#include <iostream>

int main(){
    reality::SpaceManager spaceManager("FOO");
    reality::SpaceManager spaceManagerFoo("FOO");
    std::cout << spaceManager.removeItem(reality::Item("ID", reality::Location(0,0,0), 'C'));
    std::cout << spaceManager.putItem(reality::Item("ID", reality::Location(0,0,0), 'C'));
    std::cout << spaceManager.removeItem(reality::Item("ID", reality::Location(0,0,0), 'C'));
    std::cout << spaceManager.putItem(reality::Item("ID", reality::Location(0,0,0), 'C'));
    std::cout << spaceManager.putItem(reality::Item("ID", reality::Location(0,0,0), 'C'));

}
