#pragma once

#include <string>

const int server_port = 8080;

const char server_ip_address[] = "127.0.0.1";
const char client_ip_address[] = "127.0.0.2";

class ClientApp{
private:
    bool connection_status;

public:

    ClientApp();

    ~ClientApp();

    void connect_to_server();

    void chat_with_server(int fd);
};