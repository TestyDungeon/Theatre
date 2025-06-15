#pragma once

#include "movie.h"

class Cartoon : public Movie{
    Cartoon(std::string title_, std::chrono::sys_seconds time_, double cost_, int seats_left_, int vip_seats_left_);
};