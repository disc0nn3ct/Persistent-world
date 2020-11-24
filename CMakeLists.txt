cmake_minimum_required(VERSION 3.5)

project(Persistent-world LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Boost 1.55 REQUIRED system serialization)

add_executable(Persistent-world main.cpp gen.cpp gen.hpp)
target_link_libraries(Persistent-world ${Boost_LIBRARIES} )
