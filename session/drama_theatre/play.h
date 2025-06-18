#pragma once

#include "../session.h"

class Play : public Session{
protected:
    Play(std::string title_, std::chrono::sys_seconds time_, double cost_);
public:

    virtual std::vector<Extras> get_supported_extras() const override;

    virtual double calculate_price(const OrderRequest& req) const override;
};