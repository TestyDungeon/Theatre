#pragma once

#include <stdexcept>
#include <string>


enum age{
    G = 0,
    PG13 = 13,
    R = 17,
};

enum class Extras {
    /* Opera */ Balcony,
    /* Opera / Choir */ Donation,

    /* Movie */ VipSeat, Popcorn, Cola,

    /* Drama */ Binocular, FrontRowSeat, ProgramBooklet
};

inline std::string extra_to_string(Extras x){
    switch (x) {
        case Extras::Balcony: return "to have a balcony seat";
        case Extras::VipSeat: return "to have a VIP seat";
        case Extras::FrontRowSeat: return "to have a front row seat";
        case Extras::Binocular: return "to get a binocular";
        case Extras::Cola: return "to preorder cola";
        case Extras::Popcorn: return "to preorder popcorn";
        case Extras::Donation: return "to make a donation";
        case Extras::ProgramBooklet: return "to get a program booklet"; 
    }
    throw std::invalid_argument("Unknown Extra in extras_to_string()");
}