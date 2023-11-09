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
};


#endif
