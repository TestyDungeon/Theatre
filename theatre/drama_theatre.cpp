#include "drama_theatre.h"

DramaTheatre::DramaTheatre(const std::string& name_, const std::string& location_, int parterre_seats_, int dress_circle_seats_, int balcony_seats_):
    Theatre(name_, location_)
{
    seat_counts[SeatType::Parterre] = parterre_seats_;
    seat_counts[SeatType::DressCircle] = dress_circle_seats_;
    seat_counts[SeatType::Balcony] = balcony_seats_;
}

bool DramaTheatre::approve_order(const Session& s, const OrderRequest& req) const{
    //You cannot buy more than 10 total tickets per person for Drama Theatre. 
    //But if you buy a Binocular AND a Program Booklet, youcan buy up to 20 tickets.
    if(std::count(req.extras.begin(), req.extras.end(), Extras::Binocular) && std::count(req.extras.begin(), req.extras.end(), Extras::ProgramBooklet)){
        if(s.get_total_order_seats(req) > 20)
            return false;
        return true;
    }
    else{
        if(s.get_total_order_seats(req) > 10)
            return false;
        return true;
    }
}