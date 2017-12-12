#include "centralcontroller.cpp"
#include "server/customerwebtocentralserver.cpp"
#include "bot.cpp"

void runServer(warehouse::CustomerWebToCentralServer&& server){
    server.run();
}

void runBot(warehouse::Bot&& bot){
    bot.run();
}


void printMenu(){
    std::cout << "=========================================" << std::endl;
    std::cout << "=                  MENU                 =" << std::endl;
    std::cout << "=========================================" << std::endl;
    std::cout << " (1) Add new bot" << std::endl;
    std::cout << " (2) New delivery truck come" << std::endl;
    std::cout << " (0) Quit" << std::endl;
    std::cout << "=========================================" << std::endl;
    std::cout << "Enter number: ";
    std::cout.flush();

}

void addBot(warehouse::CentralController* centralController, int botId){
    warehouse::BotToCentralClientMock clientMock(centralController);
    warehouse::Bot bot(&clientMock, botId);
    std::thread *serverThread = new std::thread(runBot, std::move(bot));
    serverThread->detach();
}

void doNewDeliveryTruck(warehouse::CentralController* centralController) {
    int capacity;
    int truckId;
    std::cout << "Enter truck capacity: ";
    std::cout.flush();
    std::cin >> capacity;
    std::cout << "Enter truck id: ";
    std::cout.flush();
    std::cin >> truckId;
    warehouse::LoadingBay loadingBay = centralController->deliveryArrive();
    centralController->startDelivery(truckId, capacity, loadingBay);
    std::cout << "Finished Delivering";
//    warehouse::Location l = {0,0,0};
//    centralController->botPollInstruction(l);
//    centralController->botPollInstruction(l);
//    centralController->botPollInstruction(l);
//    centralController->botPollInstruction(l);
}

const char QUIT = '0';
const char ADD_BOT = '1';
const char NEW_DELIVERY_TRUCK = '2';

void managerUI(warehouse::CentralController* centralController){
    char cmd = 0;
    int botId = 0;
    while (cmd != QUIT) {
        printMenu();
        // get menu entry
        std::cin >> cmd;
        // gobble newline
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (cmd){
            case ADD_BOT:
                addBot(centralController, botId);
                ++botId;
                break;
            case NEW_DELIVERY_TRUCK:
                doNewDeliveryTruck(centralController);
                break;
            case QUIT:
                break;
            default:
                std::cout << "Invalid command number " << cmd << std::endl << std::endl;

        }
    }
}

int main(){
    warehouse::CentralController centralController;
    warehouse::CustomerWebToCentralServer customerWebToCentralServer(&centralController);
    std::thread *serverThread = new std::thread(runServer, std::move(customerWebToCentralServer));
    serverThread->detach();
    managerUI(&centralController);
}