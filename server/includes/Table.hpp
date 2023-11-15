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

        std::vector<std::shared_ptr<Order>> get_all_orders();
        void new_order(float order_price, float preparation_time, std::vector<int> products_ids);

};


#endif