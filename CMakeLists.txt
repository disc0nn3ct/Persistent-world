cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project(Persistent-world LANGUAGES CXX)

add_executable(${PROJECT_NAME} main.cpp gen.cpp gen.hpp)
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_20)
set_target_properties(${PROJECT_NAME} PROPERTIES CXX_EXTENSIONS OFF)

find_package(Boost 1.5 REQUIRED COMPONENTS serialization)
find_package(Catch2 REQUIRED)

target_link_libraries(${PROJECT_NAME} PRIVATE Boost::serialization Catch2::Catch2WithMain)

message( STATUS "Boost_LIBRARIES = ${Boost_LIBRARIES}")

