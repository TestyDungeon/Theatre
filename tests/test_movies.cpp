#include <gtest/gtest.h>
#include "../session/movie_theatre/horror_movie.h"
using namespace std::chrono;

TEST(MoviesTest, MovieSetCorrectly) {
    std::chrono::sys_seconds test_time = sys_days{year{2025}/6/19} + hours{19} + minutes{30};
    HorrorMovie m("Test Movie", test_time, 15.0);
    EXPECT_DOUBLE_EQ(m.get_cost(), 15.0);
    EXPECT_EQ(m.get_title(), "Test Movie");
    EXPECT_EQ(m.get_time(), test_time);
}