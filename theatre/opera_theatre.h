#pragma once

#include "theatre.h"

class OperaTheatre : public Theatre{
private:
    int balcony_seats;
public:
    OperaTheatre(std::string name_, std::string location_, int seats_, int balcony_seats_);

    int get_balcony_seats() const;
};