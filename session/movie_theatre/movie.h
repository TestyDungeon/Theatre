#pragma once

#include "../session.h"

class Movie : public Session{
protected:
    age age_restriction;
    int vip_seats_left;
public:
    Movie(std::string title_, std::chrono::sys_seconds time_, double cost_, int seats_left_, int vip_seats_left_, age age_restriction_);

    int get_vip_seats_left() const;

    virtual std::vector<Extras> get_supported_extras() const override;

    virtual bool ordered(const OrderRequest& req) override;
};