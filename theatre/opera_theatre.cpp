#include "opera_theatre.h"
#include "enums.h"
#include "session.h"

OperaTheatre::OperaTheatre(const std::string& name_, const std::string& location_, int stalls_seats_, int first_balcony_seats_, int second_balcony_seats_, int gallery_seats_):
    Theatre(name_, location_)
{
    seat_counts[SeatType::Stalls] = stalls_seats_;
    seat_counts[SeatType::FirstBalcony] = first_balcony_seats_;
    seat_counts[SeatType::SecondBalcony] = second_balcony_seats_;
    seat_counts[SeatType::Gallery] = gallery_seats_;
}

bool OperaTheatre::approve_order(const Session& s, const OrderRequest& req) const{
    //You cannot buy more than 5 tickets per person for Opera. 
    //But you can buy up to 10 for Choir if you make a donation
    if(std::count(req.extras.begin(), req.extras.end(), Extras::Donation)){
        if(s.get_total_order_seats(req) > 10)
            return false;
        return true;
    }
    else{
        if(s.get_total_order_seats(req) > 5)
            return false;
        return true;
    }
}
