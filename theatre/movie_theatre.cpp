#include "movie_theatre.h"

MovieTheatre::MovieTheatre(std::string name_, std::string location_, int seats_, int vip_seats_):
    Theatre(name_, location_, seats_),
    vip_seats(vip_seats_)
{}

int MovieTheatre::get_vip_seats() const{
    return vip_seats;
}