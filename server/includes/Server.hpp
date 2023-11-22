#ifndef __SERVER_HPP__
#define __SERVER_HPP__


#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <memory>

#include "Globals.hpp"
#include "Message.hpp"
#include "esqueleto.hpp"

#define SERVER_PORT   7000
#define SERVER_IP     "127.0.0.1"

#define BUFFER_SIZE   2024


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

        Esqueleto esqueleto;
        std::shared_ptr<Message> old_message;

        inline void clear_buffer();
        inline int read_buffer();
        inline void write_buffer(const std::string &payload);

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


        /**
         * @brief Obtém uma solicitação (request) da aplicação.
         *
         * Esta função retorna um objeto std::shared_ptr<Message> que representa uma solicitação
         * da aplicação. Um std::shared_ptr é usado para compartilhar a propriedade do objeto
         * Message, garantindo que ele seja gerenciado adequadamente em termos de memória.
         *
         * @return Um std::shared_ptr<Message> que representa a solicitação da aplicação.
         */
        std::shared_ptr<Message> get_request();


        /**
         * @brief Envia uma resposta para um socket.
         *
         * Esta função envia uma resposta no formato JSON para um socket, especificado por seu comprimento
         * em `sock_len`. A resposta é fornecida como um objeto `json`, que contém os dados a serem enviados.
         *
         * @param payload Um objeto json contendo os dados a serem enviados como resposta.
         * @param sock_len Uma referência para a variável socklen_t que representa o comprimento do socket.
         */
        void send_response(std::shared_ptr<std::string> payload);
};


#endif