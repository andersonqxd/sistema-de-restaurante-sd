#ifndef __SERVER_HPP__
#define __SERVER_HPP__


#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include "Globals.hpp"

#define SERVER_PORT   7000
#define SERVER_IP     "127.0.0.1"

#define BUFFER_SIZE   1024


/**
 * @class Server
 * @brief Classe que representa um servidor UDP simples.
 *
 * Esta classe permite criar e configurar um servidor UDP que pode receber e processar datagramas UDP.
 */
class Server
{
    private:
        int udp_socket;

        char * buffer;

        struct sockaddr_in server_address;
        struct sockaddr_in client_address;

    public:
        /**
         * @brief Construtor padrão da classe Server.
         *
         * Este construtor inicializa os membros de dados da classe e inicia o servidor.
         */
        Server();

        /**
         * @brief Função para ouvir e processar datagramas UDP.
         *
         * Esta função coloca o servidor em execução e aguarda datagramas UDP.
         * Quando um datagrama é recebido, ele pode ser processado conforme necessário.
         */
        void listen();
};


#endif