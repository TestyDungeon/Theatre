#pragma once 

#include "opera.h"

class GrandOpera : public Opera{
private:
public:
    GrandOpera(std::string title_, std::chrono::sys_seconds time_, double cost_, int seats_left_, int balcony_seats_left_);

    std::vector<Extras> get_supported_extras() const override;

    bool ordered(const OrderRequest& req) override;
};