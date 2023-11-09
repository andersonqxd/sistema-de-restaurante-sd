#include "restaurante.hpp"


bool Restaurante::procMesa(int idMesa)
{
    auto iter = reserva.find(idMesa);

    if (iter != reserva.end())
        return true;

    return false;
}


void Restaurante::agendarMesa(const std::string& cliente, int IdMesa)
{
    if(IdMesa>= totalDeMesas)
        throw RestauranteLotado();
    
    if(procMesa(IdMesa))
        throw MesaOcupada();
    

    reserva[IdMesa] = std::make_shared<std::string>(cliente);
}


void Restaurante::fazerPedido(int numeroDaMesa, std::string nomeDoPedido, int idDoPedido)
{
    if (pedidos.find(numeroDaMesa) != pedidos.end())
        throw PedidoEmFalta();

    pedidos[numeroDaMesa] = std::make_shared<int>(idDoPedido);
    // std::cout << "Pedido feito com sucesso! Mesa: " << numeroDaMesa << ", Nome do pedido: " << nomeDoPedido << ", ID do pedido: " << idDoPedido << std::endl;
}


std::shared_ptr<int> Restaurante::consultarPedido( int idDoPedido)
{
    if (pedidos.find(idDoPedido) == pedidos.end())
        throw PedidoEmFalta();
    
    return pedidos[idDoPedido];
}
