#include "esqueleto.hpp"


std::shared_ptr<std::string> Esqueleto::invoke(std::shared_ptr<json> message)
{
    switch (message->at("method_id").get<int>())
    {
        case GET_TABLES_RESTURANT:
        {
            json response;

            try 
            {
                response["tables"] = *dispachante.get_tables();
                response["status"] = OK;
            }

            catch (const std::exception& err)
            {
                response["message"] = "Server Error";
                response["status"] = INTERNAL_ERROR;
            }

            return std::make_shared<std::string>(response.dump());
        }
        
        case RESERVED_TABLE_RESTAURANT:
        {
            json response;

            try 
            {
                json arguments = json::parse(message->at("arguments").get<std::string>());

                response["message"] = *dispachante.reserved_table(arguments["client_name"], arguments["table_id"]);
                response["status"] = OK;
            }

            catch (const TableAlredyReserved& table_exception)
            {
                response["message"] = table_exception.what();
                response["status"] = BAB_REQUEST;
            }

            catch (const std::exception& err)
            {
                response["message"] = "Server Error";
                response["status"] = INTERNAL_ERROR;
            }


            return std::make_shared<std::string>(response.dump());
        }

        case CHECK_STATUS_ORDER:
        {
            json response;

            try
            {
                json arguments = json::parse(message->at("arguments").get<std::string>());

                response["orders"] = *dispachante.check_status_order(arguments["table_id"]);
                response["status"] = OK;
            }

            catch (const std::exception& err)
            {
                response["message"] = "Server Error";
                response["status"] = INTERNAL_ERROR;
            }

            return std::make_shared<std::string>(response.dump());
        }

        case MAKE_WISH_RESTAURANT:
        {
            json response;

            try 
            {
                json arguments = json::parse(message->at("arguments").get<std::string>());

                response["message"] = *dispachante.new_order(arguments["table_id"], arguments["products"]);
                response["status"] = OK;
            }

            catch (const std::exception& err)
            {
                response["message"] = "Server Error";
                response["status"] = INTERNAL_ERROR;
            }
            
            return std::make_shared<std::string>(response.dump());
        }

        case GET_MENU_RESTAURANT:
        {
            json response;

            try
            {
                response["menu"] = *dispachante.get_menu();
                response["status"] = OK;
            }

            catch (std::exception& err)
            {
                response["message"] = "Server Error";
                response["status"] = INTERNAL_ERROR;
            }

            return std::make_shared<std::string>(response.dump());
        }


        default:
        {
            json response;

            response["message"] = "Metodo não encontrado";
            response["status"] = INTERNAL_ERROR;

            return std::make_shared<std::string>(response.dump());
        }

    }
}
