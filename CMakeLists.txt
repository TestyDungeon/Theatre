cmake_minimum_required(VERSION 3.10)

project(TheatreProject VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE Debug)

include_directories(
    ${PROJECT_SOURCE_DIR}/session
    ${PROJECT_SOURCE_DIR}/session/drama_theatre
    ${PROJECT_SOURCE_DIR}/session/movie_theatre
    ${PROJECT_SOURCE_DIR}/session/opera_theatre
    ${PROJECT_SOURCE_DIR}/theatre
    ${PROJECT_SOURCE_DIR}/order_request
)

file(GLOB_RECURSE PROJECT_SOURCES
    main.cpp
    console_ui.cpp
    session/*.cpp
    session/drama_theatre/*.cpp
    session/movie_theatre/*.cpp
    session/opera_theatre/*.cpp
    theatre/*.cpp
)

add_executable(TheatreProject ${PROJECT_SOURCES})

install(TARGETS TheatreProject
    RUNTIME DESTINATION bin
)

add_subdirectory(googletest)
enable_testing()

add_executable(runTests
    tests/test_orders.cpp

    session/movie_theatre/movie.cpp
    session/movie_theatre/horror_movie.cpp
    session/movie_theatre/action_movie.cpp
    session/movie_theatre/cartoon.cpp
    session/drama_theatre/play.cpp
    session/drama_theatre/tragedy_play.cpp
    session/drama_theatre/comedy_play.cpp
    session/opera_theatre/opera.cpp
    session/opera_theatre/choir.cpp
    session/opera_theatre/grand_opera.cpp
    session/session.cpp
    theatre/theatre.cpp
    theatre/drama_theatre.cpp
    theatre/opera_theatre.cpp
    theatre/movie_theatre.cpp
)

target_link_libraries(runTests
    gtest
    gtest_main
    pthread
)

add_test(NAME AllTests COMMAND runTests)