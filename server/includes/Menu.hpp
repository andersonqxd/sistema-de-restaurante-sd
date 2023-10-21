#ifndef __MENU_HPP__
#define __MENU_HPP__


#include "Globals.hpp"
#include <fstream>

/**
 * @class Server
 * @brief Classe que representa e manipula o menu do servico.
 *
 * Esta classe ler o menu e implementa a logica para resuperar dados do sistema
 */
class Menu 
{
    private:
        json json_object;
        std::string file_name;

        void parse_file();

    public:
        /**
         * @brief Construtor padrão da classe Menu.
         *
         * Este construtor inicializa os membros de dados da classe e faz um parse do arquivo para json.
         */
        Menu( std::string file_name );


        /**
         * @brief Este metodo retorna as messas registradas no sistema.
         *
         * @return Retorna um Json com os as messas registradas no sistema.
         */
        json get_tables();
};


#endif