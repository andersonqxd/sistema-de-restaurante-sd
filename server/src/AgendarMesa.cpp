#include "AgedarMessa.hpp"


ReservarMesa::ReservarMesa() 
{
    reserva[1] = std::make_shared<std::string>("");
    reserva[2] = std::make_shared<std::string>("");
    reserva[3] = std::make_shared<std::string>("");
}


bool ReservarMesa::procMesa(int idMesa) {
    auto iter = reserva.find(idMesa);
    if (iter != reserva.end()) {
        return true;
    }
    return false;
};


void ReservarMesa::agendarMesa(const std::string& cliente, int IdMesa) {
    if(IdMesa>= totalDeMesas) {
        throw RestauranteLotado();
    };
    if(procMesa(IdMesa)) {
        throw MesaOcupada();
    }

    
    reserva[IdMesa] = std::make_shared<std::string>(cliente);
}


void ReservarMesa::cancelarMesa(int idMesa) {
    if(!procMesa(idMesa)) {
        SemReserva();
    }
    reserva.erase(idMesa);
}
