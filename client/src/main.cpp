

#include "client.hpp"

int main(){ 

    auto client_obj = ClientApp();

    client_obj.connect_to_server();

    return 0;
}