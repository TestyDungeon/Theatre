#pragma once

#include <chrono>
#include <vector>
#include "../order_request/enums.h"
#include "../order_request/order_request.h"

class Theatre;

class Session{
protected:
    std::string title;
    std::chrono::sys_seconds time;
    double cost;
    int seats_left;
    
    Theatre* parent_theatre = nullptr;

    std::vector<OrderRequest* > orders;
public:
    Session(std::string title_, std::chrono::sys_seconds time_, double cost_, int seats_left_);

    std::string get_title() const;

    void set_parent(Theatre* x);

    int get_seats_left() const;

    bool reserve_seats(int& left, const int& reserved);

    std::string information() const;

    virtual std::vector<Extras> get_supported_extras() const=0;
    virtual bool ordered(const OrderRequest& req)=0;

    virtual ~Session() = default;
};