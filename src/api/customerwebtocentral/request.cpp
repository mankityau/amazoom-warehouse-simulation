#include "../requestinterface.h"
#include "functionname.h"

#define MERCHANDISE_ID "merchandiseId"

namespace api {
    class OrderRequest : public RequestInterface {
    public:
        const std::vector<int> merchandiseId;
        OrderRequest(std::vector<int> merchandiseId):merchandiseId(merchandiseId){
        }
        std::string functionName() const {
            return ORDER_FUNCTION;
        }
    };
}