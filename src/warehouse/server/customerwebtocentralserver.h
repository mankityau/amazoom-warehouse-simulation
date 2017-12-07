#ifndef AMAZOOM_WAREHOUSE_SIMULATION_CUSTOMERWEBTOCENTRALSERVER_H
#define AMAZOOM_WAREHOUSE_SIMULATION_CUSTOMERWEBTOCENTRALSERVER_H

#include "../centralcontroller.h"

namespace warehouse {
    class CustomerWebToCentralServer {
    private:
        warehouse::CentralController* centralController;
    public:
        CustomerWebToCentralServer(warehouse::CentralController* centralController);
        void run();
    };
}


#endif //AMAZOOM_WAREHOUSE_SIMULATION_CUSTOMERWEBTOCENTRALSERVER_H
