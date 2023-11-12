#ifndef __RESTAURANTE_HPP__
#define __RESTAURANTE_HPP__


#include <iostream>
#include <map>
#include <exception>
#include <memory>

#include "Menu.hpp"

#define DB_FILE       "./Mocks/db.json"

// class PedidoEmFalta : public std::exception {
// public:
//     const char* what() const throw() {
//         return "Pedido em falta.";
//     }
// };

// class MesaNaoEncontrada : public std::exception {
// public:
//     const char* what() const throw() {
//         return "Mesa não encontrada.";
//     }
// };

// class MesaOcupada : public std::runtime_error {
//     public:
//         MesaOcupada() : std::runtime_error("A mesa já está ocupada") {}
// };

// class RestauranteLotado : public std::runtime_error {
//     public:
//         RestauranteLotado() : std::runtime_error("O restaurante está lotado") {}
// };

// class SemReserva : public std::runtime_error {
//     public:
//         SemReserva() : std::runtime_error("Cliente não tem reservas") {}
// };

// class PedidoEmFalta : public std::exception {
// public:
//     const char* what() const throw() {
//         return "Pedido em falta";
//     }
// };


// CLASS RESTAURANTE //

class Restaurante {
    private:
        std::map<int, std::shared_ptr<std::string>> reserva;
        std::map<int, std::shared_ptr<int>> pedidos;
        int totalDeMesas = 10;

        std::unique_ptr<Menu> menu;

    public:

    Restaurante();

    std::string get_tables();
    std::string get_menu();
    
    bool procMesa(int idMesa);
    std::string agendarMesa(const std::string& cliente, int IdMesa);
    void fazerPedido(int numeroDaMesa, std::string nomeDoPedido, int idDoPedido);
    std::shared_ptr<int> consultarPedido( int idDoPedido);
};


#endif