#include "movie_theatre.h"
#include "enums.h"

MovieTheatre::MovieTheatre(const std::string& name_, const std::string& location_, int regular_seats_, int vip_seats_):
    Theatre(name_, location_)
{
    seat_counts[SeatType::Regular] = regular_seats_;
    seat_counts[SeatType::VIP] = vip_seats_;

}

bool MovieTheatre::approve_order(const Session& s, const OrderRequest& req) const{
    //You cannot buy more than 5 Regular tickets per person for Movie Theatre. 
    //And no more than 2 VIP tickets.
    if(req.number_of_tickets.at(SeatType::Regular) > 5 || req.number_of_tickets.at(SeatType::VIP) > 2)
        return false;
    return true;
}