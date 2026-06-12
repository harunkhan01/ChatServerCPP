#include <mutex>
#include <thread>
#include <iostream>

#include "server.hpp"
#include "thread_engine.hpp"

/* Server Constructor */
Server::Server() : counter(0), num_workers(number_of_workers), num_clients(0), server_status("healthy") {
    ;
}

 /* Server Destructor */
Server::~Server(){
    ;
}

void Server::print_server_status(){

    std::cout << "Server status: " << server_status << std::endl;

    std::cout << "Number of connected clients: " << num_clients << std::endl;

    std::cout << "Maximum allowable threads: " << max_threads << std::endl;

}

void Server::start_server(){
    /* Begin thread management */
    this->spawn_workers();
    

}

void Server::spawn_workers(){

    for (auto : num_workers){
        std::thread t(target, this);
    }

}