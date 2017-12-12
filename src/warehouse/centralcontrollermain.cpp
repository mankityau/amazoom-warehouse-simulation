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
    std::cout << " (2) Quit" << std::endl;
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

const char ADD_BOT = '1';
const char QUIT = '2';

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