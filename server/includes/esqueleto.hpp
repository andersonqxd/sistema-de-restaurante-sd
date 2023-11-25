#ifndef __ESQUELETO_HPP__
#define __ESQUELETO_HPP__

#include <iostream>
#include <memory>

#include "Message.hpp"
#include "Dispachante.hpp"
#include "CustomExceptions.hpp"


#define GET_TABLES_RESTURANT         1
#define RESERVED_TABLE_RESTAURANT    2
#define CHECK_STATUS_ORDER           3
#define MAKE_WISH_RESTAURANT         4
#define GET_MENU_RESTAURANT          5


class Esqueleto
{
    Dispachante dispachante;

public:
    /**
     * @brief Invoca uma operação com base em uma mensagem JSON.
     *
     * Esta função recebe um ponteiro compartilhado para um objeto JSON contendo uma mensagem
     * e executa uma operação correspondente. O resultado da operação é encapsulado em uma
     * string e retornado como um ponteiro compartilhado.
     *
     * @param message Um std::shared_ptr<json> contendo a mensagem JSON que desencadeia a operação.
     *
     * @return Um std::shared_ptr<std::string> contendo o resultado da operação encapsulado em uma string.
     *
     * @note Esta função é projetada para ser utilizada como um ponto de entrada para execução
     *       de operações com base em mensagens JSON.
     */
    std::shared_ptr<std::string> invoke(std::shared_ptr<json> message);
};


#endif
