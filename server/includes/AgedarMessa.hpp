#ifndef __AGENDAR_MESSA_HPP__
#define __AGENDAR_MESSA_HPP__

#include <iostream>
#include <map>
#include <stdexcept>
#include <memory>
#include <string>

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


class ReservarMesa {
    private:
        std::map<int, std::shared_ptr<std::string>> reserva;
        int totalDeMesas = 10;

    public:
        ReservarMesa();
        bool procMesa(int idMesa);
        void agendarMesa(const std::string& cliente, int IdMesa);
        void cancelarMesa(int idMesa);

};

#endif