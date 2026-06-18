#pragma once

#include <bits/stdc++.h> 

/*
Implementation of an application layer protocol over TCP
    - For now will be without encryption
    - We will deploy encryption later via MbedTLS
    - Point? To let central node know whether device is still connected or not!

Specification:
    - First 2 bytes of any datagram sent to the server from the client will be treated as a header
        - Start sequence: 0xBAFFFFAB
            - All data in between treated as client's message to the server
        - End sequence: 0xBEFFFFEB
*/

class FremenFrame{
private:
    uint16_t start_frame = 0xBAFFFFAB;
    uint16_t end_frame = 0xBEFFFFEB;
    std::vector<uint16_t> data; 

public:

    /* Constructor for the Fremen Frame */
    FremenFrame();
    
    /* Destructor for the Fremen Frame */
    ~FremenFrame();

}; 


class FremenProtocol{
private:
    

public:

    /* Constructor for the Fremen Protocol */
    FremenProtocol();

    /* Destructor for the Fremen Protocol */
    ~FremenProtocol();

    /* Send a Fremen Frame */
    void send_frame(int send_fd, FremenFrame fremen_frame);

    /* Receive a Fremen Frame */
    void receive_frame(int receive_fd);
};