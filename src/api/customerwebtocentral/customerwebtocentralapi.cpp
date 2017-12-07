#include "../jsonoversocketapiinterface.h"
#include "jsonconverter.cpp"
namespace api{
    class CustomerWebToCentralApi : public JsonOverSocketApiInterface{
    private:
        api::JsonConverterInterface* jc = new JsonConverter();
    protected:
        api::JsonConverterInterface* jsonConverter() const {
            return jc;
        }
    public:
        CustomerWebToCentralApi(cpen333::process::socket &&socket) :
                JsonOverSocketApiInterface(std::move(socket)){}

    };
}