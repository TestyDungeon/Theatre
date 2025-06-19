#pragma once

#include "theatre.h"

class MovieTheatre : public Theatre{
private:
public:
    MovieTheatre(const std::string& name_, const std::string& location_, int regular_seats_, int vip_seats_);
    
    bool approve_order(const Session& s, const OrderRequest& req) const override;
};