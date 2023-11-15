#ifndef __DISPACHANTE_HPP__
#define __DISPACHANTE_HPP__

#include "restaurante.hpp"
#include <string>

class Dispachante 
{
    Restaurante restaurante;

    public:

        std::shared_ptr<std::string> get_tables();
        std::shared_ptr<std::string> get_menu();
        std::shared_ptr<std::string> reserved_table(std::string client_name, int table_id);
        std::shared_ptr<std::string> new_order(int table_id, std::vector<int> products_ids);
        std::shared_ptr<std::string> check_status_order(int table_id);
};


#endif
