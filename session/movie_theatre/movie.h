#pragma once

#include "../session.h"

class Movie : public Session{
protected:
    age age_restriction;
public:
    Movie(std::string title_, std::chrono::sys_seconds time_, double cost_, int seats_left_, age age_restriction_);
};