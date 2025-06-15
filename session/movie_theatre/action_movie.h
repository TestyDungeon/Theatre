#pragma once

#include "movie.h"

class ActionMovie : public Movie{
    ActionMovie(std::string title_, std::chrono::sys_seconds time_, double cost_, int seats_left_);
};