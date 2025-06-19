#include <gtest/gtest.h>
#include "order_request.h"
#include "enums.h"

#include "drama_theatre.h"
#include "tragedy_play.h"

#include "opera_theatre.h"
#include "grand_opera.h"
#include "choir.h"

#include "movie_theatre.h"
#include "cartoon.h"
#include "action_movie.h"

#include <chrono>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std::chrono;

OrderRequest make_order(
    std::string name, std::string surname, int age,
    std::unordered_map<SeatType, int> seats,
    std::vector<Extras> extras = {})
{
    OrderRequest req;
    req.name = name;
    req.surname = surname;
    req.age = age;
    
    req.number_of_tickets[SeatType::Gallery] = 0;
    req.number_of_tickets[SeatType::SecondBalcony] = 0;
    req.number_of_tickets[SeatType::FirstBalcony] = 0;
    req.number_of_tickets[SeatType::Stalls] = 0;
    req.number_of_tickets[SeatType::Balcony] = 0;
    req.number_of_tickets[SeatType::DressCircle] = 0;
    req.number_of_tickets[SeatType::Parterre] = 0;
    req.number_of_tickets[SeatType::Regular] = 0;
    req.number_of_tickets[SeatType::VIP] = 0;
    for(auto cell : seats){
        req.number_of_tickets[cell.first] = seats.at(cell.first);
    }
    req.extras = extras;
    return req;
}

std::chrono::sys_seconds test_time = sys_days{year{2025}/9/9} + hours{9} + minutes{00};

TEST(ChoirTest, ChoirOrderLimitWithoutDonation) {
    OperaTheatre opera("Big Opera", "Location", 10, 10, 10, 10);
    Choir c("Choir Night", test_time, 15.0);
    c.set_parent(&opera);

    OrderRequest req = make_order("A", "B", 35, {{SeatType::Gallery, 6}});
    EXPECT_FALSE(opera.approve_order(c, req));

    req.number_of_tickets[SeatType::Gallery] = 5;
    EXPECT_TRUE(opera.approve_order(c, req));
}

TEST(ChoirTest, ChoirOrderLimitWithDonation) {
    OperaTheatre opera("Big Opera", "Location", 10, 10, 10, 10);
    Choir c("Choir Night", test_time, 15.0);
    c.set_parent(&opera);

    OrderRequest req = make_order("A", "B", 35, {{SeatType::Gallery, 11}}, {Extras::Donation});
    EXPECT_FALSE(opera.approve_order(c, req));

    req.number_of_tickets[SeatType::Gallery] = 10;
    EXPECT_TRUE(opera.approve_order(c, req));
}

TEST(ChoirTest, ChoirDonationAffectsPrice) {
    Choir c("Choir Night", test_time, 20.0);

    OrderRequest req = make_order("A", "B", 25, {{SeatType::Gallery, 2}});
    EXPECT_DOUBLE_EQ(c.calculate_price(req), 2*20.0);

    req.extras.push_back(Extras::Donation);
    EXPECT_DOUBLE_EQ(c.calculate_price(req), 2*20.0 + 5.0);
}

TEST(GrandOperaTest, DiscountApplied) {
    GrandOpera g("Opera X", test_time, 30.0);

    OrderRequest req = make_order("A", "B", 25, {{SeatType::Gallery, 6}});
    double expected = 6*30.0*1.0*0.9;
    EXPECT_DOUBLE_EQ(g.calculate_price(req), expected);
}

TEST(GrandOperaTest, NoDiscountWhenNotEnoughSeats) {
    GrandOpera g("Opera X", test_time, 30.0);

    OrderRequest req = make_order("A", "B", 25, {{SeatType::Gallery, 5}});
    double expected = 5*30.0*1.0;
    EXPECT_DOUBLE_EQ(g.calculate_price(req), expected);
}

TEST(DramaTheatreTest, TicketLimitWithAndWithoutExtras) {
    DramaTheatre drama("Drama Hall", "Addr", 100, 100, 100);
    TragedyPlay play("Hamlet", test_time, 20.0);
    play.set_parent(&drama);

    OrderRequest req = make_order("A", "B", 22, {{SeatType::Balcony, 11}});
    EXPECT_FALSE(drama.approve_order(play, req));

    req.number_of_tickets[SeatType::Balcony] = 20;
    req.extras = {Extras::Binocular, Extras::ProgramBooklet};
    EXPECT_TRUE(drama.approve_order(play, req));

    req.number_of_tickets[SeatType::Balcony] = 21;
    EXPECT_FALSE(drama.approve_order(play, req));
}

