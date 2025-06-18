#pragma once

#include "theatre.h"

class MovieTheatre : public Theatre{
private:
public:
    MovieTheatre(const std::string& name_, const std::string& location_, int regular_seats_, int vip_seats_);

    std::vector<SeatType> get_available_seat_types() const override;
};