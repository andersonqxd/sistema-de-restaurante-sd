#ifndef __DISPACHANTE_HPP__
#define __DISPACHANTE_HPP__

#include "restaurante.hpp"
#include <string>

class Dispachante 
{
    Restaurante restaurante;

    public:

        std::string get_tables();
        std::string get_menu();
        std::string reserved_table(std::string client_name, int table_id);
        std::string new_order(int table_id, std::vector<int> products_ids);
};


#endif
