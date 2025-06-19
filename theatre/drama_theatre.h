#pragma once

#include "theatre.h"

class DramaTheatre : public Theatre{
private:
public:
    DramaTheatre(const std::string& name_, const std::string& location_, int parterre_seats_, int dress_circle_seats_, int balcony_seats_);

    bool approve_order(const Session& s, const OrderRequest& req) const override;
};