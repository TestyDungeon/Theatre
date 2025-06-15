#include "movie.h"
#include "enums.h"

Movie::Movie(std::string title_, std::chrono::sys_seconds time_, double cost_, int seats_left_, int vip_seats_left_, age age_restriction_):
        Session(title_, time_, cost_, seats_left_),
        age_restriction(age_restriction_),
        vip_seats_left(vip_seats_left_)
    {}

int Movie::get_vip_seats_left() const{
    return vip_seats_left;
}

std::vector<Extras> Movie::get_supported_extras() const{
    return {Extras::VipSeat, Extras::Popcorn, Extras::Cola};
}

bool Movie::ordered(const OrderRequest& req){
    if(std::count(req.extras.begin(), req.extras.end(), Extras::VipSeat)){
        return reserve_seats(vip_seats_left, req.number_of_tickets);
    }
    else
        return reserve_seats(seats_left, req.number_of_tickets);

}