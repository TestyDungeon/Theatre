#include "action_movie.h"

ActionMovie::ActionMovie(std::string title_, std::chrono::sys_seconds time_, double cost_):
    Movie(title_, time_, cost_, age::PG13)
{}
