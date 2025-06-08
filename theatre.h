#ifndef THEATRE_H
#define THEATRE_H

#endif // THEATRE_H

#include <string>
#include <vector>
#include <ctime>

enum age{
    G = 0,
    PG13 = 13,
    R = 17,
};

enum class Extras { /* Opera */ Balcony,
                    /* Movie */ VipSeat, Popcorn, Cola,
                    /* Drama */ Binocular
};

struct OrderRequest{
    std::vector<Extras> extras;
};

//Session Class Hierarchy:

class Session{
protected:
    std::string title;
    std::tm time = {};
    double cost;
    int seats_left;
    const std::string poster;

public:
    Session(std::string title_, std::tm time_, double cost_, int seats_left_, std::string poster_):
        title(title_),
        time(time_),
        cost(cost_),
        seats_left(seats_left_),
        poster(poster_)
    {

    }

    std::string get_title() const{
        return title;
    }

    int get_seats_left() const{
        return seats_left;
    }

    virtual void ordered(const OrderRequest& req){

    }

    virtual ~Session() = default;
};

//Child Classes of Session:


//Ballet Theatre:
class Ballet : Session{

};

//Drama Theatre:
class Play : Session{

};

//Opera Theatre:
class Opera : public Session{
public:
    void ordered(const OrderRequest& req) override{

    }
};

class GrandOpera : Opera{
private:
    int balcony_seats_left;
};

class Choir : Opera{

};

//Movie Theatre:

class Movie : public Session{
protected:
    age age_restriction;
public:
    Movie(std::string title_, std::tm time_, double cost_, int seats_left_, std::string poster_):
        Session(title_, time_, cost_, seats_left_, poster_)
    {

    }
};

class HorrorMovie : public Movie{
public:
    HorrorMovie(std::string title_, std::tm time_, double cost_, int seats_left_, std::string poster_):
        Movie(title_, time_, cost_, seats_left_, poster_)
    {
        age_restriction = R;
    }
};

class ActionMovie : public Movie{
    ActionMovie(std::string title_, std::tm time_, double cost_, int seats_left_, std::string poster_):
        Movie(title_, time_, cost_, seats_left_, poster_)
    {
        age_restriction = PG13;
    }
};

class Cartoon : public Movie{
    Cartoon(std::string title_, std::tm time_, double cost_, int seats_left_, std::string poster_):
        Movie(title_, time_, cost_, seats_left_, poster_)
    {
        age_restriction = G;
    }
};




//Theatre Class Hierarchy:

class Theatre{
protected:
    std::string name;
    std::string location;
    std::vector<Session *> sessions;

    Theatre(std::string name_, std::string location_):
        name(name_),
        location(location_)
    {

    }

    void append_session(Session *s){
        sessions.push_back(s);
    }

    virtual void order(int x, const OrderRequest& req){
        if(sessions[x]->get_seats_left() > 0){
            sessions[x]->ordered(req);
        }
    }

};

//Child Classes of Theatre:

class OperaTheatre : public Theatre{
private:
    bool balcony;
public:
};

class DramaTheatre : Theatre{

};

class BalletTheatre : Theatre{

};

class MovieTheatre : Theatre{

};


//test
