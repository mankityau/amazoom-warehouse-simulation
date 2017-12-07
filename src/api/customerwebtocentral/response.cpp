#include "../responseinterface.h"
#include "functionname.h"

#define SUCCESS "success"
#define ORDER_ID "orderId"

namespace api{
    class OrderResponse : public ResponseInterface{
    public:
        const bool success;
        const int orderId;
        OrderResponse(bool success, int orderId) :
                success(success) ,
                orderId(orderId){}

        std::string functionName() const {
            return ORDER_FUNCTION;
        }
    };
}