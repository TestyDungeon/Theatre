#include "movie.h"

Movie::Movie(std::string title_, std::chrono::sys_seconds time_, double cost_, int seats_left_, age age_restriction_):
        Session(title_, time_, cost_, seats_left_),
        age_restriction(age_restriction_)
    {}