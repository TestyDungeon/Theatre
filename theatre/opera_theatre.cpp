#include "opera_theatre.h"

OperaTheatre::OperaTheatre(std::string name_, std::string location_, int seats_, int balcony_seats_):
    Theatre(name_, location_, seats_),
    balcony_seats(balcony_seats_)
{}

int OperaTheatre::get_balcony_seats() const{
    return balcony_seats;
}