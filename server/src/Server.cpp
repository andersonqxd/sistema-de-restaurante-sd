#include "Server.hpp"

Server::Server()
{

    if ((udp_socket = socket(AF_INET, SOCK_DGRAM, 0)) < 0)
    {
        std::cout << "Server::Server(): Error initializa server" << std::endl;
        exit(EXIT_FAILURE);
    }

    buffer = new char[BUFFER_SIZE];
    memset(buffer, 0, sizeof(BUFFER_SIZE));

    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(SERVER_PORT);

    if ((bind(udp_socket, (const struct sockaddr *)&server_address, sizeof(server_address))) < 0)
    {
        std::cout << "Server::Server(): Error bind " << SERVER_IP << " with port " << SERVER_PORT << std::endl;
        exit(EXIT_FAILURE);
    }

    menu = std::make_unique<Menu>(DB_FILE);
}


std::shared_ptr<Message> Server::get_request()
{
    socklen_t sock_len = sizeof(client_address);
    int n = recvfrom(udp_socket, (char *)buffer, BUFFER_SIZE, MSG_WAITALL, (struct sockaddr *)&client_address, &sock_len);

    json payload = json::parse(buffer);

    return std::make_shared<Message>(
        payload["message_type"], 
        payload["request_id"], 
        payload["object_reference"], 
        payload["method_id"]
    );
}


void Server::send_response(const json &payload, socklen_t &sock_len)
{

    std::string payload_str = payload.dump();
    unsigned int payload_size = payload_str.size();

    memset(buffer, 0, BUFFER_SIZE);

    memcpy(buffer, &payload_size, sizeof(unsigned int));
    memcpy(buffer + sizeof(unsigned int), payload_str.c_str(), BUFFER_SIZE);

    sendto(udp_socket, buffer, BUFFER_SIZE, 0, (struct sockaddr *) &client_address, sock_len);
}


void Server::listen()
{

    socklen_t sock_len = sizeof(client_address);

    while (true)
    {
        std::cerr << "Server::listen(): Wait packets" << std::endl;
        
        std::shared_ptr<Message> message = this->get_request();

        std::cout << message->to_json().dump() << std::endl;

        this->send_response(menu->get_tables(), sock_len);

        std::cout << "Server::listen(): " << std::endl;
    }
}
