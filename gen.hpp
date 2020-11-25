//#pragma once // ?
#ifndef _gen_HPP
#define _gen_HPP
#include <string>
#include <iostream>

#include <random>
#include <vector>
#include <algorithm>
#include <cstring> // для memset

uint random(uint min, uint max);



class adventurer
{
public:
    void set_current_planet(unsigned int N);
    unsigned int get_current_planet();

    void set_current_id(unsigned int N);
    unsigned int get_current_id();
    adventurer();
private:

    unsigned int N_planet;
    unsigned int current_id_of_planet;
//    string Name;
};


class planet
{
public:
    planet();

    unsigned int get_number_of_portals();
    void set_number_of_planet(unsigned int N_planet);
    unsigned int get_number_of_planet();
    std::vector<std::pair<uint, uint>> const &get_vector_whereTo() const;
    void add_to_vector_pair_whereTo(std::pair<uint, uint> const &par);
    uint how_many_portals_are_fee();
    uint choose_free_portail_for_transport() ;
    static uint is_tp_on_planet(uint num ,std::vector<std::pair<uint, uint>>const &whereTO);   // если есть то вернет куда, если нет 0
    void print_whereTO_portals();

private:
    unsigned int N_planet; // номер планеты
    std::string planet_color;  // цвет планеты
    unsigned int N_of_portals; // кол-во порталов
    std::vector<std::pair<uint, uint>> whereTO;

};


uint is_planet_unique(uint num, std::vector<planet> &planet_game );  // вернет 0 если не существует и 1 если есть

void step(adventurer &player, std::vector<planet> &planet_game );

void step_to_portal(uint num_of_portal, adventurer &player, std::vector<planet> &planet_game );












#endif
