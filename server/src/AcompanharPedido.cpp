#include <iostream>
#include <map>
#include <exception>

class PedidoEmFalta : public std::exception {
public:
    const char* what() const throw() {
        return "Pedido em falta.";
    }
};

class MesaNaoEncontrada : public std::exception {
public:
    const char* what() const throw() {
        return "Mesa não encontrada.";
    }
};

class FazerPedido {
private:
    std::map<int, int> pedidos;

public:
    void fazerPedido(int mesa, int idPedido) {
        if (pedidos.find(mesa) != pedidos.end()) {
            throw PedidoEmFalta();
        };
    }

    std::pair<std::string, int> obterStatus(int mesa) {

        if (pedidos.find(mesa) == pedidos.end()) {
            throw MesaNaoEncontrada();
        }

        // Em espera, preparando entregue
        std::pair<std::string, int> status;

        // Exemplo: retornar status do pedido na mesa específica
        // status.first = "Em espera";
        // status.second = pedidos[mesa];

        return status;
    }
};