#pragma once 

#include "opera.h"

class GrandOpera : public Opera{
private:
public:
    GrandOpera(std::string title_, std::chrono::sys_seconds time_, double cost_);

    std::vector<Extras> get_supported_extras() const override;

    double calculate_price(const OrderRequest& req) const override;
};