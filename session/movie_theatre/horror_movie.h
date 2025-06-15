#pragma once

#include "movie.h"

class HorrorMovie : public Movie{
public:
    HorrorMovie(std::string title_, std::chrono::sys_seconds time_, double cost_, int seats_left_);
};