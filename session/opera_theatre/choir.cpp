#include "choir.h"
#include "enums.h"
#include <algorithm>

Choir::Choir(std::string title_, std::chrono::sys_seconds time_, double cost_):
    Opera(title_, time_, cost_)
{}

std::vector<Extras> Choir::get_supported_extras() const{
    return {Extras::Donation};
}

double Choir::calculate_price(const OrderRequest& req) const{
    double price = 0;
    price += req.number_of_tickets.at(SeatType::Gallery) * cost * 1.0;
    price += req.number_of_tickets.at(SeatType::SecondBalcony) * cost * 1.0;
    price += req.number_of_tickets.at(SeatType::FirstBalcony) * cost * 1.0;
    price += req.number_of_tickets.at(SeatType::Stalls) * cost * 1.25;

    if(std::count(req.extras.begin(), req.extras.end(), Extras::Donation))
        price += 5;

    return price;
}