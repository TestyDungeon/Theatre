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

    bool operator==(const OrderRequest &a) const{
        
        return name == a.name && surname == a.surname && age == a.age && number_of_tickets == a.number_of_tickets && extras == a.extras;
    }
};