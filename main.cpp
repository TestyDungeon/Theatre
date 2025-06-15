#include <iostream>

#include "theatre/opera_theatre.h"
#include "session/opera_theatre/grand_opera.h"

#include "order_request/order_request.h"


int main(){
    std::vector<Theatre*> theatres;

    OperaTheatre opera("Opera Theatre of Saint Louis", "210 Hazel Ave", 960, 130);
    opera.append_session(new GrandOpera(
        "The Pirates of Penzance", 
        sys_days{year{2025}/6/19} + hours{19} + minutes{30},
        59,
        opera.get_seats(),
        opera.get_balcony_seats()
    ));
    theatres.push_back(&opera);

    while(true){
        int theatre_choice;
        int session_choice;
        bool order_choice;

        for(int i = 0; i < theatres.size(); i++)
            std::cout<<i<<" - "<<theatres[i]->get_name()<<std::endl;
        std::cout<<"Choose the theatre(from "<<0<<" to "<<theatres.size()-1<<"): "<<std::endl;
        std::cin>>theatre_choice;

        for(int i = 0; i < theatres[theatre_choice]->get_number_of_sessions(); i++)
            std::cout<<i<<" - "<<theatres[theatre_choice]->get_session(i)->get_title()<<std::endl;
        std::cout<<"Choose the session(from "<<0<<" to "<<theatres[theatre_choice]->get_number_of_sessions()-1<<"): "<<std::endl;
        std::cin>>session_choice;

        std::cout<<theatres[theatre_choice]->get_session(session_choice)->information();

        std::cout<<"Would you like to order a ticket? (0 - No | 1 - Yes):"<<std::endl;
        std::cin>>order_choice;
        
        if(!order_choice)
            continue;

        OrderRequest order;
        std::cout<<"Your name:"<<std::endl;
        std::cin>>order.name;
        std::cout<<"Your surname:"<<std::endl;
        std::cin>>order.surname;
        std::cout<<"Your age:"<<std::endl;
        std::cin>>order.age;
        std::cout<<"How many tickets:"<<std::endl;
        std::cin>>order.number_of_tickets;
        std::cout<<"Do you want:"<<std::endl;
        std::cin>>order.age;

    }

    return 0;
}
