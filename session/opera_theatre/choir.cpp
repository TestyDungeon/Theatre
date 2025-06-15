#include "choir.h"
#include "enums.h"

Choir::Choir(std::string title_, std::chrono::sys_seconds time_, double cost_, int seats_left_, int balcony_seats_left_):
    Opera(title_, time_, cost_, seats_left_, balcony_seats_left_)
{}

std::vector<Extras> Choir::get_supported_extras() const{
    return {Extras::Donation, Extras::Balcony};
}

bool Choir::ordered(const OrderRequest& req){
    if(std::count(req.extras.begin(), req.extras.end(), Extras::Balcony)){
        return reserve_seats(balcony_seats_left, req.number_of_tickets);
    }
    else
        return reserve_seats(seats_left, req.number_of_tickets);

}