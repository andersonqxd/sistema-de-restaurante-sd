#include "esqueleto.hpp"


Esqueleto::Esqueleto()
{
    dispachante = std::make_unique<Dispachante>();
}


std::string Esqueleto::invoke(std::shared_ptr<Message> message)
{
    switch (message->get_method_id())
    {
    case 1:
        return dispachante->get_tables();
    
    case 2:
    {
        json arguments = json::parse(*message->get_arguments());
        json response;

        response["message"] = dispachante->reserved_table(arguments["client_name"], arguments["table_id"]);

        return response.dump();
    }
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

    return "";
}
