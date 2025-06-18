#include "movie_theatre.h"
#include "enums.h"

MovieTheatre::MovieTheatre(const std::string& name_, const std::string& location_, int regular_seats_, int vip_seats_):
    Theatre(name_, location_)
{
    seat_counts[SeatType::Regular] = regular_seats_;
    seat_counts[SeatType::VIP] = vip_seats_;

}

std::vector<SeatType> MovieTheatre::get_available_seat_types() const{
    return {SeatType::Regular, SeatType::VIP};
}