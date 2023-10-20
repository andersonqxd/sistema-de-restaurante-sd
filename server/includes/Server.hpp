#ifndef __SERVER_HPP__
#define __SERVER_HPP__

#include <iostream>

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>

#include <json.hpp>

#define SERVER_PORT   7000
#define SERVER_IP     "127.0.0.1"

#define BUFFER_SIZE   1024

using json = nlohmann::json;

class Server
{
    int udp_socket;

    char * buffer;

    struct sockaddr_in server_address;
    struct sockaddr_in client_address;

    public:
        Server();

        void listen();
};


#endif