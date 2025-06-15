#include "session.h"
#include "../theatre/theatre.h"

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