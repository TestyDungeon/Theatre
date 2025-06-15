#pragma once

#include <string>
#include <vector>
#include "enums.h"

struct OrderRequest{
    std::string name;
    std::string surname;
    int number_of_tickets;
    int age;
    std::vector<Extras> extras;
};