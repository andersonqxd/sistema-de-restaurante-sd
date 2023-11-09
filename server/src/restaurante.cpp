#include <iostream>
#include <map>
#include <exception>
#include <memory>

// EXEÇÕES //

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

class MesaOcupada : public std::runtime_error {
    public:
        MesaOcupada() : std::runtime_error("A mesa já está ocupada") {}
};

class RestauranteLotado : public std::runtime_error {
    public:
        RestauranteLotado() : std::runtime_error("O restaurante está lotado") {}
};

class SemReserva : public std::runtime_error {
    public:
        SemReserva() : std::runtime_error("Cliente não tem reservas") {}
};

class PedidoEmFalta : public std::exception {
public:
    const char* what() const throw() {
        return "Pedido em falta";
    }
};


// CLASS RESTAURANTE //

class Restaurante {
     private:
        std::map<int, std::shared_ptr<std::string>> reserva;
        std::map<int, std::shared_ptr<int>> pedidos;
        int totalDeMesas = 10;
    public:

    bool procMesa(int idMesa) {
        auto iter = reserva.find(idMesa);
        if (iter != reserva.end()) {
            return true;
        }
        return false;
    };

    void agendarMesa(const std::string& cliente, int IdMesa) {
        if(IdMesa>= totalDeMesas) {
            throw RestauranteLotado();
        };
        if(procMesa(IdMesa)) {
            throw MesaOcupada();
        }
        reserva[IdMesa] = std::make_shared<std::string>(cliente);
    }

    void fazerPedido(int numeroDaMesa, std::string nomeDoPedido, int idDoPedido) {
        if (pedidos.find(numeroDaMesa) != pedidos.end()) {
            throw PedidoEmFalta();
        }
        pedidos[numeroDaMesa] = std::make_shared<int>(idDoPedido);
        std::cout << "Pedido feito com sucesso! Mesa: " << numeroDaMesa << ", Nome do pedido: " << nomeDoPedido << ", ID do pedido: " << idDoPedido << std::endl;
    }


    std::shared_ptr<int> consultarPedido( int idDoPedido) {
        if (pedidos.find(idDoPedido) == pedidos.end()) {
            throw PedidoEmFalta();
        }
        return pedidos[idDoPedido];
        
        }
};