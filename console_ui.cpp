#include "console_ui.h"
#include <iostream>


int ConsoleUI::prompt_theatre_choice(const std::vector<Theatre*>& theatres) {
    int choice;
    while(true){
        std::cout<<"\nChoose the theatre (from 0 to "<<(theatres.size() - 1)<<"):\n";
        for (size_t i = 0; i < theatres.size(); ++i)
            std::cout<<i<<" - "<<theatres[i]->get_name()<<std::endl;
        std::cin>>choice;
        if(choice > theatres.size()-1 || choice < 0 || std::cin.fail()){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout<<"!!! Please enter a proper value !!!"<<std::endl;
        }
        else{
            return choice;
        }
    }
}

int ConsoleUI::prompt_session_choice(const Theatre* theatre) {
    int choice;
    while(true){
        std::cout<<"\nChoose the session (from 0 to "<<(theatre->get_number_of_sessions() - 1)<<"):\n";
        for (int i = 0; i < theatre->get_number_of_sessions(); ++i)
            std::cout<<i<<" - "<<theatre->get_session(i)->get_title()<<std::endl;
        std::cin>>choice;
        if(choice > theatre->get_number_of_sessions()-1 || choice < 0 || std::cin.fail()){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout<<"!!! Please enter a proper value !!!"<<std::endl;
        }
        else{
            return choice;
        }
    }
}

OrderRequest ConsoleUI::prompt_order_input(const Session* session) {
    OrderRequest order;
    std::cout << "Your name:\n";
    std::cin >> order.name;
    std::cout << "Your surname:\n";
    std::cin >> order.surname;

    int temp_age;
    while(true){
        std::cout << "Your age:\n";
        std::cin >> temp_age;
        if(temp_age > 100 || temp_age < 1 || std::cin.fail()){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout<<"!!! Please enter a real age !!!"<<std::endl;
        }
        else{
            break;
        }
    }
    order.age = temp_age;

    int temp_seat;
    for (auto type : session->get_seats_types()) {
        while(true){
            std::cout << "How many " << seat_type_to_string(type) << " tickets do you want?\n";
            std::cin >> temp_seat;
            if(temp_seat > 50 || temp_seat < 0 || std::cin.fail()){
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout<<"!!! Please enter a realistic amount of seats !!!"<<std::endl;
            }
            else{
                break;
            }
        }
        order.number_of_tickets[type] = temp_seat;
    }

    
    bool extras_choice;
    for (auto x : session->get_supported_extras()) {
        while (true) {
            std::cout << "Do you want " << extra_to_string(x) << "? (0 - No | 1 - Yes)\n";
            std::cin >> extras_choice;
            if((extras_choice != 0 && extras_choice != 1) || std::cin.fail()){
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout<<"!!! Please enter a proper value !!!"<<std::endl;
            }
            else{
                break;
            }
        }
        if (extras_choice) order.extras.push_back(x);
    }
    return order;
}

void ConsoleUI::show_order_summary(const Session* session, const OrderRequest& order) {
    std::cout << "\n" << session->order_information(order) << "\n";
    std::cout << "Thank you for using our service!\n";
}


void ConsoleUI::run(std::vector<Theatre*>& theatres) {
    while (true) {
        int theatre_index = prompt_theatre_choice(theatres);
        Theatre* theatre = theatres[theatre_index];
        int session_index = prompt_session_choice(theatre);
        Session* session = theatre->get_session(session_index);

        std::cout<<"\n"<<session->information()<<std::endl;

        
        bool order_choice;
        while(true){
            std::cout<<"Would you like to order a ticket? (0 - No | 1 - Yes): "<<std::endl;
            std::cin>>order_choice;
            if((order_choice != 0 && order_choice != 1) || std::cin.fail()){
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout<<"!!! Please enter a proper value !!!"<<std::endl;
            }
            else{
                break;
            }
        }
        if (!order_choice) continue;

        OrderRequest order = prompt_order_input(session);
        if (session->ticket_order(order)) {
            show_order_summary(session, order);
        } else {
            std::cout<<"Unable to complete order (you are too young OR not enough seats).\n";
        }

        int end_choice;
        
        while(true){
            std::cout<<"Would you like to order something else? (0 - No | 1 - Yes): ";
            std::cin>>end_choice;
            if((end_choice != 0 && end_choice != 1) || std::cin.fail()){
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout<<"!!! Please enter a proper value !!!"<<std::endl;
            }
            else{
                break;
            }
        }

        if(!end_choice) 
            break;
    }
}