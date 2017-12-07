#include <iostream>
#include <vector>
#include "api/customerwebtocentral/customerwebtocentralapi.cpp"
static const char CLIENT_NEW_ORDER = '1';
static const char CLIENT_QUIT = '2';

void printMenu(){
    std::cout << "=========================================" << std::endl;
    std::cout << "=                  MENU                 =" << std::endl;
    std::cout << "=========================================" << std::endl;
    std::cout << " (1) Order Item" << std::endl;
    std::cout << "=========================================" << std::endl;
    std::cout << "Enter number: ";
    std::cout.flush();

}

void pause(){
    std::cin.clear();  // flush input
    std::cout << "Press ENTER to continue . . .";
    std::string line;
    std::getline(std::cin, line);
}

void doNewOrder(api::CustomerWebToCentralApi& api){
    std::vector<int> merchandiseIds;
    std::cout << "Enter merchandise Id (-1) to quit: ";
    std::cout.flush();
    int input = 0;
    while (input != -1) {
        std::cin >> input;
        if (input != -1) {
            merchandiseIds.push_back(input);
            std::cout << "Enter next merchandise Id (-1) to quit: ";
            std::cout.flush();
        }
    }

    api.sendRequest(api::OrderRequest(merchandiseIds));
    std::unique_ptr<api::ResponseInterface> resp = api.receiveResp();

    if (resp != nullptr){
        std::string functionName = resp->functionName();
        if (functionName == ORDER_FUNCTION){
            api::OrderResponse &orderResponse = (api::OrderResponse &)(*resp);
            if (orderResponse.success){
                std::cout << "Order successful, orderId: " << orderResponse.orderId << std::endl;
            }else {
                std::cout << "Order not successful" << std::endl;
            }
        }
    }

}

int main(){
    cpen333::process::socket socket("localhost", 52102);
    std::cout << "Client connecting...";
    std::cout.flush();
    if (socket.open()) {
        std::cout << "connected." << std::endl;
        api::CustomerWebToCentralApi api(std::move(socket));
        char cmd = 0;
        while (cmd != CLIENT_QUIT) {
            printMenu();
            // get menu entry
            std::cin >> cmd;
            // gobble newline
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            switch (cmd){
                case CLIENT_NEW_ORDER:
                    doNewOrder(api);
                    break;
                case CLIENT_QUIT:
                    break;
                default:
                    std::cout << "Invalid command number " << cmd << std::endl << std::endl;

            }
        }
        pause();
    } else {
        std::cout << "failed." << std::endl;
    }

    return 0;
}