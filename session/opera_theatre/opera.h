#pragma once

#include "../session.h"
#include "enums.h"
#include <vector>

class Opera : public Session{
protected:
    int balcony_seats_left;
public:
    Opera(std::string title_, std::chrono::sys_seconds time_, double cost_, int seats_left_, int balcony_seats_left_);

    int get_balcony_seats_left() const;

    virtual std::vector<Extras> get_supported_extras() const override;

    virtual bool ordered(const OrderRequest& req) override;
};