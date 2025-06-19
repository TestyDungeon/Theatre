#include "movie.h"
#include "enums.h"
#include "theatre.h"

Movie::Movie(std::string title_, std::chrono::sys_seconds time_, double cost_, age age_restriction_):
    Session(title_, time_, cost_),
    age_restriction(age_restriction_)
{}


std::vector<Extras> Movie::get_supported_extras() const{
    return {Extras::Popcorn, Extras::Cola};
}

double Movie::calculate_price(const OrderRequest& req) const{
    double price = 0;
    price += req.number_of_tickets.at(SeatType::Regular) * cost * 1.0;
    price += req.number_of_tickets.at(SeatType::VIP) * cost * 1.5;
    if(std::count(req.extras.begin(), req.extras.end(), Extras::Popcorn))
        price += 3;
    if(std::count(req.extras.begin(), req.extras.end(), Extras::Cola))
        price += 1;  
    
    return price;
}

bool Movie::ticket_order(OrderRequest req){
    if(!parent_theatre->approve_order(*this, req))
        return false;
    
    for(auto seat : parent_theatre->get_available_seat_types()){
        if(seats_left[seat] - req.number_of_tickets.at(seat) < 0)
            return false;
    }

    if(req.age < static_cast<int>(age_restriction))
        return false;

    for(auto seat : parent_theatre->get_available_seat_types()){
        seats_left[seat] -= req.number_of_tickets.at(seat);
    }

    orders.push_back(req);

    return true;
}
