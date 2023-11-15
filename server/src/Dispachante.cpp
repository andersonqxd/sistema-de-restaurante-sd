#include "Dispachante.hpp"


std::string Dispachante::get_tables()
{
    return restaurante.get_tables();
}


std::string Dispachante::get_menu()
{
    return restaurante.get_menu();
}

std::string Dispachante::reserved_table(std::string client_name, int table_id)
{
    return restaurante.agendarMesa(client_name, table_id);
}


std::string Dispachante::new_order(int table_id, std::vector<int> products_ids)
{
    return restaurante.new_order(table_id, products_ids);
}

