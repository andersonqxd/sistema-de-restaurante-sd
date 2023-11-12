#include "restaurante.hpp"




Restaurante::Restaurante()
{
    menu = std::make_unique<Menu>(DB_FILE);
}


std::string Restaurante::get_tables()
{
    return menu->get_tables().dump();
}


std::string Restaurante::get_menu()
{
    return menu->get_menu().dump();
}


bool Restaurante::procMesa(int idMesa)
{
    auto iter = reserva.find(idMesa);

    if (iter != reserva.end())
        return true;

    return false;
}


std::string Restaurante::agendarMesa(const std::string& cliente, int IdMesa)
{
    reserva[IdMesa] = std::make_shared<std::string>(cliente);

    menu->reserved_table_with_id(IdMesa);

    return std::string("Mesa agendada com sucesso");
}


void Restaurante::fazerPedido(int numeroDaMesa, std::string nomeDoPedido, int idDoPedido)
{
    pedidos[numeroDaMesa] = std::make_shared<int>(idDoPedido);
    // std::cout << "Pedido feito com sucesso! Mesa: " << numeroDaMesa << ", Nome do pedido: " << nomeDoPedido << ", ID do pedido: " << idDoPedido << std::endl;
}


std::shared_ptr<int> Restaurante::consultarPedido( int idDoPedido)
{   
    return pedidos[idDoPedido];
}
