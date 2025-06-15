#include "horror_movie.h"
#include "enums.h"

HorrorMovie::HorrorMovie(std::string title_, std::chrono::sys_seconds time_, double cost_, int seats_left_, int vip_seats_left_):
    Movie(title_, time_, cost_, seats_left_, vip_seats_left_, age::R)
{}

