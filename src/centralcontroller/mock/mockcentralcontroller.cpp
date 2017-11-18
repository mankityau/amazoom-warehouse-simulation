#include "../centralcontroller.h"

namespace centralcontroller{
    class MockCentralController : public virtual CentralController{
        common::CreateOrderResponse createOrder(int itemId){
            return {0, true};
        }
    };
}\