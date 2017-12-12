#include "bot.h"
#include "bottocentralclientmock.cpp"

namespace warehouse{
    void Bot::log(std::string msg) {
        std::cout << "Bot-" << id << ": " << msg << std::endl;
    }

    Bot::Bot(BotToCentralClientMock* botToCentralClientMock, int id) : id(id){
        this->botToCentralClientMock = botToCentralClientMock;
        log("started.");
    }

    void print(int i, int times){
        for (int t = 0; t < times; ++t){
            std::cout << i;
        }
    }

    void Bot::run(){
//        bool alive = true;
//        int i = 0;
//        BotInstruction instruction = botToCentralClientMock->pollInstruction(location);
//        while(i < 10) {
//            log("Polling new instruction.");
//            log("Going to " + toString(instruction.pathToGetItem.end));
//            location = {instruction.pathToGetItem.end.x, instruction.pathToGetItem.end.y, instruction.pathToGetItem.end.z};
//            log("Arrive.");
//            log("Picking up item " + toString(instruction.merchandise));
//            log("Going to " + toString(instruction.pathToPutLoad.end));
//            location = {instruction.pathToPutLoad.end.x, instruction.pathToPutLoad.end.y, instruction.pathToPutLoad.end.z};
//            log("Arrive.");
//            log("Loading item");
        log("Polling once");
        botToCentralClientMock->pollInstruction(location);
        std::this_thread::sleep_for(std::chrono::seconds(5));
        log("Polling twice");
        botToCentralClientMock->pollInstruction(location);
        std::this_thread::sleep_for(std::chrono::seconds(5));
        log("Polling third");
        botToCentralClientMock->pollInstruction(location);
        std::this_thread::sleep_for(std::chrono::seconds(5));
//            print(i, 10);
//            ++i;
//        }
    }
}