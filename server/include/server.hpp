#pragma once

#define MAX_THREADS 20

#include <string>

class Server{
private:
    int num_clients;
    std::string server_status;
    const int max_threads;

public:

    /* Server Constructor */
    Server();

    /* Server Destructor */
    ~Server();

    void print_server_status();

};