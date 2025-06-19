#pragma once

#include <stdexcept>
#include <string>


enum class age{
    G = 0,
    PG13 = 13,
    R = 17,
};

enum class Extras {
    /* Opera / Choir */ Donation,

    /* Movie */ Popcorn, Cola,

    /* Drama */ Binocular, ProgramBooklet
};



inline std::string extra_to_string(Extras x){
    switch (x) {
        case Extras::Binocular: return "Binocular";
        case Extras::Cola: return "Cola";
        case Extras::Popcorn: return "Popcorn";
        case Extras::Donation: return "Donation";
        case Extras::ProgramBooklet: return "Program booklet"; 
    }
    throw std::invalid_argument("Unknown Extra in extras_to_string()");
}

enum class SeatType{
    /* Opera */ Stalls, FirstBalcony, SecondBalcony, Gallery,
    /* Movie */ Regular, VIP,
    /* Drama */ Parterre, DressCircle, Balcony 
};

inline std::string seat_type_to_string(SeatType x){
    switch (x) {
        case SeatType::Stalls: return "Stalls";
        case SeatType::FirstBalcony: return "First balcony";
        case SeatType::SecondBalcony: return "Second balcony";
        case SeatType::Gallery: return "Gallery";
        
        case SeatType::Regular: return "Regular";
        case SeatType::VIP: return "VIP";

        case SeatType::Parterre: return "Parterre";
        case SeatType::DressCircle: return "Dress circle";
        case SeatType::Balcony: return "Balcony"; 
    }
    throw std::invalid_argument("Unknown SeatType in seat_type_to_string()");
}