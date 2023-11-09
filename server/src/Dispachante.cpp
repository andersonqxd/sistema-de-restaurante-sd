#include "Dispachante.hpp"


Dispachante::Dispachante()
{
    restaurante = std::make_unique<Restaurante>();
}


std::string Dispachante::get_tables()
{
    return restaurante->get_tables();
}

