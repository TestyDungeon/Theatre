#pragma once

#include "theatre.h"

class OperaTheatre : public Theatre{
private:
public:
    OperaTheatre(const std::string& name_, const std::string& location_, int stalls_seats_, int first_balcony_seats_, int second_balcony_seats_, int gallery_seats_);

    bool approve_order(const Session& s, const OrderRequest& req) const override;

};