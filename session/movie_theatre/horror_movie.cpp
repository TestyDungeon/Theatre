#include "horror_movie.h"
#include "enums.h"
#include <string>

HorrorMovie::HorrorMovie(std::string title_, std::chrono::sys_seconds time_, double cost_):
    Movie(title_, time_, cost_, age::R)
{}


std::string HorrorMovie::age_message(const OrderRequest& req) const{
    return "Sorry, you are not allowed to watch this. Come back after " + std::to_string(static_cast<int>(age_restriction)-req.age) + " years :)\n";
}