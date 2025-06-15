#include "horror_movie.h"

HorrorMovie::HorrorMovie(std::string title_, std::chrono::sys_seconds time_, double cost_, int seats_left_):
    Movie(title_, time_, cost_, seats_left_, R)
{}