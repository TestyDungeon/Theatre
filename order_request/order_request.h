#pragma once

#include <string>
#include <vector>
#include "enums.h"
#include <unordered_map>

struct OrderRequest{
    std::string name;
    std::string surname;
    int age;
    std::unordered_map<SeatType, int> number_of_tickets;
    std::vector<Extras> extras;

};