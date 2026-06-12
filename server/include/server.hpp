#pragma once

#include <mutex>
#include <string>
#include <queue>
#include <condition_variable>

const int listen_limit = 10;
const int server_port = 8080;
const int number_of_workers = 0;
const std::string server_ip_address = "127.0.0.1";

class Server{
private:
    int counter;

    bool predicate;

    std::mutex mtx;

    int num_clients;

    int num_workers;

    std::string server_status;

    std::condition_variable cv;

    std::queue<int> worker_queue;

public:

    /* Server Constructor */
    Server();

    /* Server Destructor */
    ~Server();

    void print_server_status();

    /* Server entry point */
    void Server::start_server();

    /* Initialize server websocket */
    int Server::create_socket();

    /* Begin serving of thread instances */
    void Server::serve_threads(int fd);

    /* Spin up worker threads */
    void Server::spawn_workers();

    /* Worker waiting code */
    void Server::worker_pool();
};