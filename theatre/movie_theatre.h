#pragma once

#include "theatre.h"

class MovieTheatre : public Theatre{
private:
    int vip_seats;
public:
    MovieTheatre(std::string name_, std::string location_, int seats_, int balcony_seats_);

    int get_vip_seats() const;
};