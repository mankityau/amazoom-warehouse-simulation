#include "../requestinterface.h"

namespace api {
    class FooRequest : public RequestInterface{
    public:
        std::string functionName() const {
            return "foo";
        }
    };
}