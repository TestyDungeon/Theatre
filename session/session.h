#pragma once

#include <chrono>
#include <string>
#include <vector>
#include <unordered_map>
#include "../order_request/enums.h"
#include "../order_request/order_request.h"

class Theatre;

class Session{
protected:
    std::string title;
    std::chrono::sys_seconds time;
    double cost;
    std::unordered_map<SeatType, int> seats_left;
    
    Theatre* parent_theatre = nullptr;

    std::vector<OrderRequest> orders;
    Session(std::string title_, std::chrono::sys_seconds time_, double cost_);
public:

    void set_parent(Theatre* x);
    std::string get_title() const;

    int get_seats_left(SeatType x) const;

    bool ticket_order(OrderRequest req);

    std::string information() const;

    std::string order_information(const OrderRequest& o) const;

    int get_total_order_seats(const OrderRequest& o) const;

    std::vector<SeatType> get_seats_types() const;

    virtual std::vector<Extras> get_supported_extras() const=0;

    virtual double calculate_price(const OrderRequest& req) const = 0;

    virtual ~Session();
};