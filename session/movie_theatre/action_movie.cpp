#include "action_movie.h"

ActionMovie::ActionMovie(std::string title_, std::chrono::sys_seconds time_, double cost_, int seats_left_, int vip_seats_left_):
    Movie(title_, time_, cost_, seats_left_, vip_seats_left_, age::PG13)
{

}