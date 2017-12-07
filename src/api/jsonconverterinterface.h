#ifndef AMAZOOM_WAREHOUSE_SIMULATION_JSONCONVERTERINTERFACE_H
#define AMAZOOM_WAREHOUSE_SIMULATION_JSONCONVERTERINTERFACE_H

#include "requestinterface.h"
#include "responseinterface.h"
#include <json.hpp>

using JSON = nlohmann::json;

#define FUNCTION_NAME "functionName"
#define PARAMETERS "parameters"

namespace api{
    class JsonConverterInterface{
    public:
        virtual JSON toJSON(const api::RequestInterface &req) const = 0;
        virtual std::unique_ptr<RequestInterface> parseRequest(const JSON &jmsg) const = 0;
        virtual JSON toJSON(const api::ResponseInterface &resp) const = 0;
        virtual std::unique_ptr<ResponseInterface> parseResponse(const JSON &jmsg) const = 0;

    };
}

#endif //AMAZOOM_WAREHOUSE_SIMULATION_JSONCONVERTERINTERFACE_H
