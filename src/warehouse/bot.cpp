#include "bot.h"
#include "bottocentralclientmock.cpp"

namespace warehouse{
    void Bot::log(std::string msg) {
        std::cout << "Bot-" << id << ": " << msg << std::endl;
    }

    Bot::Bot(BotToCentralClientMock* botToCentralClientMock, int id) : id(id){
        this->botToCentralClientMock = botToCentralClientMock;
    }

    void Bot::run(){
        while(true) {
            BotInstruction instruction = botToCentralClientMock->pollInstruction(location);
            log("Going to " + toString(instruction.pathToGetItem.end));
            log("Picking up item " + toString(instruction.merchandise));
            log("Going to " + toString(instruction.pathToPutLoad.end));
            log("Loading item");
            location = {instruction.pathToPutLoad.end.x, instruction.pathToPutLoad.end.y, instruction.pathToPutLoad.end.z};
        }
    }
}