#ifndef AMAZOOM_WAREHOUSE_SIMULATION_RESPONSEINTERFACE_H
#define AMAZOOM_WAREHOUSE_SIMULATION_RESPONSEINTERFACE_H

namespace api{
    class ResponseInterface{
    public:
        virtual std::string functionName() const = 0;
    };
}

#endif //AMAZOOM_WAREHOUSE_SIMULATION_RESPONSEINTERFACE_H
