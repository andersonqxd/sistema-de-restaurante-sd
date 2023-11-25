#ifndef __RESTAURANTE_HPP__
#define __RESTAURANTE_HPP__


#include <iostream>
#include <map>
#include <memory>

#include "Menu.hpp"
#include "Order.hpp"
#include "Table.hpp"
#include "CustomExceptions.hpp"

#define DB_FILE       "./Mocks/db.json"


class Restaurante {
    private:
        std::map<int, std::shared_ptr<Table>> reserva;

        int totalDeMesas { 10 };
        Menu menu { DB_FILE };

    public:
        /**
         * @brief Obtém informações sobre as mesas do restaurante.
         *
         * Esta função retorna um ponteiro compartilhado para uma string contendo
         * a representação JSON das informações das mesas do restaurante.
         *
         * @note A representação JSON é gerada utilizando a função `dump` do objeto
         *       associado à variável `menu`.
         *
         * @return Um std::shared_ptr<std::string> contendo a representação JSON
         *         das informações das mesas do restaurante.
         */
        std::shared_ptr<std::string> get_tables();


        /**
         * @brief Obtém o menu do restaurante.
         *
         * Esta função retorna um ponteiro compartilhado para uma string contendo
         * a representação JSON do menu do restaurante.
         *
         * @note A representação JSON é gerada utilizando a função `dump` do objeto
         *       associado à variável `menu`.
         *
         * @return Um std::shared_ptr<std::string> contendo a representação JSON do menu.
         */
        std::shared_ptr<std::string> get_menu();

    
        /**
         * @brief Agenda uma mesa para um cliente no restaurante.
         *
         * Esta função reserva uma mesa para um cliente específico, associando a mesa
         * ao cliente e registrando a reserva. Se a mesa já estiver reservada, uma
         * exceção `TableAlredyReserved` será lançada.
         *
         * @param cliente Uma string contendo o nome do cliente para o qual a mesa
         *        está sendo agendada.
         *
         * @param IdMesa Um inteiro representando o identificador único da mesa a ser
         *        agendada.
         *
         * @return Um std::shared_ptr<std::string> contendo uma mensagem indicando que
         *         a mesa foi agendada com sucesso.
         *
         * @throws TableAlredyReserved Se a mesa já estiver reservada para outro cliente.
         */
        std::shared_ptr<std::string> agendarMesa(const std::string& cliente, int IdMesa);


        /**
         * @brief Realiza um novo pedido para uma mesa específica no restaurante.
         *
         * Esta função cria um novo pedido para uma mesa específica, calculando o tempo
         * de preparo e o preço total com base nos produtos solicitados. O pedido é
         * associado à mesa fornecida.
         *
         * @param table_id Um inteiro representando o identificador único da mesa para
         *        a qual o pedido está sendo feito.
         *
         * @param products_ids Um vetor de inteiros contendo os identificadores únicos
         *        dos produtos solicitados no pedido.
         *
         * @return Um std::shared_ptr<std::string> contendo uma mensagem indicando que
         *         o pedido foi feito com sucesso.
         *
         * @note A função utiliza as informações do menu para calcular o tempo de
         *       preparo e o preço total do pedido.
         */
        std::shared_ptr<std::string> new_order(int table_id, std::vector<int> products_ids);


        /**
         * @brief Obtém o status de todos os pedidos associados a uma mesa específica no restaurante.
         *
         * Esta função retorna uma representação JSON contendo o status de todos os pedidos
         * associados à mesa especificada.
         *
         * @param table_id Um inteiro representando o identificador único da mesa para
         *        a qual o status dos pedidos está sendo consultado.
         *
         * @return Um std::shared_ptr<std::string> contendo a representação JSON
         *         do status de todos os pedidos associados à mesa.
         *
         * @note A função obtém os pedidos associados à mesa através do objeto associado
         *       à variável `reserva` e retorna uma representação JSON dos estados desses pedidos.
         */
        std::shared_ptr<std::string> status_order(int table_id);
    
};


#endif