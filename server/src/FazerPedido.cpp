#include <iostream>
#include <string>
#include <map>
#include <memory>

class PedidoEmFalta : public std::exception {
public:
    const char* what() const throw() {
        return "Pedido em falta";
    }
};

class FazerPedido {
private:
    std::map<int, std::shared_ptr<int>> pedidos;

public:
    void fazerPedido(int numeroDaMesa, std::string nomeDoPedido, int idDoPedido) {
        if (pedidos.find(numeroDaMesa) != pedidos.end()) {
            throw PedidoEmFalta();
        }
        pedidos[numeroDaMesa] = std::make_shared<int>(idDoPedido);
        std::cout << "Pedido feito com sucesso! Mesa: " << numeroDaMesa << ", Nome do pedido: " << nomeDoPedido << ", ID do pedido: " << idDoPedido << std::endl;
    }

    void cancelarPedido(int numeroDaMesa) {
        if (pedidos.find(numeroDaMesa) == pedidos.end()) {
            throw PedidoEmFalta();
        }
        pedidos.erase(numeroDaMesa);
        std::cout << "Pedido cancelado com sucesso! Mesa: " << numeroDaMesa << std::endl;
    }
};
