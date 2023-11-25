#ifndef __MESSAGE_HPP__
#define __MESSAGE_HPP__

#include "Globals.hpp"

/**
 * @enum MessageType
 * @brief Enumeração que define os tipos de mensagens.
 *
 * Esta enumeração define os tipos de mensagens usados na comunicação do sistema.
 */
enum MessageType {
    MSG_REQUEST = 0,
    MSG_REPLY = 1,
};


/**
 * @class Message
 * @brief Classe que representa uma mensagem em comunicação do sistema.
 *
 * Esta classe encapsula informações de uma mensagem usada na comunicação.
 */
class Message 
{
    private:
        MessageType message_type;
        int request_id;
        std::string object_reference;
        int method_id;
        std::string arguments;

    public:
        /**
         * @brief Construtor da classe Message.
         * 
         * @param message_type O tipo da mensagem (MSG_REQUEST ou MSG_REPLY).
         * @param request_id O ID da solicitação.
         * @param object_reference A referência ao objeto relacionado à mensagem.
         * @param method_id O ID do método associado à mensagem.
         */
        Message( MessageType message_type, int request_id, std::string object_reference, int method_id, std::string arguments);


        /**
         * @brief Converte a mensagem em um objeto JSON.
         * @return Um objeto JSON representando a mensagem.
         */
        json to_json();


        /**
         * @brief Obtém o tipo de mensagem associado à instância.
         *
         * @return Um MessageType indicando o tipo de mensagem associado.
         */
        MessageType get_message_type();

        /**
         * @brief Obtém o identificador único da solicitação associado à instância.
         *
         * @return Um inteiro representando o identificador único da solicitação.
         */
        int get_request_id();

        /**
         * @brief Obtém a referência do objeto associada à instância.
         *
         * @return Uma string contendo a referência do objeto associada.
         */
        std::string get_object_reference();

        /**
         * @brief Obtém o identificador do método associado à instância.
         *
         * @return Um inteiro representando o identificador do método associado.
         */
        int get_method_id();

        /**
         * @brief Obtém os argumentos associados à instância.
         *
         * @return Uma string contendo os argumentos associados.
         */
        std::string get_arguments();
};


#endif
