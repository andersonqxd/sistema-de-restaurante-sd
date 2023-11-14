#include "Order.hpp"


Order::Order(int table_id, float order_price, float preparation_time, std::vector<int> products_ids, OrderStatus status = OrderStatus::PREPARING)
{
    this->table_id = table_id;
    this->order_price = order_price;
    this->preparation_time = preparation_time;
    this->status = status;
    this->products_ids = std::make_unique<std::vector<int>>(products_ids);
}



std::vector<int> Order::get_products()
{
    return *this->products_ids;
}
