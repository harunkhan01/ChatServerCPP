#include <vector>
#include <mutex>
#include <thread>
#include <iostream>

#include <netinet/in.h>
#include <sys/socket.h>

#include "server.hpp"
#include "thread_engine.hpp"

/* Server Constructor */
Server::Server() : counter(0), predicate(false), num_workers(number_of_workers), num_clients(0), server_status("healthy") {
    ;
}

 /* Server Destructor */
Server::~Server(){
    ;
}

void Server::print_server_status(){

    std::cout << "Server status: " << server_status << std::endl;

    std::cout << "Number of connected clients: " << num_clients << std::endl;

    std::cout << "Maximum allowable threads: " << num_workers << std::endl;

}

void Server::start_server(){
    /* Begin thread management */
    this->spawn_workers();

    /* begin server loop */
    int server_socket = this->create_socket();
 
    this->serve_threads(server_socket);
}

int Server::create_socket(){
    /* Binds an address to a socket and returns the file descriptor */

    int fd;   

    fd = socket(AF_INET, SOCK_STREAM, 0);

    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(server_port);
    serverAddress.sin_addr.s_addr = INADDR_ANY; 

    bind(fd, (const sockaddr *)&serverAddress, sizeof(serverAddress));

    return fd;
}

void Server::serve_threads(int server_fd){

    std::vector<char> client_data;

    listen(server_fd, listen_limit);

    /* We start our server session */
    while (1) {
        int client_fd = accept(server_fd, nullptr, nullptr);

        recv(client_fd, client_data.data(), 100, 0);

        for (auto ch : client_data){
            std::cout << ch << std::endl;
        }
    }
}

void Server::spawn_workers(){

    for (int i=0; i < this->num_workers; i++){
        std::thread(&Server::worker_pool, this);
    }

}

void Server::worker_pool(){
    
    std::unique_lock<std::mutex> lock(mtx);

    while(!this->predicate){
        this->cv.wait(lock);
    }

    /* pull from worker queue -- its a vector right now */


    lock.unlock();
    
}