#include <vector>
#include <string>
#include <iostream>

#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>


/* Custom headers included */
#include "client.hpp"

ClientApp::ClientApp(){
    ;
}

ClientApp::~ClientApp(){;}

void ClientApp::connect_to_server(){
    /* In order to create connection we need to do several things: 
        - create client socket
        - connect to remote server IP
    
    */
    int err;
    int client_fd = socket(AF_INET, SOCK_STREAM, 0);

    sockaddr_in server_sockaddr;
    server_sockaddr.sin_port = htons(server_port);
    server_sockaddr.sin_family = AF_INET;
    
    inet_pton(AF_INET, server_ip_address, &(server_sockaddr.sin_addr));

    err = connect(client_fd, (const sockaddr *)&server_sockaddr, sizeof(server_sockaddr));

    if (err == -1){
        std::cout << "Error setting up connection with remote server. Exiting..." << std::endl;
        exit(1);
    }

    std::cout << "Successful connection to server!" << std::endl;

    chat_with_server(client_fd);
}


void ClientApp::chat_with_server(int fd){

    int err;
    std::string message;

    while (1){

        std::cout << "Send message to server: ";
        std::cin >> message;

        err = send(fd, message.data(), message.size(), 0);

        if (err == -1){
            std::cout << "Failed to send message." << std::endl;
        }

        std::cout << "Successfully sent message!" << std::endl;

        std::cout << "Sent " << err << " number of bytes" << std::endl;

    }

}