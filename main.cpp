//#include "mainwindow.h"

//#include <QApplication>

#include "session/opera_theatre/grand_opera.h"
#include "theatre/opera_theatre.h"
#include <iostream>




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
        int in_1;
        int in_2;
        for(int i = 0; i < theatres.size(); i++)
            std::cout<<i<<" - "<<theatres[i]->get_name()<<std::endl;
        std::cout<<"Choose the theatre(from "<<0<<" to "<<theatres.size()-1<<"): "<<std::endl;
        std::cin>>in_1;

        for(int i = 0; i < theatres[in_1]->get_number_of_sessions(); i++)
            std::cout<<i<<" - "<<theatres[in_1]->get_session(i)->get_title()<<std::endl;
        std::cout<<"Choose the session(from "<<0<<" to "<<theatres[in_1]->get_number_of_sessions()-1<<"): "<<std::endl;
        std::cin>>in_2;

        std::cout<<theatres[in_1]->get_session(in_2)->information();
    }

    return 0;
}
