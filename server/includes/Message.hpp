#ifndef __MESSAGE_HPP__
#define __MESSAGE_HPP__

#include "Globals.hpp"

/**
 * @enum MessageType
 * @brief Enumeração que define os tipos de mensagens.
 *
 * Esta enumeração define os tipos de mensagens usados na comunicação do sistema.
 */
enum MesssageType {
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
        MesssageType message_type;
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
        Message( MesssageType message_type, int request_id, std::string object_reference, int method_id, std::string arguments);


        /**
         * @brief Converte a mensagem em um objeto JSON.
         * @return Um objeto JSON representando a mensagem.
         */
        json to_json();


        MesssageType get_message_type();
        int get_request_id();
        std::string get_object_reference();
        int get_method_id();
        std::shared_ptr<std::string> get_arguments();
};


#endif
