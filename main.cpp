#include <iostream>

#include "comedy_play.h"
#include "drama_theatre.h"
#include "enums.h"
#include "session.h"
#include "theatre.h"
#include "theatre/opera_theatre.h"
#include "session/opera_theatre/grand_opera.h"
#include "session/opera_theatre/choir.h"

#include "theatre/movie_theatre.h"
#include "session/movie_theatre/horror_movie.h"
#include "session/movie_theatre/action_movie.h"
#include "session/movie_theatre/cartoon.h"

#include "order_request/order_request.h"
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


    while(true){
        int theatre_choice;
        int session_choice;
        bool order_choice;
        bool extras_choice;
        int end_choice;

        std::cout<<std::endl<<"Choose the theatre(from "<<0<<" to "<<theatres.size()-1<<"): "<<std::endl;
        for(int i = 0; i < theatres.size(); i++)
            std::cout<<i<<" - "<<theatres[i]->get_name()<<std::endl;
        std::cin>>theatre_choice;
        Theatre* theatre = theatres[theatre_choice];

        std::cout<<std::endl<<"Choose the session(from "<<0<<" to "<<theatre->get_number_of_sessions()-1<<"): "<<std::endl;
        for(int i = 0; i < theatre->get_number_of_sessions(); i++)
            std::cout<<i<<" - "<<theatre->get_session(i)->get_title()<<std::endl;
        std::cin>>session_choice;

        Session* session = theatre->get_session(session_choice);

        std::cout<<std::endl<<session->information()<<std::endl;

        std::cout<<"Would you like to order a ticket? (0 - No | 1 - Yes):"<<std::endl;
        std::cin>>order_choice;
        
        if(!order_choice)
            continue;

        OrderRequest order;
        std::cout<<std::endl;
        std::cout<<"Your name: "<<std::endl;
        std::cin>>order.name;
        std::cout<<"Your surname: "<<std::endl;
        std::cin>>order.surname;
        std::cout<<"Your age: "<<std::endl;
        std::cin>>order.age;
        for(auto type : session->get_seats_types()){
            std::cout<<"How many "<<seat_type_to_string(type)<<" tickets do you want ?"<<std::endl;
            std::cin>>order.number_of_tickets[type];
        }
        

        for(auto x : session->get_supported_extras()){
            std::cout<<"Do you want "<<extra_to_string(x)<<"? (0 - No | 1 - Yes)"<<std::endl;
            std::cin>>extras_choice;
            if(extras_choice)
                order.extras.push_back(x);
        }

        session->ticket_order(order);
        std::cout<<std::endl<<session->order_information(order)<<std::endl;
        std::cout<<"Thank you for using our service!\n"<<
                    "Would you like to order something else? (0 - No | 1 - Yes)";
        std::cin>>end_choice;
        if(end_choice)
            continue;
        break;
    }

    return 0;
}
