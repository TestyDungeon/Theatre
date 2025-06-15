#pragma once

#include <string>
#include <vector>
#include "enums.h"

struct OrderRequest{
    std::string name;
    std::string surname;
    int age;
    int number_of_tickets;
    std::vector<Extras> extras;
};