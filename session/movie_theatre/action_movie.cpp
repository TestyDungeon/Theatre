#include "action_movie.h"

ActionMovie::ActionMovie(std::string title_, std::chrono::sys_seconds time_, double cost_):
    Movie(title_, time_, cost_, age::PG13)
{}


std::string ActionMovie::age_message(const OrderRequest& req) const{
    return "Sorry, you are not allowed to watch this. You can ask your grown-ups to go with you :)\n";
}