#ifndef THEATRE_H
#define THEATRE_H

#endif // THEATRE_H

#include <string>


//Session Class Hierarchy:

class Session{

};

//Child Classes of Session:

class Ballet : Session{

};

class Play : Session{

};

class Opera : Session{

};

class Movie : Session{
protected:
    bool ageRestricted;
};

class HorrorMovie : Movie{

};

class ActionMovie : Movie{

};

class Cartoon : Movie{

};


//Theatre Class Hierarchy:

class Theatre{
protected:
    std::string name;
    std::string Location;
};

//Child Classes of Theatre:

class OperaTheatre : Theatre{

};

class DramaTheatre : Theatre{

};

class BalletTheatre : Theatre{

};

class MovieTheatre : Theatre{

};


//test
