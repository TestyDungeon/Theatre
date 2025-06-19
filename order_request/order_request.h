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

    OrderRequest(){
        number_of_tickets[SeatType::Gallery] = 0;
        number_of_tickets[SeatType::SecondBalcony] = 0;
        number_of_tickets[SeatType::FirstBalcony] = 0;
        number_of_tickets[SeatType::Stalls] = 0;
        number_of_tickets[SeatType::Balcony] = 0;
        number_of_tickets[SeatType::DressCircle] = 0;
        number_of_tickets[SeatType::Parterre] = 0;
        number_of_tickets[SeatType::Regular] = 0;
        number_of_tickets[SeatType::VIP] = 0;
    }
};