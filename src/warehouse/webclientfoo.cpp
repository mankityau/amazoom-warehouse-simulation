#include <cpen333/process/socket.h>
#include "../api/customerwebtocentral/customerwebtocentralapi.cpp"

int main() {
    cpen333::process::socket socket("localhost", 52102);
    std::cout << "Client connecting...";
    std::cout.flush();
    if (socket.open()) {
        std::cout << "connected." << std::endl;
        api::CustomerWebToCentralApi api(std::move(socket));
        api.sendRequest(api::FooRequest());
    }
}

