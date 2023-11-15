#include "Dispachante.hpp"


std::shared_ptr<std::string> Dispachante::get_tables()
{
    return restaurante.get_tables();
}


std::shared_ptr<std::string> Dispachante::get_menu()
{
    return restaurante.get_menu();
}

std::shared_ptr<std::string> Dispachante::reserved_table(std::string client_name, int table_id)
{
    return restaurante.agendarMesa(client_name, table_id);
}


std::shared_ptr<std::string> Dispachante::new_order(int table_id, std::vector<int> products_ids)
{
    return restaurante.new_order(table_id, products_ids);
}


std::shared_ptr<std::string> Dispachante::check_status_order(int table_id)
{
    return restaurante.status_order(table_id);
}
