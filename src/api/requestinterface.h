#ifndef AMAZOOM_WAREHOUSE_SIMULATION_REQUEST_H
#define AMAZOOM_WAREHOUSE_SIMULATION_REQUEST_H

#include <string>

namespace api {
    class RequestInterface{
    public:
        virtual std::string functionName() const = 0;
    };
}
#endif //AMAZOOM_WAREHOUSE_SIMULATION_REQUEST_H
