#include "Table.hpp"


Table::Table(int table_id, std::string client_name)
{
    this->table_id = table_id;
    this->client_name = client_name;
}


void Table::new_order(float order_price, float preparation_time, std::vector<int> products_ids)
{
    orders.push_back(std::make_shared<Order>(this->table_id, order_price, preparation_time, products_ids, OrderStatus::PREPARING));
}


std::vector<std::shared_ptr<Order>> Table::get_all_orders()
{
    return this->orders;
}

