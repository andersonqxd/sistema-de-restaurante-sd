
#include <iostream>
#include <map>
#include <stdexcept>
#include <memory>


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
    void cancelarMesa(int idMesa) {
        if(!procMesa(idMesa)) {
            SemReserva();
        }
        reserva.erase(idMesa);
    }

};
