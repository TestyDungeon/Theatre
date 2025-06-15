#include <iostream>

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



int main(){
    std::vector<Theatre*> theatres;

    OperaTheatre opera("Opera Theatre of Saint Louis", "210 Hazel Ave", 960, 130);
    opera.append_session(new GrandOpera(
        "The Pirates of Penzance", 
        sys_days{year{2025}/6/19} + hours{19} + minutes{30},
        29,
        opera.get_seats(),
        opera.get_balcony_seats()
    ));

    opera.append_session(new Choir(
        "House Gospel Choir", 
        sys_days{year{2025}/6/30} + hours{12} + minutes{00},
        5,
        opera.get_seats(),
        opera.get_balcony_seats()
    ));

    theatres.push_back(&opera);

    MovieTheatre cinema("Multiplex", "47 European Union Ave", 130, 12);
    cinema.append_session(new HorrorMovie(
        "Substance", 
        sys_days{year{2025}/6/12} + hours{14} + minutes{30},
        5,
        cinema.get_seats(),
        cinema.get_vip_seats()
    ));

    cinema.append_session(new ActionMovie(
        "Mission: Impossible - The Final Reckoning", 
        sys_days{year{2025}/6/13} + hours{16} + minutes{00},
        5,
        cinema.get_seats(),
        cinema.get_vip_seats()
    ));

    theatres.push_back(&cinema);

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
        std::cout<<"How many tickets: "<<std::endl;
        std::cin>>order.number_of_tickets;
        for(auto x : session->get_supported_extras()){
            std::cout<<"Do you want "<<extra_to_string(x)<<"? (0 - No | 1 - Yes)"<<std::endl;
            std::cin>>extras_choice;
            if(extras_choice)
                order.extras.push_back(x);
        }

        session->append_order(order);
        std::cout<<std::endl<<session->order_information(order);
        std::cin>>end_choice;

    }

    return 0;
}
