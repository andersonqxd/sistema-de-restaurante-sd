#ifndef __ESQUELETO_HPP__
#define __ESQUELETO_HPP__

#include <iostream>
#include <memory>

#include "Message.hpp"
#include "Dispachante.hpp"


class Esqueleto
{
    Dispachante dispachante;

public:
    std::shared_ptr<std::string> invoke(std::shared_ptr<json> message);
};


#endif
