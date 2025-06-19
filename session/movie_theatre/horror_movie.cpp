#include "horror_movie.h"
#include "enums.h"
#include <string>

HorrorMovie::HorrorMovie(std::string title_, std::chrono::sys_seconds time_, double cost_):
    Movie(title_, time_, cost_, age::R)
{}
