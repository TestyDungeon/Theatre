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
    tests/test_main.cpp
    tests/test_movies.cpp

    session/movie_theatre/movie.cpp
    session/movie_theatre/horror_movie.cpp
    session/session.cpp
    theatre/theatre.cpp
)

target_link_libraries(runTests
    gtest
    gtest_main
    pthread
)

add_test(NAME AllTests COMMAND runTests)