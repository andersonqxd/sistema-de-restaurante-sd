#include "Menu.hpp"


Menu::Menu( std::string file_name )
{
    this->file_name = file_name;

    parse_file();
}


void Menu::parse_file()
{
    std::ifstream file( file_name );

    if ( !file.is_open() )
    {
        std::cout << "Menu::parse_file(): Error open file \"" << file_name << '"' << std::endl;
        exit( EXIT_FAILURE );
    }

    std::string line;
    std::string content;

    while ( std::getline( file, line ) )
        content += line;

    file.close();

    try 
    {
        json_object = json::parse( content );
    }

    catch ( const json::parse_error& err ) 
    {
        std::cout << "Menu::parse_file(): Error parse file \"" << file_name << '"' << std::endl;
        exit( EXIT_FAILURE );
    }
}



json Menu::get_tables() 
{

    std::cout << json_object["tables"] << std::endl;
    
    return json( json_object[ "tables" ] );
}


void Menu::reserved_table_with_id(int table_id)
{
    json_object["tables"][std::to_string(table_id)]["reserved"] = true;
}
