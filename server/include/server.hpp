#pragma once

#include <mutex>
#include <string>
#include <vector>
#include <condition_variable>

const int number_of_workers = 0; 

class Server{
private:
    int counter;

    std::mutex mtx;

    int num_clients;

    int num_workers;

    std::string server_status;

    std::condition_variable cv;

    std::vector<int> worker_queue;

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

    /* Worker waiting code */
    void Server::worker_pool();
};