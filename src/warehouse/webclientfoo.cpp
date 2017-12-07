#include <cpen333/process/socket.h>
#include "../api/customerwebtocentral/customerwebtocentralapi.cpp"

int main() {
    cpen333::process::socket socket("localhost", 52102);
    std::cout << "Client connecting...";
    std::cout.flush();
    if (socket.open()) {
        std::cout << "connected." << std::endl;
        api::CustomerWebToCentralApi api(std::move(socket));
        std::vector<int> merchandiseId;
        merchandiseId.push_back(1);
        merchandiseId.push_back(2);
        merchandiseId.push_back(100);
        api.sendRequest(api::OrderRequest(merchandiseId));
        std::unique_ptr<api::ResponseInterface> resp = api.receiveResp();
        if (resp != nullptr){
            std::string functionName = resp->functionName();
            if (functionName == ORDER_FUNCTION){
                api::OrderResponse &orderResponse = (api::OrderResponse &)(*resp);
                std::cout << orderResponse.orderId << std::endl;
                std::cout << orderResponse.success;
            }
        }

    }
}

