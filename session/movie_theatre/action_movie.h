#pragma once

#include "movie.h"

class ActionMovie : public Movie{
public:
    ActionMovie(std::string title_, std::chrono::sys_seconds time_, double cost_);
};
