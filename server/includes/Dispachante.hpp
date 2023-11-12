#ifndef __DISPACHANTE_HPP__
#define __DISPACHANTE_HPP__

#include "restaurante.hpp"
#include <string>

class Dispachante 
{
    std::unique_ptr<Restaurante> restaurante;

    public:
        Dispachante();

        std::string get_tables();
        std::string get_menu();
        std::string reserved_table(std::string client_name, int table_id);
};


#endif
