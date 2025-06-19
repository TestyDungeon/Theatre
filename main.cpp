#include "theatre.h"
#include "session.h"
#include "console_ui.h"

#include "opera_theatre.h"
#include "grand_opera.h"
#include "choir.h"

#include "movie_theatre.h"
#include "horror_movie.h"
#include "action_movie.h"
#include "cartoon.h"

#include "drama_theatre.h"
#include "comedy_play.h"
#include "tragedy_play.h"



int main(){
    std::vector<Theatre*> theatres;

    OperaTheatre opera("Opera Theatre of Saint Louis", "210 Hazel Ave", 96, 120, 165, 238);
    opera.append_session(new GrandOpera(
        "The Pirates of Penzance", 
        sys_days{year{2025}/6/19} + hours{19} + minutes{30},
        29
    ));

    opera.append_session(new Choir(
        "House Gospel Choir", 
        sys_days{year{2025}/6/30} + hours{12} + minutes{00},
        5
    ));

    theatres.push_back(&opera);




    MovieTheatre cinema("Multiplex Cinema", "47 European Union Ave", 130, 12);
    cinema.append_session(new HorrorMovie(
        "Substance", 
        sys_days{year{2025}/6/12} + hours{14} + minutes{30},
        10
    ));

    cinema.append_session(new ActionMovie(
        "Mission: Impossible - The Final Reckoning", 
        sys_days{year{2025}/6/13} + hours{16} + minutes{00},
        10
    ));

    cinema.append_session(new Cartoon(
        "Nausicaä of the Valley of the Wind", 
        sys_days{year{2025}/7/1} + hours{21} + minutes{45},
        9
    ));

    theatres.push_back(&cinema);




    DramaTheatre drama("Eugene O'Neill Theatre", "230 West 49th Street", 110, 240, 278);

    drama.append_session(new TragedyPlay(
        "Hamlet", 
        sys_days{year{2025}/7/9} + hours{20} + minutes{30},
        18
    ));

    drama.append_session(new ComedyPlay(
        "A Midsummer Night’s Dream", 
        sys_days{year{2025}/7/7} + hours{17} + minutes{00},
        15
    ));


    theatres.push_back(&drama);


    ConsoleUI ui;
    ui.run(theatres);
    return 0;
}
