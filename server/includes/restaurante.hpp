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
        std::shared_ptr<std::string> get_tables();
        std::shared_ptr<std::string> get_menu();
    
        std::shared_ptr<std::string> agendarMesa(const std::string& cliente, int IdMesa);
        std::shared_ptr<std::string> new_order(int table_id, std::vector<int> products_ids);
        std::shared_ptr<std::string> status_order(int table_id);
    
};


#endif