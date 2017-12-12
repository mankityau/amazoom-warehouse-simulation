#ifndef AMAZOOM_WAREHOUSE_SIMULATION_BOT_H
#define AMAZOOM_WAREHOUSE_SIMULATION_BOT_H

#include "bottocentralclientmock.h"

namespace warehouse {
    class Bot {
    private:
        BotToCentralClientMock* botToCentralClientMock;
        Location location = {1, 1, 0};
        const int id;
        void log(std::string msg);
    public:
        Bot(BotToCentralClientMock* botToCentralClientMock, int id);
        void run();

    };
}


#endif //AMAZOOM_WAREHOUSE_SIMULATION_BOT_H
