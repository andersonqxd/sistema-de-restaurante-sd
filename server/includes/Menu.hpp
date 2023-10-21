#ifndef __MENU_HPP__
#define __MENU_HPP__


#include "Globals.hpp"
#include <fstream>


class Menu 
{
    private:
        json json_object;
        std::string file_name;

        void parse_file();

    public:
        Menu( std::string file_name );

        json get_tables();
};


#endif