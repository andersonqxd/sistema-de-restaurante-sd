#include "esqueleto.hpp"

class esqueleto {
public:
std::string get_metodos(Message message){
    std::string metodo = "";
    switch (message.get_method_id())
    {
    case 1:
        /* despachante.getTables() */
        break;
    case 2:
        /* json Argumentos = json::parse(message->get_arguments());
         std:: string nomeDoCliente = objeto["nome"];
         int idMesa = objeto["idMesa"];

        despachante.resevarMesa(string nomeDoCliente, idMesa);
        */
        break;
    case 3:
        /*
        json Argumentos = json::parse(message->get_arguments());
         std:: string idPedido = objeto["IdPedido"];
         despachante.consultaPedido(IdPedido) */
        break;
    case 4:
        /*
        json Argumentos = json::parse(message->get_arguments());
         std:: string idPedido = objeto["IdPedido"];
         int idMesa = objeto["idMesa"]; 
        despachante.fazerPedido(IdPedido, idMesa) */
        break;
    case 5:
        /* despachante.getMenu() */
        break;

    default:
        break;
        }
    }
    
};