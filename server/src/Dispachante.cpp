#include "Dispachante.hpp"


Dispachante::Dispachante()
{
    restaurante = std::make_unique<Restaurante>();
}


std::string Dispachante::get_tables()
{
    return restaurante->get_tables();
}


std::string Dispachante::get_menu()
{
    return restaurante->get_menu();
}

std::string Dispachante::reserved_table(std::string client_name, int table_id)
{
    return restaurante->agendarMesa(client_name, table_id);
}

