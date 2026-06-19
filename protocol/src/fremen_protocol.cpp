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


#include "protocol.hpp"


FremenProtocol::FremenProtocol(){;}

FremenProtocol::~FremenProtocol(){;}

void FremenProtocol::send_frame(int send_fd, FremenFrame frame){
    ;
}

void FremenProtocol::receive_frame(int receive_fd){
    ; 
}