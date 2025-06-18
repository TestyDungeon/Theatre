#pragma once

#include "../session.h"
#include "enums.h"
#include <vector>

class Opera : public Session{
protected:
    int balcony_seats_left;
public:
    Opera(std::string title_, std::chrono::sys_seconds time_, double cost_);

    virtual std::vector<Extras> get_supported_extras() const override;

    virtual double calculate_price(const OrderRequest& req) const override=0;
};