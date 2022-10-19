cmake_minimum_required(VERSION 3.23)
project(lab2)
set(CMAKE_CXX_STANDARD 20)

add_subdirectory(Google_test)
include_directories(Google_test/googlemock/include)
include_directories(Google_test/googletest/include)
add_executable(lab2 main.cpp cycloid.cpp cycloid.h dialog.cpp dialog.h handle.cpp test.cpp)
target_link_libraries(lab2 gtest gtest_main)