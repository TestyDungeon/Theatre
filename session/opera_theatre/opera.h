#pragma once

#include "../session.h"

class Opera : public Session{
protected:
    int balcony_seats_left;
public:
    Opera(std::string title_, std::chrono::sys_seconds time_, double cost_, int seats_left_, int balcony_seats_left_);

    virtual void handle_extras(const std::vector<Extras>& ext) override;

    virtual bool ordered(const OrderRequest& req) override;
};