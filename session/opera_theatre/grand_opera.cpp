#include "grand_opera.h"
#include "enums.h"

GrandOpera::GrandOpera(std::string title_, std::chrono::sys_seconds time_, double cost_):
    Opera(title_, time_, cost_)
{}

std::vector<Extras> GrandOpera::get_supported_extras() const{
    return {Extras::Binocular};
}

double GrandOpera::calculate_price(const OrderRequest& req) const{
    double price = 0;
    price += req.number_of_tickets.at(SeatType::Gallery) * cost * 1.0;
    price += req.number_of_tickets.at(SeatType::SecondBalcony) * cost * 1.50;
    price += req.number_of_tickets.at(SeatType::FirstBalcony) * cost * 1.75;
    price += req.number_of_tickets.at(SeatType::Stalls) * cost * 2.0;

    if(get_total_order_seats(req) > 5)
        price *= 0.9;

    return price;
}