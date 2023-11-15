#include "restaurante.hpp"


std::shared_ptr<std::string> Restaurante::get_tables()
{
    return std::make_shared<std::string>(menu.get_tables().dump());
}


std::shared_ptr<std::string> Restaurante::get_menu()
{
    return std::make_shared<std::string>(menu.get_menu().dump());
}


bool Restaurante::procMesa(int idMesa)
{
    auto iter = reserva.find(idMesa);

    if (iter != reserva.end())
        return true;

    return false;
}


std::shared_ptr<std::string> Restaurante::agendarMesa(const std::string& cliente, int IdMesa)
{
    reserva[IdMesa] = std::make_shared<std::string>(cliente);

    menu.reserved_table_with_id(IdMesa);

    return std::make_shared<std::string>("Mesa agendada com sucesso");
}



std::shared_ptr<Order> Restaurante::consultarPedido( int idDoPedido)
{   
    return pedidos[idDoPedido];
}


std::shared_ptr<std::string> Restaurante::new_order(int table_id, std::vector<int> products_ids)
{
    int order_time = 0;
    float order_price = 0.0;

    for (int id = 0; id < products_ids.size(); id++)
    {
        json order = menu.get_order(products_ids[id]);


        order_time += static_cast<float>(order["preparation_time"]);
        order_price += static_cast<float>(order["price"]);
    }


    pedidos[table_id] = std::make_shared<Order>(table_id, order_price, order_time, products_ids, OrderStatus::PREPARING);

    return std::make_shared<std::string>("pedido feito com sucesso");
}
