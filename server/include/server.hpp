#pragma once

#include <mutex>
#include <string>
#include <vector>

const int number_of_workers = 0; 

class Server{
private:
    int counter;
    std::mutex mtx;
    int num_clients;
    const int num_workers;
    std::string server_status;
    std::vector work_queue;

public:

    /* Server Constructor */
    Server();

    /* Server Destructor */
    ~Server();

    void print_server_status();

    /* Server entry point */
    void Server::start_server();

    /* Spin up worker threads */
    void Server::spawn_workers();
};