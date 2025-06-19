#include "session.h"
#include "../theatre/theatre.h"
#include "enums.h"
#include "order_request.h"
#include <string>
#include <unordered_map>


Session::Session(std::string title_, std::chrono::sys_seconds time_, double cost_):
    title(title_),
    time(time_),
    cost(cost_)
{}

std::string Session::get_title() const{
    return title;
}

double Session::get_cost() const{
    return cost;
}

std::chrono::sys_seconds Session::get_time() const{
    return time;
}

void Session::set_parent(Theatre* x){
    parent_theatre = x;
}

int Session::get_seats_left(SeatType x) const{
    return seats_left.at(x);
}

void Session::set_seats_left(const std::unordered_map<SeatType, int>& s){
    seats_left = s;
}


bool Session::ticket_order(OrderRequest req){
    if(!parent_theatre->approve_order(*this, req))
        return false;

    for(auto seat : parent_theatre->get_available_seat_types()){
        if(seats_left[seat] - req.number_of_tickets.at(seat) < 0)
            return false;
    }

    for(auto seat : parent_theatre->get_available_seat_types()){
        seats_left[seat] -= req.number_of_tickets.at(seat);
    }

    orders.push_back(req);

    return true;
}


std::string Session::information() const{
    std::string info = 
    title +
    "\nTime: " + std::format("{:%Y-%m-%d %H:%M}", time) +
    "\nCost: " + std::to_string(cost) + " USD" +
    "\nAddress: " + parent_theatre->get_address();
    return info;
}

std::string Session::order_information(const OrderRequest& o) const{
    std::string s = 
    "Name: " + o.name + "\n" +
    "Surname: " + o.surname + "\n";
    for(auto cell : o.number_of_tickets){
        s += seat_type_to_string(cell.first) + ": " + std::to_string(cell.second) + " ticket(s)" + "\n";
    }
    for(auto cell : o.extras){
        s += extra_to_string(cell) + "\n";
    }
    s += "Total cost: " + std::to_string(calculate_price(o)) + "\n";
    return s;
}

int Session::get_total_order_seats(const OrderRequest& o) const{
    int total = 0;
    for(auto cell : o.number_of_tickets){
        total += cell.second;
    }
    return total;
}

std::vector<SeatType> Session::get_seats_types() const{
    return parent_theatre->get_available_seat_types();
}

Session::~Session(){

}