TEST(CartoonTest, ChildDiscount) {
    Cartoon cartoon("Kids Show", test_time, 12.0);

    OrderRequest req = make_order("A", "B", 10, {{SeatType::Regular, 1}}, {Extras::Popcorn});
    double expected = (1*12.0 + 3.0) * 0.6;
    EXPECT_DOUBLE_EQ(cartoon.calculate_price(req), expected);
}

TEST(CartoonTest, NoChildDiscount) {
    Cartoon cartoon("Adult Show", test_time, 12.0);

    OrderRequest req = make_order("A", "B", 30, {{SeatType::Regular, 1}}, {Extras::Popcorn});
    double expected = 1*12.0 + 3.0;
    EXPECT_DOUBLE_EQ(cartoon.calculate_price(req), expected);
}

TEST(PriceCalculationTest, DramaPlayPricing) {
    TragedyPlay p("Hamlet", test_time, 20.0);

    std::unordered_map<SeatType, int> seats = {
        {SeatType::Balcony, 2},
        {SeatType::DressCircle, 1},
        {SeatType::Parterre, 1}
    };
    OrderRequest req = make_order("A", "B", 25, seats, {Extras::Binocular, Extras::ProgramBooklet});
    double price = p.calculate_price(req);

    EXPECT_DOUBLE_EQ(price, 103.0);
}

TEST(PriceCalculationTest, OperaDiscount) {
    using namespace std::chrono;
    GrandOpera op("La Traviata", test_time, 30.0);

    std::unordered_map<SeatType, int> seats = {
        {SeatType::Gallery, 3},
        {SeatType::SecondBalcony, 2},
        {SeatType::FirstBalcony, 1},
        {SeatType::Stalls, 1}
    };
    OrderRequest req = make_order("A", "B", 40, seats);
    double price = op.calculate_price(req);

    EXPECT_DOUBLE_EQ(price, 263.25);
}

TEST(PriceCalculationTest, CartoonChildDiscount) {
    using namespace std::chrono;
    Cartoon c("Totoro", test_time, 10.0);

    std::unordered_map<SeatType, int> seats = {
        {SeatType::Regular, 2},
        {SeatType::VIP, 1}
    };
    OrderRequest req = make_order("A", "B", 12, seats, {Extras::Popcorn, Extras::Cola});
    double price = c.calculate_price(req);

    EXPECT_DOUBLE_EQ(price, 23.4);
}

TEST(DramaTheatreTest, TicketLimitEnforced) {
    DramaTheatre drama("Drama Hall", "Address", 100, 200, 300);
    TragedyPlay play("Hamlet", test_time, 20.0);
    play.set_parent(&drama);

    std::unordered_map<SeatType, int> seats = {
        {SeatType::Balcony, 11}
    };
    OrderRequest req = make_order("A", "B", 30, seats);
    EXPECT_FALSE(drama.approve_order(play, req));

    seats[SeatType::Balcony] = 20;
    req.extras = {Extras::Binocular, Extras::ProgramBooklet};
    EXPECT_TRUE(drama.approve_order(play, req));
    seats[SeatType::Balcony] = 21;
    req.number_of_tickets = seats;
    EXPECT_FALSE(drama.approve_order(play, req));
}

TEST(MovieTest, MoviePriceNoDiscount) {
    using namespace std::chrono;
    ActionMovie m("Inception", test_time, 12.0);

    std::unordered_map<SeatType, int> seats = {
        {SeatType::Regular, 1},
        {SeatType::VIP, 2}
    };
    OrderRequest req = make_order("A", "B", 20, seats, {Extras::Popcorn});
    double price = 1*12.0*1.0 + 2*12.0*1.5 + 3;
    EXPECT_DOUBLE_EQ(m.calculate_price(req), 51.0);
}

TEST(TheatreTest, GetNameAndAddress) {
    MovieTheatre t("Big Theatre", "Main Street 1", 100, 14);
    EXPECT_EQ(t.get_name(), "Big Theatre");
    EXPECT_EQ(t.get_address(), "Main Street 1");
}

TEST(TheatreTest, GetSeats) {
    MovieTheatre t("Opera Hall", "456 Broadway", 200, 20);
    EXPECT_EQ(t.get_seats(SeatType::Regular), 200);
    EXPECT_EQ(t.get_seats(SeatType::VIP), 20);
}