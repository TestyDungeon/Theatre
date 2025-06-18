#pragma once

#include "enums.h"
#include "theatre.h"
#include <vector>

class OperaTheatre : public Theatre{
private:
public:
    OperaTheatre(const std::string& name_, const std::string& location_, int stalls_seats_, int first_balcony_seats_, int second_balcony_seats_, int gallery_seats_);

    std::vector<SeatType> get_available_seat_types() const override;
};