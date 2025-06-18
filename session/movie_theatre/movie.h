#pragma once

#include "../session.h"

class Movie : public Session{
protected:
    age age_restriction;
    int vip_seats_left;
    Movie(std::string title_, std::chrono::sys_seconds time_, double cost_, age age_restriction_);
public:

    int get_vip_seats_left() const;

    virtual std::vector<Extras> get_supported_extras() const override;

    virtual double calculate_price(const OrderRequest& req) const override;
};