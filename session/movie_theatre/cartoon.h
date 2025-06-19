#pragma once

#include "movie.h"

class Cartoon : public Movie{
public:
    Cartoon(std::string title_, std::chrono::sys_seconds time_, double cost_);

    double calculate_price(const OrderRequest& req) const override;

    std::string age_message(const OrderRequest& req) const override;
};