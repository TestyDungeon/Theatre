#pragma once

#include "enums.h"
#include "order_request.h"
#include <memory>



#include <string>
#include <vector>
#include <unordered_map>

#include "../session/session.h"
#include <bits/stdc++.h>
using namespace std::chrono;

class Theatre{
protected:
    std::string name;
    std::string location;
    
    std::vector<std::unique_ptr<Session>> sessions;
    std::unordered_map<SeatType, int> seat_counts;
public:
    Theatre(const std::string& name_, const std::string& location_);

    void append_session(Session *s);

    const std::string& get_name() const;
    
    const std::string& get_address() const;

    std::unordered_map<SeatType, int> get_seats() const;

    int get_seats(const SeatType& x) const;

    int get_number_of_sessions() const;

    const Session* get_session(int i) const;

    Session* get_session(int i);

    std::vector<SeatType> get_available_seat_types() const;

    virtual bool approve_order(const Session& s, const OrderRequest& req) const = 0;

    virtual ~Theatre();
};