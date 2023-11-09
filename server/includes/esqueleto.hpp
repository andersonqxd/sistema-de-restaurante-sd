#ifndef __ESQUELETO_HPP__
#define __ESQUELETO_HPP__

#include <iostream>

#include "Message.hpp"
#include "Dispachante.hpp"


class Esqueleto
{
    std::unique_ptr<Dispachante> dispachante;

public:
    Esqueleto();

    std::string invoke(std::shared_ptr<Message> message);
};


#endif
