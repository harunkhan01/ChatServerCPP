#include <iostream>

#include "server.hpp"

/* Server Constructor */
Server::Server() : max_threads(MAX_THREADS), num_clients(0), server_status("healthy") {
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