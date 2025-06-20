#pragma once
#include <vector>
#include "theatre.h"

class ConsoleUI {
public:
    int prompt_theatre_choice(const std::vector<Theatre*>& theatres);

    int prompt_session_choice(const Theatre* theatre);
    
    OrderRequest prompt_order_input(const Session* session);
    
    void show_order_summary(const Session* session, const OrderRequest& order);
    void run(std::vector<Theatre*>& theatres);
};