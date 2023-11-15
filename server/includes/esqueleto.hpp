#ifndef __ESQUELETO_HPP__
#define __ESQUELETO_HPP__

#include <iostream>

#include "Message.hpp"
#include "Dispachante.hpp"


class Esqueleto
{
    Dispachante dispachante;

public:
    std::string invoke(std::shared_ptr<Message> message);
};


#endif
