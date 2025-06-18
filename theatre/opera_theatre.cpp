#include "opera_theatre.h"
#include "enums.h"

OperaTheatre::OperaTheatre(const std::string& name_, const std::string& location_, int stalls_seats_, int first_balcony_seats_, int second_balcony_seats_, int gallery_seats_):
    Theatre(name_, location_)
{
    seat_counts[SeatType::Stalls] = stalls_seats_;
    seat_counts[SeatType::FirstBalcony] = first_balcony_seats_;
    seat_counts[SeatType::SecondBalcony] = second_balcony_seats_;
    seat_counts[SeatType::Gallery] = gallery_seats_;
}

std::vector<SeatType> OperaTheatre::get_available_seat_types() const{
    return {SeatType::Stalls, SeatType::FirstBalcony, SeatType::SecondBalcony, SeatType::Gallery};
}