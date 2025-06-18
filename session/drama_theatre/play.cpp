#include "play.h"
#include "enums.h"

Play::Play(std::string title_, std::chrono::sys_seconds time_, double cost_):
    Session(title_, time_, cost_)
{}


std::vector<Extras> Play::get_supported_extras() const{
    return {Extras::Binocular, Extras::ProgramBooklet};
}


double Play::calculate_price(const OrderRequest& req) const{
    double price = 0;
    price += req.number_of_tickets.at(SeatType::Balcony) * cost * 1.0;
    price += req.number_of_tickets.at(SeatType::DressCircle) * cost * 1.25;
    price += req.number_of_tickets.at(SeatType::Parterre) * cost * 1.75;

    if(std::count(req.extras.begin(), req.extras.end(), Extras::Binocular))
        price += 2;

    if(std::count(req.extras.begin(), req.extras.end(), Extras::ProgramBooklet))
        price += 1;

    return price;
}