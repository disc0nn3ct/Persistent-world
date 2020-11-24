//#pragma once // ?
#ifndef _gen_HPP
#define _gen_HPP
#include <string>
#include <iostream>

#include <random>
#include <vector>
#include <algorithm>
#include <cstring> // для memset


class adventurer
{
public:
    void set_current_planet(unsigned int N);
    unsigned int get_current_planet();
    adventurer();
private:

    unsigned int N_planet;
//    string Name;
};


class planet
{
public:
    planet();
    uint random(uint min, uint max);

//    ~planet()
//    {
//        delete whereTO;
//    }

//    void set_whereTO_portal(unsigned int i, unsigned int where_to);
//    unsigned int get_whereTO_portal(unsigned int i);
    unsigned int get_number_of_portals();
    void set_number_of_planet(unsigned int N_planet);
    unsigned int get_number_of_planet();
    std::vector<std::pair<uint, uint>> const &get_vector_whereTo() const;


private:
    unsigned int N_planet; // номер планеты
    std::string planet_color;  // цвет планеты
    unsigned int N_of_portals; // кол-во порталов
    std::vector<std::pair<uint, uint>> whereTO;
};

void step(adventurer &player, std::vector<planet> &planet_game );














#endif
