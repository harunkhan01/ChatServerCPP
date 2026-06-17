#include <vector>
#include <mutex>
#include <thread>
#include <iostream>

#include <netinet/in.h>
#include <sys/socket.h>

#include "server.hpp"

/* Server Constructor */
Server::Server() : counter(0), num_workers(number_of_workers), num_clients(0), server_status("healthy"), printing_press("") {
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

    int err;

    listen(server_fd, listen_limit);

    std::cout << "Started up server!" << std::endl;

    /* We start our server session */
    while (1) {
        int client_fd = accept(server_fd, nullptr, nullptr);

        std::cout << "Client connected!" << std::endl;

        /*
        We want to add this client_fd to the queue and then
        unlock the mutex for a thread to acquire the lock and
        proceed in the critical section
        */

        std::unique_lock<std::mutex> lock(this->mtx);

        this->worker_queue.push(client_fd);

        lock.unlock();

        this->cv.notify_one();

    }
}

void Server::spawn_workers(){
    /* Create workers and send them to hell */

    std::cout << "Starting " << this->num_workers << " number of workers!" << std::endl;

    for (int i=0; i < this->num_workers; i++){
        this->threads.emplace_back(&Server::worker_pool, this);
    }
}

void Server::worker_pool(){
    
    while (1){
        std::unique_lock<std::mutex> lock(mtx);

        this->cv.wait(lock, [this] {
            return !worker_queue.empty();
        });
        
        /* pull from from of worker queue */
        int client_fd = this->worker_queue.front();

        lock.unlock();

        /* Launch subscript for handling client process */
        this->thread_handle_client(client_fd);
    }
}

void Server::thread_handle_client(int client_fd){

    int err;
    char data[250];

    std::cout << "Thread is handling connection with client: " << client_fd << std::endl;

    while (1){
        err = recv(client_fd, data, sizeof(data), 0);

        if (err == 0){
            std::cout << "Client: " << client_fd << " closed their connection. Exiting loop!" << std::endl;
            break;
        } else if (err == -1){
            std::cout << "Error on recv() call. Exiting..." << std::endl;
            break;
        }

        std::cout << "Successfully received message from client!" << std::endl;

        std::cout << "Messaged received: ";

        for (int i=0; i < err; i++){
            std::cout << data[i];
        }

        std::cout << "\n";
    }
}