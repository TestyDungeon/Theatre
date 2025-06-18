#include "drama_theatre.h"

DramaTheatre::DramaTheatre(const std::string& name_, const std::string& location_, int parterre_seats_, int dress_circle_seats_, int balcony_seats_):
    Theatre(name_, location_)
{
    seat_counts[SeatType::Parterre] = parterre_seats_;
    seat_counts[SeatType::DressCircle] = dress_circle_seats_;
    seat_counts[SeatType::Balcony] = balcony_seats_;
}

std::vector<SeatType> DramaTheatre::get_available_seat_types() const{
    return {SeatType::Parterre, SeatType::DressCircle, SeatType::Balcony};
}