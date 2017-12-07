#include <thread>
#include "customerwebtocentralserver.h"
#include "../../api/customerwebtocentral/customerwebtocentralapi.cpp"

namespace warehouse{
    void service(warehouse::CentralController *centralController, api::CustomerWebToCentralApi &&api){
        std::unique_ptr<api::RequestInterface> request = api.receiveRequest();
        while (request != nullptr){
            std::string functionName = request->functionName();{
                if (functionName == ORDER_FUNCTION){
                    api::OrderRequest &orderRequest = (api::OrderRequest &)(*request);
                    warehouse::NewOrderResponse newOrderResponse = centralController->newOrder(orderRequest.merchandiseId);
                    api::OrderResponse orderResponse(newOrderResponse.success, newOrderResponse.orderId);
                    api.sendResponse(orderResponse);
                }
            }

            request = api.receiveRequest();
        }
    }

    CustomerWebToCentralServer::CustomerWebToCentralServer(warehouse::CentralController *centralController) {
        this->centralController = centralController;
    }

    void CustomerWebToCentralServer::run(){
        cpen333::process::socket_server server(52102);
        server.open();

        cpen333::process::socket client;
        while (server.accept(client)) {
            std::cout << "CLIENT CONNECTED \n";
            api::CustomerWebToCentralApi api(std::move(client));
            std::thread thread(service, std::ref(centralController),std::move(api));
            thread.detach();
        }

        server.close();

    }
}