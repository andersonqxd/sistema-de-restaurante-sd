#ifndef __ESQUELETO_HPP__
#define __ESQUELETO_HPP__

#include <iostream>
#include <memory>

#include "Message.hpp"
#include "Dispachante.hpp"
#include "CustomExceptions.hpp"


#define GET_TABLES_RESTURANT         1
#define RESERVED_TABLE_RESTAURANT    2
#define CHECK_STATUS_ORDER           3
#define MAKE_WISH_RESTAURANT         4
#define GET_MENU_RESTAURANT          5


class Esqueleto
{
    Dispachante dispachante;

public:
    std::shared_ptr<std::string> invoke(std::shared_ptr<json> message);
};


#endif
