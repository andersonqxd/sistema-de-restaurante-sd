#ifndef __ORDER_CPP__
#define __ORDER_CPP__


#include <vector>
#include <memory>


enum OrderStatus {
    PREPARING,
    DONE,
};


class Order 
{
    private:
        int table_id;
        float order_price;
        float preparation_time;
        OrderStatus status;
        std::unique_ptr<std::vector<int>> products_ids;


    public:
        Order(int table_id, float order_price, float preparation_time, std::vector<int> products_ids, OrderStatus status);

        std::vector<int> get_products();
};


#endif