#pragma once

#ifndef THEATRE_H
#define THEATRE_H

#endif // THEATRE_H


#include <string>
#include <vector>

#include "../session/session.h"
#include <bits/stdc++.h>
using namespace std::chrono;

class Theatre{
protected:
    std::string name;
    std::string location;
    std::vector<Session *> sessions;
    int seats;
public:
    Theatre(std::string name_, std::string location_, int seats_):
        name(name_),
        location(location_),
        seats(seats_)
    {

    }

    void append_session(Session *s){
        sessions.push_back(s);
        s->set_parent(this);
    }

    int get_seats() const{
        return seats;
    }

    std::string get_address() const{
        return location;
    }

    int get_number_of_sessions() const{
        return sessions.size();
    }

    Session* get_session(int i) const{
        return sessions[i];
    }

    std::string get_name() const{
        return name;
    }

    virtual void order(int x, const OrderRequest& req){
        if(sessions[x]->get_seats_left() > 0){
            sessions[x]->ordered(req);
        }
    }

};