#pragma once

#include "../session.h"
#include "order_request.h"

class Movie : public Session{
protected:
    age age_restriction;
    Movie(std::string title_, std::chrono::sys_seconds time_, double cost_, age age_restriction_);
public:
    bool ticket_order(OrderRequest req) override;

    virtual std::vector<Extras> get_supported_extras() const override;

    virtual double calculate_price(const OrderRequest& req) const override;

    virtual std::string age_message(const OrderRequest& req) const = 0;
};