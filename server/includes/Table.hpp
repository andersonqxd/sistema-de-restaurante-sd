#ifndef __TABLE_HPP__
#define __TABLE_HPP__


#include <vector>
#include <string>
#include <memory>

#include "Order.hpp"

class Table
{

    int table_id;
    std::string client_name;
    std::vector<std::shared_ptr<Order>> orders;

    public:
        Table(int table_id, std::string client_name);

        /**
         * @brief Obtém todos os pedidos associados à instância.
         *
         * @return Um vetor de std::shared_ptr<Order> contendo todos os pedidos associados.
         */
        std::vector<std::shared_ptr<Order>> get_all_orders();

        /**
         * @brief Adiciona um novo pedido à instância.
         *
         * @param order_price Um float representando o preço total do pedido.
         * @param preparation_time Um float representando o tempo total de preparo do pedido.
         * @param products_ids Um vetor de inteiros contendo os identificadores únicos dos produtos no pedido.
         */
        void new_order(float order_price, float preparation_time, std::vector<int> products_ids);

};


#endif