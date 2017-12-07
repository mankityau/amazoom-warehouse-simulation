#include "../jsonconverterinterface.h"
#include "request.cpp"

namespace api{
    class JsonConverter : public JsonConverterInterface {
    public:
        JSON toJSON(const api::RequestInterface &req) const {
            JSON j;
            j[FUNCTION_NAME] = "foo";
            return j;
        }

        std::unique_ptr<RequestInterface> parseRequest(const JSON &jmsg) const{
            return std::unique_ptr<RequestInterface>(new FooRequest());
        }
    };
}