#ifndef __DISPACHANTE_HPP__
#define __DISPACHANTE_HPP__

#include "restaurante.hpp"
#include <string>

class Dispachante 
{
    Restaurante restaurante;

    public:

        /**
         * @brief Obtém as informações sobre as mesas do restaurante.
         *
         * Esta função delega a chamada para a função `get_tables` da classe `Restaurante`
         * e retorna um ponteiro compartilhado para uma string contendo a representação JSON
         * das informações das mesas do restaurante.
         *
         * @return Um std::shared_ptr<std::string> contendo a representação JSON
         *         das informações das mesas do restaurante.
         *
         * @note Esta função atua como um intermediário, proporcionando acesso às informações
         *       das mesas do restaurante por meio da classe `Restaurante`.
         */
        std::shared_ptr<std::string> get_tables();


        /**
         * @brief Obtém o menu do restaurante.
         *
         * Esta função delega a chamada para a função `get_menu` da classe `Restaurante`
         * e retorna um ponteiro compartilhado para uma string contendo a representação JSON
         * do menu do restaurante.
         *
         * @return Um std::shared_ptr<std::string> contendo a representação JSON do menu
         *         do restaurante.
         *
         * @note Esta função atua como um intermediário, proporcionando acesso ao menu
         *       do restaurante por meio da classe `Restaurante`.
         */
        std::shared_ptr<std::string> get_menu();


        /**
         * @brief Reserva uma mesa para um cliente no restaurante.
         *
         * Esta função delega a chamada para a função `agendarMesa` da classe `Restaurante`,
         * agendando uma mesa para um cliente específico com base no nome do cliente e no
         * identificador único da mesa.
         *
         * @param client_name Uma string contendo o nome do cliente para o qual a mesa
         *        está sendo reservada.
         *
         * @param table_id Um inteiro representando o identificador único da mesa a ser
         *        reservada.
         *
         * @return Um std::shared_ptr<std::string> contendo uma mensagem indicando se
         *         a reserva da mesa foi realizada com sucesso.
         *
         * @throws TableAlredyReserved Se a mesa já estiver reservada para outro cliente.
         *
         * @note Esta função atua como um intermediário, proporcionando acesso à reserva
         *       de mesas por meio da classe `Restaurante`.
         */
        std::shared_ptr<std::string> reserved_table(std::string client_name, int table_id);


        /**
         * @brief Realiza um novo pedido para uma mesa específica no restaurante.
         *
         * Esta função delega a chamada para a função `new_order` da classe `Restaurante`,
         * criando um novo pedido para uma mesa específica com base no identificador único
         * da mesa e nos identificadores únicos dos produtos solicitados.
         *
         * @param table_id Um inteiro representando o identificador único da mesa para
         *        a qual o pedido está sendo feito.
         *
         * @param products_ids Um vetor de inteiros contendo os identificadores únicos
         *        dos produtos solicitados no pedido.
         *
         * @return Um std::shared_ptr<std::string> contendo uma mensagem indicando se
         *         o pedido foi realizado com sucesso.
         *
         * @note Esta função atua como um intermediário, proporcionando acesso à realização
         *       de pedidos por meio da classe `Restaurante`.
         */
        std::shared_ptr<std::string> new_order(int table_id, std::vector<int> products_ids);

        /**
         * @brief Obtém o status de todos os pedidos associados a uma mesa específica no restaurante.
         *
         * Esta função delega a chamada para a função `status_order` da classe `Restaurante`,
         * retornando uma representação JSON contendo o status de todos os pedidos associados
         * à mesa especificada.
         *
         * @param table_id Um inteiro representando o identificador único da mesa para
         *        a qual o status dos pedidos está sendo consultado.
         *
         * @return Um std::shared_ptr<std::string> contendo a representação JSON
         *         do status de todos os pedidos associados à mesa.
         *
         * @note Esta função atua como um intermediário, proporcionando acesso ao status
         *       dos pedidos por meio da classe `Restaurante`.
         */
        std::shared_ptr<std::string> check_status_order(int table_id);
};


#endif
