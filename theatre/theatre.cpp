#include "theatre.h"
#include "enums.h"

Theatre::Theatre(const std::string& name_, const std::string& location_):
    name(name_),
    location(location_)
{}

void Theatre::append_session(Session *s){
    sessions.push_back(std::unique_ptr<Session>(s));
    s->set_parent(this);
    s->set_seats_left(seat_counts);
}

int Theatre::get_seats(const SeatType& x) const{
    return seat_counts.at(x);
}

std::unordered_map<SeatType, int> Theatre::get_seats() const{
    return seat_counts;
}

const std::string& Theatre::get_address() const{
    return location;
}

int Theatre::get_number_of_sessions() const{
    return sessions.size();
}

const Session* Theatre::get_session(int i) const{
    return sessions[i].get();
}

Session* Theatre::get_session(int i){
    return sessions[i].get();
}

const std::string& Theatre::get_name() const{
    return name;
}

std::vector<SeatType> Theatre::get_available_seat_types() const{
    std::vector<SeatType> seat_types;
    for(auto cell : seat_counts){
        seat_types.push_back(cell.first);
    }
    return seat_types;
}

Theatre::~Theatre(){}