#include "session.h"
#include "../theatre/theatre.h"
#include "order_request.h"
#include <string>

Session::Session(std::string title_, std::chrono::sys_seconds time_, double cost_, int seats_left_):
    title(title_),
    time(time_),
    cost(cost_),
    seats_left(seats_left_)
{}

std::string Session::get_title() const{
    return title;
}

void Session::set_parent(Theatre* x){
    parent_theatre = x;
}

int Session::get_seats_left() const{
    return seats_left;
}


bool Session::reserve_seats(int& left, const int& reserved){
    if(left - reserved >= 0){
        left -= reserved;
        return true;
    }
    return false;
}


std::string Session::information() const{
    std::string info = 
    title +
    "\nTime: " + std::format("{:%Y-%m-%d %H:%M}", time) +
    "\nCost: " + std::to_string(cost) +
    "\nAddress: " + parent_theatre->get_address();
    return info;
}

void Session::append_order(OrderRequest o){
    orders.push_back(o);
    ordered(o);
}

int Session::find_seat(const OrderRequest& o) const{
    for(int i = 0; i < orders.size(); i++){
        if(orders[i] == o)
            return i+1;
    }
    throw std::runtime_error("Order not found.");

}

std::string Session::order_information(const OrderRequest& o) const{
    std::string s = 
    std::string("|Your order information you will have to show at the entrance|\n") +
    "Name: " + o.name + "\n" +
    "Surname: " + o.surname + "\n" +
    std::to_string(o.number_of_tickets) + " tickets" + "\n" +
    "Seat number " + std::to_string(find_seat(o)) + "\n";

    return s;
}