#include "opera.h"

Opera::Opera(std::string title_, std::chrono::sys_seconds time_, double cost_, int seats_left_, int balcony_seats_left_):
    Session(title_, time_, cost_, seats_left_),
    balcony_seats_left(balcony_seats_left_)
{}

void Opera::handle_extras(const std::vector<Extras>& ext){};

bool Opera::ordered(const OrderRequest& req){
    handle_extras(req.extras);

    if(std::count(req.extras.begin(), req.extras.end(), Extras::Balcony)){
        return reserve_seats(balcony_seats_left, req.number_of_tickets);
    }
    else
        return reserve_seats(seats_left, req.number_of_tickets);

}