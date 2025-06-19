#include "cartoon.h"

Cartoon::Cartoon(std::string title_, std::chrono::sys_seconds time_, double cost_):
    Movie(title_, time_, cost_, age::G)
{}

double Cartoon::calculate_price(const OrderRequest& req) const{
    double price = 0;
    price += req.number_of_tickets.at(SeatType::Regular) * cost * 1.0;
    price += req.number_of_tickets.at(SeatType::VIP) * cost * 1.5;

    
    if(std::count(req.extras.begin(), req.extras.end(), Extras::Popcorn))
        price += 3;
    if(std::count(req.extras.begin(), req.extras.end(), Extras::Cola))
        price += 1;  
    
    if(req.age < 14)
        price *= 0.6;

    return price;
}