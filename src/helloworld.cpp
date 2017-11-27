
#include "reality/spacemanager.cpp"
#include <iostream>

int main(){
    reality::SpaceManager spaceManager("FOO", {2, 2, 2});
    reality::SpaceManager spaceManagerFoo("FOO", {2, 2, 2});
    reality::Item i("ID", reality::Location(0,0,0), 'C');
    std::cout << spaceManager.removeItem(i) << std::endl;
    std::cout << spaceManagerFoo.putItem(i) << std::endl;
    std::cout << spaceManager.removeItem(i) << std::endl;
    std::cout << spaceManagerFoo.putItem(i) << std::endl;
    std::cout << spaceManager.putItem(i) << std::endl;
    std::cout << spaceManager.updateLocation(i, {0,1,1}) << std::endl;
    std::cout << spaceManager.updateLocation(i, {0,1,2}) << std::endl;

}
