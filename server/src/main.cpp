/* Server Main Code */
#include <iostream>

#include "server.hpp"

int main(){

    std::cout << "Hello World" << std::endl;

    Server server_obj;

    server_obj.print_server_status(); 

    return 0;

}