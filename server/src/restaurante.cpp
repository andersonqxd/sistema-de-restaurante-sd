#include "restaurante.hpp"


std::shared_ptr<std::string> Restaurante::get_tables()
{
    return std::make_shared<std::string>(menu.get_tables().dump());
}


std::shared_ptr<std::string> Restaurante::get_menu()
{
    return std::make_shared<std::string>(menu.get_menu().dump());
}


std::shared_ptr<std::string> Restaurante::agendarMesa(const std::string& cliente, int IdMesa)
{

    auto interator = reserva.find(IdMesa);

    if (interator != reserva.end())
        throw TableAlredyReserved("Mesa ja esta ocupada");


    reserva[IdMesa] = std::make_shared<Table>(IdMesa, cliente);

    menu.reserved_table_with_id(IdMesa);

    return std::make_shared<std::string>("Mesa agendada com sucesso");
}


std::shared_ptr<std::string> Restaurante::status_order(int table_id)
{
    json orders_status;

    std::vector<std::shared_ptr<Order>> orders = reserva[table_id]->get_all_orders();

    for (int index = 0; index < orders.size(); index++)
        orders_status[std::to_string(index)] = orders[index]->get_status();

    return std::make_shared<std::string>(orders_status.dump());
}


std::shared_ptr<std::string> Restaurante::new_order(int table_id, std::vector<int> products_ids)
{
    float order_time { 0.0 };
    float order_price { 0.0 };

    for (int id = 0; id < products_ids.size(); id++)
    {
        json order = menu.get_order(products_ids[id]);

        order_time += static_cast<float>(order["preparation_time"]);
        order_price += static_cast<float>(order["price"]);
    }


    reserva[table_id]->new_order(order_price, order_time, products_ids);

    return std::make_shared<std::string>("pedido feito com sucesso");
}
