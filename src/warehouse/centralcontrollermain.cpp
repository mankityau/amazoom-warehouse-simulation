#include "centralcontroller.cpp"
#include "server/customerwebtocentralserver.cpp"
int main(){
    warehouse::CentralController centralController;
    warehouse::CustomerWebToCentralServer customerWebToCentralServer(&centralController);
    customerWebToCentralServer.run();
}